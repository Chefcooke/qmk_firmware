#include "analog_joystick.h"

void analog_joystick_init(void) {
    analog_joystickTimer       = 0;
    analog_joystickScrollTimer = 0;

    analog_joystick_state.config.mode           = ANALOG_JOYSTICK_MODE_MOUSE;
    analog_joystick_state.config.deadZone       = ANALOG_JOYSTICK_DEAD_ZONE;
    analog_joystick_state.config.fineZone       = ANALOG_JOYSTICK_FINE_ZONE;
    analog_joystick_state.config.speed          = ANALOG_JOYSTICK_SPEED;
    analog_joystick_state.config.fineSpeed      = ANALOG_JOYSTICK_FINE_SPEED;
    analog_joystick_state.config.axisSeparation = ANALOG_JOYSTICK_AXIS_SEPARATION;
    analog_joystick_state.config.eightAxis      = ANALOG_JOYSTICK_EIGHT_AXIS;

#if defined ANALOG_JOYSTICK_DEBUG
    rawX               = 0;
    rawY               = 0;
    distX              = 0;
    distY              = 0;
    analog_joystickLogTimer = 0;
#endif
}

// Axis-level wrapper to read raw value, do logging and calculate speed
int16_t analog_joystick_get_component(uint8_t pin) {
    uint16_t analogValue = analogReadPin(pin);
    // Compute direction
    bool directionIsPositive = (analogValue > ANALOG_JOYSTICK_RANGE_CENTER);
    // Compute distance from the center
    uint16_t distance = directionIsPositive ? (analogValue - ANALOG_JOYSTICK_RANGE_CENTER) : (ANALOG_JOYSTICK_RANGE_CENTER - analogValue);
#if defined ANALOG_JOYSTICK_DEBUG
    if (pin == ANALOG_JOYSTICK_PIN_X) {
        rawX  = analogValue;
        distX = distance;
    } else {
        rawY  = analogValue;
        distY = distance;
    }
#endif
    // Compute component (range of [0 to 1023])
    return directionIsPositive ? distance : -(int16_t)distance;
}

void analog_joystick_mode_set(analog_joystick_mode_t mode) { analog_joystick_state.config.mode = mode; }

analog_joystick_mode_t analog_joystick_mode_get(void) { return analog_joystick_state.config.mode; }

void analog_joystick_mode_cycle(bool reverse) {
    analog_joystick_mode_t mode = analog_joystick_mode_get();
    if (reverse) {
        mode = (mode == 0) ? (_ANALOG_JOYSTICK_MODE_LAST - 1) : (mode - 1);
    } else {
        mode = (mode == (_ANALOG_JOYSTICK_MODE_LAST - 1)) ? 0 : (mode + 1);
    }
    analog_joystick_mode_set(mode);
}

// Get mouse speed
int16_t analog_joystick_get_mouse_speed(int16_t component) {
    int16_t  maxSpeed;
    uint16_t distance = abs(component);
    if (distance > ANALOG_JOYSTICK_FINE_ZONE) {
        maxSpeed = ANALOG_JOYSTICK_SPEED;
    } else if (distance > ANALOG_JOYSTICK_DEAD_ZONE) {
        maxSpeed = ANALOG_JOYSTICK_FINE_SPEED;
    } else {
        return 0;
    }
    return (float)maxSpeed * component / ANALOG_JOYSTICK_RANGE_CENTER;
}

// Fix direction within one of 8 axes (or 4 if 8-axis is disabled)
analog_joystick_direction_t analog_joystick_get_discretized_direction(analog_joystick_vector_t vector, float axisSeparation, bool eightAxis) {
    analog_joystick_direction_t direction;
    uint16_t               absX                = abs(vector.x);
    uint16_t               absY                = abs(vector.y);
    uint16_t               maxComponent        = (absX > absY) ? absX : absY;
    bool                   insideDeadZone      = (maxComponent <= ANALOG_JOYSTICK_DEAD_ZONE);
    bool                   outsideDiagonalZone = ((abs(absX - absY) / (float)maxComponent) >= axisSeparation);
    if (insideDeadZone) {
        direction.up = direction.down = direction.left = direction.right = false;
    } else {
        direction.up    = (vector.y < 0);
        direction.down  = (vector.y > 0);
        direction.left  = (vector.x < 0);
        direction.right = (vector.x > 0);
        // Let only the dominant direction remain under the right conditions
        if (outsideDiagonalZone || !eightAxis) {
            if (absX > absY) {
                direction.up = direction.down = false;
            } else {
                direction.left = direction.right = false;
            }
        }
    }
    return direction;
}

analog_joystick_direction_t scrollDirection;  // Declaring global to save stack space
void                   analog_joystick_process(void) {
    if (timer_elapsed(analog_joystickTimer) > ANALOG_JOYSTICK_TIMEOUT) {
        analog_joystickTimer = timer_read();
#ifndef ANALOG_JOYSTICK_FLIP_X
        analog_joystick_state.vector.x = analog_joystick_get_component(ANALOG_JOYSTICK_PIN_X);
#else
        analog_joystick_state.vector.x = -analog_joystick_get_component(ANALOG_JOYSTICK_PIN_X);
#endif
#ifndef analog_joystick_FLIP_Y
        analog_joystick_state.vector.y = analog_joystick_get_component(ANALOG_JOYSTICK_PIN_Y);
#else
        analog_joystick_state.vector.y = -analog_joystick_get_component(ANALOG_JOYSTICK_PIN_Y);
#endif
        switch (analog_joystick_state.config.mode) {
            case ANALOG_JOYSTICK_MODE_MOUSE:
                analog_joystick_state.report.x = analog_joystick_get_mouse_speed(analog_joystick_state.vector.x);
                analog_joystick_state.report.y = analog_joystick_get_mouse_speed(analog_joystick_state.vector.y);
                break;
            case analog_joystick_MODE_ARROWS:
                analog_joystick_state.direction = analog_joystick_get_discretized_direction(analog_joystick_state.vector, analog_joystick_state.config.axisSeparation, analog_joystick_state.config.eightAxis);
                break;
            case ANALOG_JOYSTICK_MODE_SCROLL:
                if (timer_elapsed(analog_joystickScrollTimer) > ANALOG_JOYSTICK_SCROLL_TIMEOUT) {
                    analog_joystickScrollTimer     = timer_read();
                    scrollDirection           = analog_joystick_get_discretized_direction(analog_joystick_state.vector, analog_joystick_state.config.axisSeparation, false);
                    analog_joystick_state.report.v = (scrollDirection.up || scrollDirection.down) ? (scrollDirection.up ? ANALOG_JOYSTICK_SCROLL_SPEED : -ANALOG_JOYSTICK_SCROLL_SPEED) : 0;
                    analog_joystick_state.report.h = (scrollDirection.left || scrollDirection.right) ? (scrollDirection.left ? -ANALOG_JOYSTICK_SCROLL_SPEED : ANALOG_JOYSTICK_SCROLL_SPEED) : 0;
                } else {
                    analog_joystick_state.report.v = analog_joystick_state.report.h = 0;
                }
                break;
            default:
                break;
        }
    }
}

void update_keycode_status(uint16_t keycode, bool last, bool current) {
    if (last != current) {
        if (current) {
            register_code16(keycode);
        } else {
            unregister_code16(keycode);
        }
    }
}

void pointing_device_init(void) { analog_joystick_init(); }

void pointing_device_task(void) {
    report_mouse_t report = pointing_device_get_report();

    if (!isLeftHand) {
        analog_joystick_process();
        switch (analog_joystick_state.config.mode) {
            case ANALOG_JOYSTICK_MODE_MOUSE:
                report.x = analog_joystick_state.report.x;
                report.y = analog_joystick_state.report.y;
#ifdef ANALOG_JOYSTICK_DEBUG
                if (timer_elapsed(analog_joystickLogTimer) > 100) {
                    analog_joystickLogTimer = timer_read();
                    uprintf("Raw (%d, %d); Dist (%u, %u); Vec (%d, %d);\n", rawX, rawY, distX, distY, analog_joystick_state.vector.x, analog_joystick_state.vector.y);
                }
#endif
                break;
            case ANALOG_JOYSTICK_MODE_ARROWS:
                update_keycode_status(KC_UP, analog_joystick_state.lastDirection.up, analog_joystick_state.direction.up);
                update_keycode_status(KC_DOWN, analog_joystick_state.lastDirection.down, analog_joystick_state.direction.down);
                update_keycode_status(KC_LEFT, analog_joystick_state.lastDirection.left, analog_joystick_state.direction.left);
                update_keycode_status(KC_RIGHT, analog_joystick_state.lastDirection.right, analog_joystick_state.direction.right);
                analog_joystick_state.lastDirection = analog_joystick_state.direction;
#ifdef ANALOG_JOYSTICK_DEBUG
                if (timer_elapsed(analog_joystickLogTimer) > 100) {
                    analog_joystickLogTimer = timer_read();
                    uprintf("Up %d; Down %d; Left: %d; Right %d; Vec (%d, %d);\n", direction.up, direction.down, direction.left, direction.right, analog_joystick_state.vector.x, analog_joystick_state.vector.y);
                }
#endif
                break;
            case ANALOG_JOYSTICK_MODE_SCROLL:
                report.v = analog_joystick_state.report.v;
                report.h = analog_joystick_state.report.h;
#ifdef ANALOG_JOYSTICK_DEBUG
                if (timer_elapsed(analog_joystickLogTimer) > 100) {
                    analog_joystickLogTimer = timer_read();
                    uprintf("Scroll (%d, %d)\n", report.h, report.v);
                }
#endif
                break;
            default:
                break;
        }
    }

    pointing_device_set_report(report);
    pointing_device_send();
}