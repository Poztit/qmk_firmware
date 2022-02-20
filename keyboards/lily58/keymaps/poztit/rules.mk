BOOTLOADER = atmel-dfu

AUDIO_ENABLE       = no   # Audio output on port C6
BACKLIGHT_ENABLE   = no   # Enable keyboard backlight functionality
BLUETOOTH_ENABLE   = no   # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE   = no   # Virtual DIP switch configuration
COMMAND_ENABLE     = no   # Commands for debug and configuration
CONSOLE_ENABLE     = no   # Console for debug
MIDI_ENABLE        = no   # MIDI controls
MOUSEKEY_ENABLE    = no   # Mouse keys
RGBLIGHT_ENABLE    = no   # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE  = no   # Enable one-hand typing
UNICODE_ENABLE     = no   # Unicode

EXTRAKEY_ENABLE    = yes  # Audio control and System control
NKRO_ENABLE        = yes  # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
OLED_DRIVER_ENABLE = yes  # OLED display
WPM_ENABLE         = yes

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

#LTO_ENABLE = yes
SRC +=  ./lib/logo_reader.c
