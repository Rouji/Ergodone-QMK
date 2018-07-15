#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _______ KC_TRNS

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NMPD 2 // numpad and mouse

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  AUML,
  UUML,
  OUML,
  SZ
};

static bool SHIFTED = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | pscr   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | tab    |   Q  |   W  |   E  |   R  |   T  |  L2  |           | ~L2      Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | lshift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | rshift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |lctrl | lgui | lalt | ralt | ~L1  |                                       |  [   |  ]   |  -   |  =   | rctl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | caps | app  |       | ins  | rgui   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | end  |       | pgup |        |      |
 *                                 | space|enter |------|       |------|  del   |backsp|
 *                                 |      |      | home |       | pgdn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
    KC_GRV,         KC_1,         KC_2,      KC_3,      KC_4,      KC_5,   _______,
    KC_TAB,         KC_Q,         KC_W,      KC_E,      KC_R,      KC_T,   TG(NMPD),
    KC_ESC,         KC_A,         KC_S,      KC_D,      KC_F,      KC_G,
    KC_LSFT,        KC_Z,         KC_X,      KC_C,      KC_V,      KC_B,   _______,
    KC_LCTL,        KC_LGUI,      KC_LALT,   KC_RALT,   MO(SYMB),

                                             KC_CAPS,   KC_APP,
                                                                   KC_END,
                                             KC_SPC,    KC_ENT,    KC_HOME,
        // right hand
     _______,   KC_6,    KC_7,      KC_8,      KC_9,      KC_0,             KC_PSCR,
     MO(NMPD),  KC_Y,    KC_U,      KC_I,      KC_O,      KC_P,             KC_BSLS,
                KC_H,    KC_J,      KC_K,      KC_L,      KC_SCLN,          KC_QUOT,
     _______,   KC_N,    KC_M,      KC_COMM,   KC_DOT,    CTL_T(KC_SLSH),   KC_RSFT,
                         KC_LBRC,   KC_RBRC,   KC_MINS,   KC_EQL,           KC_RCTL,

     KC_INS,    KC_RGUI,
     KC_PGUP,
     KC_PGDN,   KC_DEL,  KC_BSPC
    ),
/*
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | version |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |      |  ü   |      |  ö   |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   ä  |   ß  |   (  |   )  |   `  |------|           |------| left | down |  up  | right|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
   // left hand (symbols)
   VRSN,      KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F11,
   _______,   KC_EXLM,   KC_AT,     KC_LCBR,   KC_RCBR,   KC_PIPE,   _______,
   _______,   AUML,      SZ,        KC_LPRN,   KC_RPRN,   KC_GRV,
   _______,   KC_PERC,   KC_CIRC,   KC_LBRC,   KC_RBRC,   KC_TILD,   _______,
   _______,   _______,   _______,   _______,   _______,
                                               _______,   _______,
                                                          _______,
                                    _______,   _______,   _______,
   // right hand (vim movements)
   KC_F12,    KC_F6,     KC_F7,     KC_F8,     KC_F9,      KC_F10,    _______,
   _______,   _______,   UUML,      _______,   OUML,    _______,   _______,
              KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,   _______,   _______,
   _______,   _______,   _______,   _______,   _______,    _______,   _______,
                         _______,   _______,   _______,    _______,   _______,
   _______,   _______,
   _______,  
   _______,   _______,   _______
),
/*
 * ,--------------------------------------------------.             ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |             |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|             |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |             |      |      |   7  |   8  |   9  |   /  |        |
 * |--------+------+------+------+------+------|      |             |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|             |------|      |   4  |   5  |   6  |   *  |        |
 * |--------+------+------+------+------+------|      |             |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |             |      |      |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+-------------'             `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                         |   0  |   0  |   .  |   +  | enter|
 *   `----------------------------------'                                         `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | lclk | rclk |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 * 
 */
[NMPD] = LAYOUT_ergodox(
    // left hand (mouse)
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_MS_U, _______, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______, KC_ENT,
    _______, _______, _______, _______, _______,
                                       _______, _______,
                                                _______,
                              KC_BTN1, KC_BTN2, _______,
    // right hand (keypad)
    _______, _______, _______, _______,_______, _______, _______,
    _______, _______, KC_7,    KC_8,   KC_9,    KC_BSLS, _______,
            _______, KC_4,    KC_5,   KC_6,    KC_ASTR, _______,
    _______, _______, KC_1,    KC_2,   KC_3,    KC_MINS, _______,
                     KC_0,    KC_0,   KC_DOT,  KC_PLUS, _______,
    _______, _______,
    _______,
    _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_LSFT || keycode == KC_RSFT)
    {
        SHIFTED = record->event.pressed;
    }

    if (record->event.pressed)
    {
        switch (keycode)
        {
            // dynamically generate these.
            case EPRM:
                eeconfig_init();
                return false;
            case VRSN:
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case AUML:
                if (SHIFTED)
                    SEND_STRING (SS_TAP(X_RALT) "\"A");
                else
                    SEND_STRING (SS_TAP(X_RALT) "\"a");
                return false;
            case UUML:
                if (SHIFTED)
                    SEND_STRING (SS_TAP(X_RALT) "\"U");
                else
                    SEND_STRING (SS_TAP(X_RALT) "\"u");
                return false;
            case OUML:
                if (SHIFTED)
                    SEND_STRING (SS_TAP(X_RALT) "\"O");
                else
                    SEND_STRING (SS_TAP(X_RALT) "\"o");
                return false;
            case SZ:
                SEND_STRING (SS_TAP(X_RALT) "ss");
                return false;
        }
    }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    switch (layer) {
        case 1:
            break;
        case 2:
            ergodox_board_led_on();
            break;
        case 3:
            break;
        default:
            // none
            break;
    }

};
