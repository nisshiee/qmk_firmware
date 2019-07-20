// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_jp.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,-------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7   |   8  |   9  |   0  |   -  |
 * |--------+------+------+------+------+-------------|           |------+------+-------+------+------+------+------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Opt+Z|           |Sft+En|   Y  |   U   |   I  |   O  |   P  |   @  |
 * |--------+------+------+------+------+------|      |           |      |------+-------+------+------+------+------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J   |   K  |   L  |   ;  |   :  |
 * |--------+------+------+------+------+------| Space|           | Enter|------+-------+------+------+------+------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M   |   ,  |   .  |   /  |   _  |
 * `--------+------+------+------+------+-------------'           `-------------+-------+------+------+------+------'
 *   |  BS  |  Del |AltShf|LShift| 英数 |                                       |かな/L2|   [  |   ]  |   ^  | ¥   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | LSft | Tab  |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       |  Up  |        |      |
 *                                 |Space/|Option|------|       |------| LShift |Enter/|
 *                                 |Ctrl  |      | Cmd  |       | Down |        |Cmd   |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,    KC_1,    KC_2,   KC_3,   KC_4,     KC_5,   KC_LEFT,
        KC_TAB,    KC_Q,    KC_W,   KC_E,   KC_R,     KC_T,   LALT(KC_Z),
        KC_LCTRL,  KC_A,    KC_S,   KC_D,   KC_F,     KC_G,
        KC_LSFT,   KC_Z,    KC_X,   KC_C,   KC_V,     KC_B,   KC_SPC,
        KC_BSPACE, KC_DEL,  LALT(KC_LSFT),  KC_LSHIFT,LT(SYMB, JP_MEISU),
                                              KC_LSHIFT,  KC_TAB,
                                                              KC_HOME,
                                        CTL_T(KC_SPC),KC_LALT,KC_LCMD,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             LSFT(KC_ENT),       KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             JP_AT,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,           JP_COLN,
             KC_ENTER,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   JP_UNDS,
                                  LT(MDIA, JP_MKANA),  JP_LBRC,JP_RBRC,JP_CIRC,JP_YEN,
             KC_LEFT,        KC_RIGHT,
             KC_UP,
             KC_DOWN,KC_LSFT,LCMD_T(KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   "  |   {  |   }  |   |  |      |           |      |   "  |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|   =  |   4  |   5  |   6  |   +  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   &  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   -  |   ¥    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   '  |   <  |   >  |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,JP_EXLM,JP_DQT,  JP_LCBR,JP_RCBR,JP_PIPE,KC_TRNS,
       KC_TRNS,JP_HASH,JP_DLR, JP_LPRN,JP_RPRN,JP_GRV,
       KC_TRNS,JP_PERC,JP_AMPR,JP_LBRC,JP_RBRC,JP_TILD,KC_TRNS,
       KC_TRNS,JP_QUOT,JP_LT,  JP_GT  ,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_DQT,  KC_7,   KC_8,    KC_9,    JP_ASTR, KC_F12,
                JP_EQL,  KC_4,   KC_5,    KC_6,    JP_PLUS, JP_SLSH,
       KC_TRNS, JP_AMPR, KC_1,   KC_2,    KC_3,    JP_MINS, JP_YEN,
                         KC_TRNS,JP_DOT,  KC_0,    JP_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | Reset  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |  W_L | W_UP |  W_R |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  Up  |MsLeft|MsDown|MsRght|      |------|           |------|      | Lclk |W_DOWN| Rclk |  Up  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Left  | Down |Right |Option|  Cmd |      |      |           |      |      |      |      | Left | Down | Right  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,  KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_UP,   KC_MS_L,  KC_MS_D, KC_MS_R, KC_TRNS,
       KC_LEFT, KC_DOWN, KC_RIGHT, KC_LALT, KC_LCMD, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,  KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
       KC_TRNS,  KC_TRNS, KC_WH_L, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_BTN1, KC_WH_D, KC_BTN2, KC_UP,   KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_BTN3, KC_LEFT, KC_DOWN, KC_RIGHT,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
