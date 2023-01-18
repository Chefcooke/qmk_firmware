OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = no       # ENables the use of one or more encoders
RGBLIGHT_ENABLE = no     # Enable keyboard RGB underglow about 10% of memory

# LTO: Link Time Optimizations.
# Reduce compiled size, but will automatically disable the legacy TMK Macros and Functions features.
# This does not affect QMK Macros and Layers
LTO_ENABLE = yes
ENCODER_MAP_ENABLE = no
POINTING_DEVICE_ENABLE = no
TAP_DANCE_ENABLE = no
LEADER_ENABLE = no
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = yes #Auto Shift is 10% of mcu memory

KEY_LOCK_ENABLE = no
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
VELOCIKEY_ENABLE = no
STENO_ENABLE = no
TERMINAL_ENABLE = no
GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no