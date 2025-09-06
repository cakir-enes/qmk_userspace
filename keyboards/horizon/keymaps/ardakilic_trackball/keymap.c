/* Copyright 2022 Arda Kilicdagi
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


enum custom_keycodes {
  BALL_SCR = SAFE_RANGE, //scrolls
  BALL_NCL,              //left click
  BALL_RCL,              //right click
  BALL_MCL,              //middle click
};

enum horizon_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SPACE,
  _SODA,
  _NUMPAD
};


// KC_NONUS_BACKSLASH (\|) is equivalent to ["é] key in Turkish keyboards.
// KC_GRV (~ `) is equivalent to [<>|] key in Turkish keyboards.
// KC_SCLN is Turkish s [şŞ] key
// KC_QUOT is Turkish i [iİ] key
// KC_COMM is Turkish o [öÖ] key
// KC_DOT is Turkish c [çÇ] key

// Custom shortcuts specific to Turkish layout
#define CURLY_OPEN RALT(KC_7)
#define CURLY_CLOSE RALT(KC_0)
#define SQUARE_OPEN RALT(KC_8)
#define SQUARE_CLOSE RALT(KC_9)
#define DOLLAR_SIGN RALT(KC_4)
#define BACKSLASH RALT(KC_MINS)
#define VERTICAL_PIPE RALT(KC_EQL)
#define BACKTICK RALT(KC_BSLS)
#define TILDE RALT(KC_RBRC)
#define HASHTAG RALT(KC_3)
#define LOCKSCREEN LCTL(LSFT(KC_PWR)) // Screen Lock shortcut for OSX

/*
// Unicode Turkish characters, in case it's needed
enum {
    TR_C, // ç
    TR_C_L, // Ç
    TR_I, // ı
    TR_I_L, // İ
    TR_G, // ğ
    TR_G_L, // Ğ
    TR_S, // ş
    TR_S_L, // Ş
    TR_U, // ü
    TR_U_L, // Ü
    TR_O, // ö
    TR_O_L, // Ö
};

// clang-format off
const uint32_t PROGMEM unicode_map[] = {
    [TR_C] = 0x00c7,
    [TR_C_L] = 0x00e7,
    [TR_I] = 0x0130,
    [TR_I_L] = 0x0131,
    [TR_G] = 0x011e,
    [TR_G_L] = 0x011f,
    [TR_S] = 0x015e,
    [TR_S_L] = 0x015f,
    [TR_U] = 0x00dc,
    [TR_U_L] = 0x00fc,
    [TR_O] = 0x00d6,
    [TR_O_L] = 0x00f6,
};
// clang-format on
*/


/*
// Smooth mouse scroll movement START
// https://github.com/qmk/qmk_firmware/blob/master/keyboards/sofle/keymaps/foureight84/keymap.c
static uint32_t       last_mouse_activity = 0;
static report_mouse_t last_mouse_report   = {0};
static bool           is_scrolling        = false;

report_mouse_t smooth_mouse_movement(report_mouse_t mouse_report) {
    // Linear interpolation and ease-in-out
    static fract8 fract = 0.5;
    int8_t        x     = 0;
    int8_t        y     = 0;
    int8_t        h     = 0;
    int8_t        v     = 0;

    if (!is_scrolling) {
        x = ease8InOutApprox(lerp8by8(last_mouse_report.x, mouse_report.x, fract));
        y = ease8InOutApprox(lerp8by8(last_mouse_report.y, mouse_report.y, fract));
    } else {
        h = ease8InOutApprox(lerp8by8(last_mouse_report.x, mouse_report.x, fract));
        v = ease8InOutApprox(lerp8by8(last_mouse_report.y, mouse_report.y, fract));
    }

    // update the new smoothed report
    mouse_report.x = x;
    mouse_report.y = y;
    mouse_report.h = h;
    mouse_report.v = v;

    return mouse_report;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    if (has_mouse_report_changed(&last_mouse_report, &mouse_report)) {
        last_mouse_activity = timer_read32();
        memcpy(&last_mouse_report, &mouse_report, sizeof(mouse_report));
    }

    return smooth_mouse_movement(mouse_report);
}
// Smooth mousescroll  movement END
*/

bool set_scrolling = false;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
  switch (keycode){
      case BALL_SCR:
       if(record->event.pressed) {
            set_scrolling = !set_scrolling;
        }
       break;
   }
/*
  case BALL_NCL:
     record->event.pressed?register_code(KC_BTN1):unregister_code(KC_BTN1);
     break;
  case BALL_RCL:
      record->event.pressed?register_code(KC_BTN2):unregister_code(KC_BTN2);
      break;
  case BALL_MCL:
      record->event.pressed?register_code(KC_BTN3):unregister_code(KC_BTN3);
      break;
  }
  */
  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------------------------------------------------------------------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |    TRACK    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|     BALL    |------+------+------+------+------+------|
 * |NPdEsc|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   Ş  |   İ  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |SftCps|   Z  |   X  |   C  |   V  |   B  |LftClk|LftClk|   N  |   M  |   Ö  |   Ç  |   .  |SftEtr|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |Sda|<>| Ctrl | Alt  |  OS  |Lowr|,|Space*|Scroll|RgtClk| Bksp |Rise|"| Left | Down |  Up  |Right |
 * `-------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
        KC_TAB,            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SQUARE_OPEN,
        KC_CAPS,           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MS_BTN1, KC_MS_BTN1,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT /*KC_ENT*/,
        LT(_SODA, KC_GRV), KC_F19, KC_LCTL, KC_LALT,    KC_LGUI,  KC_SPC,  KC_SCRL,    KC_MS_BTN2,    KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

/* Lower
 * ,-------------------------------------------------------------------------------------------------.
 * |   >  |   !  |   '  |   ^  |   +  |   %  |    TRACK    |   &  |   /  |   (  |   )  |   =  | Bksp |
 * |------+------+------+------+------+------+     BALL    |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   ?  |   _  |  Ğ   |  Ü   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |LftClk|LftClk|  F12 |  "$" |  "{" |  "}" |  <   |  ">" |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Scroll|RgtClk|      |      |  "[" |  "]" |  '   |   "  |
 * `-------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LBRC, KC_RBRC, KC_EQL,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_MS_BTN1, KC_MS_BTN1,  KC_F12,  DOLLAR_SIGN, CURLY_OPEN, CURLY_CLOSE, KC_GRV, LSFT(KC_GRV),
    _______, _______, _______, _______, _______, _______, BALL_SCR, KC_MS_BTN2, _______, _______,   SQUARE_OPEN, SQUARE_CLOSE, LSFT(KC_2), KC_NONUS_BACKSLASH
),


/* Raise
 * ,-------------------------------------------------------------------------------------------------.
 * |  <>| |   1  |   2  |   3  |   4  |   5  |    TRACK    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+     BALL    |------+------+------+------+------+------|
 * |  Del |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   *  |   -  | "\"  | "|"  |  ,   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |LftClk|LftClk|  F12 |   #  |   "  | "~"  | "`"  |  <>| |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Scroll|RgtClk|      |      | Next | Vol- | Vol+ | Play |
 * `-------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  BACKSLASH, VERTICAL_PIPE, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_MS_BTN1, KC_MS_BTN1,  KC_F12,  HASHTAG, KC_NUBS, TILDE, BACKTICK, KC_GRV,
    _______, _______, _______, _______, _______, _______, BALL_SCR, KC_MS_BTN2,_______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Soda Layer. Adjust and other stuff
 * ,-------------------------------------------------------------------------------------------------.
 * |EepRST|BOTLDR| Debug|Reboot|      |      |    TRACK    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------+     BALL    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      | Left | Down |Right |      | Mute |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |LftClk|LftClk|      |      | Next | Vol- | Vol+ | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Scroll|RgtClk|      |      |      |      |Brght▼|Brght▲|
 * `-------------------------------------------------------------------------------------------------'
 */
[_SODA] = LAYOUT(
    QK_CLEAR_EEPROM,  QK_BOOT,  DB_TOGG, QK_RBT, _______, _______, _______, _______, KC_UP, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_MUTE,
    _______, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN1, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______, _______, BALL_SCR, KC_MS_BTN2, _______, _______, _______, _______, KC_BRMD, KC_BRMU
),

/* Space Layer (Space Bar Layer Tap)
 * ,-------------------------------------------------------------------------------------------------.
 * |      |CMD+1 |CMD+2 |CMD+3 |CMD+4 |CMD+5 |    TRACK    |CMD+6 |CMD+7 |CMD+8 |CMD+9 |CMD+0 |LCKOSX|
 * |------+------+------+------+------+------+     BALL    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |  Up  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |LftClk|LftClk|      |      | Left | Down |Right |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Scroll|RgtClk|      |      |      |      |Brght▼|Brght▲|
 * `-------------------------------------------------------------------------------------------------'
 */
[_SPACE] = LAYOUT(
    _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8),  LGUI(KC_9), LGUI(KC_0), LOCKSCREEN,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,  _______, _______,
    _______, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN1, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, BALL_SCR, KC_MS_BTN2, _______, _______, _______, _______, KC_BRMD, KC_BRMU
),


/* Numpad Layer
 * KC_PDOT is comma on the Turkish layout ¯\_(ツ)_/¯
 * ,-------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |    TRACK    | Space|   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+------+     BALL    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             | Enter|   4  |   5  |   6  |   +  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |LftClk|LftClk| Enter|   1  |   2  |   3  |   +  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Scroll|RgtClk| Bkspc|   0  |   0  |   .  |   ,  |   =  |
 * `-------------------------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT(
    _______, _______, _______, _______, _______, _______, KC_SPC, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_BSPC,
    _______, _______, _______, _______, _______, _______, KC_PENT, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST,
    _______, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN1, KC_PENT, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_PSLS,
    _______, _______, _______, _______, _______, _______, BALL_SCR, KC_MS_BTN2, KC_BSPC,  KC_P0, KC_P0, KC_SLSH, KC_PDOT, KC_PEQL
),

};
