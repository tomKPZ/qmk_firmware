# Link time optimization
LTO_ENABLE = yes

# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Virtual DIP switch configuration
BOOTMAGIC_ENABLE = no

# Audio control and System control
EXTRAKEY_ENABLE = no

# Console for debug
CONSOLE_ENABLE = no

# Commands for debug and configuration
COMMAND_ENABLE = no

# Breathing sleep LED during USB suspend
SLEEP_LED_ENABLE = no

# USB N-Key Rollover
NKRO_ENABLE = yes

# Enable keyboard backlight functionality
BACKLIGHT_ENABLE = no

# Enable keyboard RGB underglow
RGBLIGHT_ENABLE = no

# Enable Bluetooth
BLUETOOTH_ENABLE = no
# Current options are AdafruitBLE, RN42
# BLUETOOTH =

# Audio output
AUDIO_ENABLE = no

# Enable the key override feature
KEY_OVERRIDE_ENABLE = no

# Enable keyboard underlight functionality
RGBLIGHT_ENABLE = no

# Enable leader key chording
LEADER_ENABLE = no

# MIDI controls
MIDI_ENABLE = no

# Unicode
UNICODE_ENABLE = no

# Enables split keyboard support
SPLIT_KEYBOARD = yes

# Allows replacing the standard matrix scanning routine with a custom one.
CUSTOM_MATRIX = no

# Allows replacing the standard key debouncing routine with an alternative or custom one.
DEBOUNCE_TYPE = no

# Forces the keyboard to wait for a USB connection to be established before it starts up
WAIT_FOR_USB = no

# Disables usb suspend check after keyboard startup. Usually the keyboard waits for the host to wake it up before any tasks are performed. This is useful for split keyboards as one half will not get a wakeup call but must send commands to the master.
NO_USB_STARTUP_CHECK = yes

DYNAMIC_MACRO_ENABLE = no

# Mouse support
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3389
MOUSEKEY_ENABLE = yes

# Per-key debouncing.  State changes are immediate.
DEBOUNCE_TYPE = sym_eager_pk

SRC += repeat.c
