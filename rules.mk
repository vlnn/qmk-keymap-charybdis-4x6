SRC += source.c
MCU_FAMILY = NRF52
MCU  = cortex-m4
ARMV = 7

# BOOTMAGIC_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
LTO_ENABLE = yes
LAYOUTS = split_3x5_3
