/* Copyright 2019 Biacco42
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define MACRO_A1A_SNAKE  0
#define MACRO_A1A_PASCAL 1
#define MACRO_RFQ_SNAKE  2
#define MACRO_RFQ_PASCAL 3

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
    case MACRO_A1A_SNAKE:
        if (record->event.pressed) {
            SEND_STRING("a1a");
        }
        break;
    case MACRO_A1A_PASCAL:
        if (record->event.pressed) {
            SEND_STRING("A1A");
        }
        break;
    case MACRO_RFQ_SNAKE:
        if (record->event.pressed) {
            SEND_STRING("request_for_quotation");
        }
        break;
    case MACRO_RFQ_PASCAL:
        if (record->event.pressed) {
            SEND_STRING("RequestForQuotation");
        }
        break;
    }
    return MACRO_NONE;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    M(MACRO_A1A_SNAKE), M(MACRO_A1A_PASCAL), M(MACRO_RFQ_SNAKE), M(MACRO_RFQ_PASCAL) \
  )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
