OLED_ENABLE  = yes
EXTRAKEY_ENABLE = yes # for media keys

# bongo cat
WPM_ENABLE = yes
# bongo cat

# Size optimisations
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESCAPE_ENABLE = no
MOUSEKEY_ENABLE = no
# Size optimisations END

# Select the Bootloader
# https://github.com/qmk/qmk_firmware/blob/master/platforms/chibios/converters/elite_c_to_rp2040_ce/converter.mk
# https://github.com/qmk/qmk_firmware/blob/master/platforms/chibios/converters/promicro_to_rp2040_ce/converter.mk
CONVERT_TO = elite_pi