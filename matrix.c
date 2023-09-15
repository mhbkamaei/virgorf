#include "quantum.h"
#include "matrix.h"
#include "uart.h"

#define PER_KEY_LED_TIMEOUT_MS  50      // LED on time per key timeout in milliseconds.
#define AT_BOOT_LED_TIMEOUT_MS  1000    // LED on time at boot timeout in milliseconds.

#define UART_BAUDRATE                   1000000
#define UART_MATRIX_RESPONSE_TIMEOUT    10000

// the Deferred executor callbacks to turn LED off without causeing any latancy.
static uint32_t blink_callback(uint32_t trigger_time, void* cb_arg) {

  writePinHigh(C13); // Turn LED off.

  return 0;
}

void matrix_init_custom(void) {
    uart_init(UART_BAUDRATE);
    setPinOutput(C13);
    writePinLow(C13); // Turn LED on.
    defer_exec(AT_BOOT_LED_TIMEOUT_MS, blink_callback, NULL);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    uint32_t timeout = 0;
    bool     changed = false;

    // the s character requests the RF slave to send the matrix
    uart_write('s');

    // trust the external keystates entirely, erase the last data
    uint8_t uart_data[9] = {0};

    // there are 10 bytes corresponding to 10 columns, and then an end byte
    for (uint8_t i = 0; i < 9; i++) {
        // wait for the serial data, timeout if it's been too long
        // this only happened in testing with a loose wire, but does no
        // harm to leave it in here
        while (!uart_available()) {
            timeout++;
            if (timeout > UART_MATRIX_RESPONSE_TIMEOUT) {
                break;
            }
        }

        if (timeout < UART_MATRIX_RESPONSE_TIMEOUT) {
            uart_data[i] = uart_read();
        } else {
            uart_data[i] = 0x00;
        }
    }

    // check for the end packet, the key state bytes use the LSBs, so 0xE0
    // will only show up here if the correct bytes were recieved
    if (uart_data[8] == 0xE0) {
        // shifting and transferring the keystates to the QMK matrix variable
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            matrix_row_t current_row = (uint16_t)uart_data[i * 2] | (uint16_t)uart_data[i * 2 + 1] << 5;
            if (current_matrix[i] != current_row) {
                changed = true;
            }
            current_matrix[i] = current_row;
        }
    }
    return changed;
}