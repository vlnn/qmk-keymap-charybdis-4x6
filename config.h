#pragma once

/* Key matrix configuration. */

#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS \
    { F4, F5, F6, F7, B5 }
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS \
    { D1, D4, C6, D7, E6, B4 }

#undef DIODE_DIRECTION
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed. */
#define DEBOUNCE 5

/* Trackball angle adjustment. */
#define ROTATIONAL_TRANSFORM_ANGLE -25



/* Handedness. */
#define MASTER_RIGHT
#define SPLIT_USB_DETECT

/* serial.c configuration (for split keyboard). */
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2

/* RGB settings. */
/* #define RGB_DI_PIN D3 */

/* PMW3360 settings. */
#define POINTING_DEVICE_DEBUG
#define CHARYBDIS_CONFIG_SYNC

#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT


#undef PMW33XX_CS_PIN
#define PMW33XX_CS_PIN B6
#define PMW3360_CPI 400............

#define BOOTMAGIC_LITE_ROW 5
#define BOOTMAGIC_LITE_COLUMN 0
