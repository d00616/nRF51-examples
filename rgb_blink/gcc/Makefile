TARGET_CHIP := NRF51822_QFAA_CA
BOARD := BOARD_PCA10000

C_SOURCE_FILES += main.c
C_SOURCE_FILES += nrf_delay.c

OUTPUT_FILENAME := rgb_blink
SDK_PATH = $(HOME)/Projects/nRF51SDK/Nordic/nrf51822/

#Uncomment correct line if you have softdevice programmed on the chip.
DEVICE_VARIANT := xxaa
#DEVICE_VARIANT := xxab

#USE_SOFTDEVICE := S110
#USE_SOFTDEVICE := S210

include $(SDK_PATH)Source/templates/gcc/Makefile.common
