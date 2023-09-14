#pragma once

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10
//#define LED_CAPS_LOCK_PIN C13
#define AUDIO_PIN A8
#define AUDIO_PWM_DRIVER PWMD1
#define AUDIO_PWM_CHANNEL 1
#define AUDIO_PWM_PAL_MODE 1
#define AUDIO_ENABLE_TONE_MULTIPLEXING
#define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10

#define STARTUP_SONG SONG(STARTUP_SOUND)

#define VIAL_KEYBOARD_UID {0x14, 0xC3, 0x23, 0xD7, 0x8A, 0x9E, 0xD1, 0xA6}

#define SERIAL_USART_FULL_DUPLEX      // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN A9        // USART TX pin
#define SERIAL_USART_RX_PIN A10       // USART RX pin
#define SERIAL_USART_TX_PAL_MODE 7    // Pin "alternate function", default: 7
#define SERIAL_USART_RX_PAL_MODE 7    // Pin "alternate function", default: 7
#define SERIAL_USART_DRIVER SD1       // Select serial driver 1.

#define DYNAMIC_KEYMAP_LAYER_COUNT  7
#define VIAL_COMBO_ENABLE
#define VIAL_COMBO_ENTRIES          8
#define VIAL_TAP_DANCE_ENTRIES      8
#define DYNAMIC_KEYMAP_MACRO_COUNT  8

//#define VIAL_UNLOCK_COMBO_ROWS { 2, 2 }
//#define VIAL_UNLOCK_COMBO_COLS { 0, 9 }


// #define IGNORE_MOD_TAP_INTERRUPT   it is now the default behavior
#define TAPPING_TERM 200
#define RETRO_TAPPING
#define PERMISSIVE_HOLD
#define ONESHOT_TIMEOUT 555

#define FORCE_NKRO

#define LEADER_TIMEOUT 750 // 0.75 second.

#define TAP_CODE_DELAY 10

#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 2000 // 2 seconds.
