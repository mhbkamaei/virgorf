#pragma once

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

#define VIAL_KEYBOARD_UID {0x14, 0xC3, 0x23, 0xD7, 0x8A, 0x9E, 0xD1, 0xA6}

#define SERIAL_USART_FULL_DUPLEX      // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN A9        // USART TX pin
#define SERIAL_USART_RX_PIN A10       // USART RX pin
#define SERIAL_USART_TX_PAL_MODE 7    // Pin "alternate function", default: 7
#define SERIAL_USART_RX_PAL_MODE 7    // Pin "alternate function", default: 7
#define SERIAL_USART_DRIVER SD1       // Select serial driver 1.

#define DYNAMIC_KEYMAP_LAYER_COUNT 7
#define VIAL_COMBO_ENTRIES 8
#define VIAL_TAP_DANCE_ENTRIES 8
#define DYNAMIC_KEYMAP_MACRO_COUNT 8

#define VIAL_UNLOCK_COMBO_ROWS { 2, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 9 }

// #define IGNORE_MOD_TAP_INTERRUPT   it is now the default behavior
#define TAPPING_TERM 222
#define ONESHOT_TIMEOUT 500