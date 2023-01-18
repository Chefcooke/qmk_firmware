OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = no       # ENables the use of one or more encoders
RGBLIGHT_ENABLE = no     # Enable keyboard RGB underglow

# LTO: Link Time Optimizations.
# Reduce compiled size, but will automatically disable the legacy TMK Macros and Functions features.
# This does not affect QMK Macros and Layers
LTO_ENABLE = yes
ENCODER_MAP_ENABLE = no
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = analog_joystick
TAP_DANCE_ENABLE = no
LEADER_ENABLE = no
# SRC += analog_joystick.c


