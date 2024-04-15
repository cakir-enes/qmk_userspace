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


#include "ardakilic.h"

enum keyboard_layers {
  _QWERTY,
  _LOWER,
  // _RAISE,
  _ADJUST,
  // _SPACE,
  // _SODA,
  _NUMPAD,
  _MAC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  "   |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   | BkSp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   | Del  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |NpdEsc|  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   |  Ş   |  İ   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | LSFT |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   |  Ö   |  Ç   |  .   |SftEnt|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | Ctrl |Adj|<>| Win  | Alt  |Lowr|,|Space | |Space | AltGR| Left | Down |  Up  | Rght |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
    KC_GRV,KC_1,KC_2,KC_3,KC_4,KC_5,                    /*|*/   KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPC,
    KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,                    /*|*/   KC_Y,KC_U,KC_I,KC_O,KC_P,KC_DEL,
    LT(_NUMPAD, KC_ESC),KC_A,KC_S,KC_D,KC_F,KC_G,       /*|*/   KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,
    KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,           /*|*/   KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,SC_SENT,
    KC_LCTL,LT(_ADJUST,KC_NONUS_BACKSLASH),KC_LGUI,KC_LALT,LT(_LOWER,KC_BSLS),KC_SPC, /*|*/ KC_SPC,KC_RALT,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT
),


/* Lower
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |      |      |  "\" |  "|" |  *   |  -   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  | F10  | |      |   #  |   "  |  "¨" | "~"  |  "=" |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      | |  *   |   ?  |  "`" |  Ğ   |  Ü   |  _   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      | "$"  |  "{" |  "}" |  <   |  ">" |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      | Entr | | BkSp |      |  "[" |  "]" |  '   |  "   |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
    _______,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,              /*|*/   _______,_______,BACKSLASH,VERTICAL_PIPE,KC_MINS,KC_EQL,
    _______,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,             /*|*/   _______,HASHTAG,KC_GRV,RALT(KC_LBRC),RALT(KC_RBRC),LSFT(KC_0),
    _______,KC_F11,KC_F12,_______,_______,_______,      /*|*/   KC_MINS,KC_UNDS,BACKTICK,KC_LBRC,KC_RBRC,KC_PLUS,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,DOLLAR_SIGN,CURLY_OPEN,CURLY_CLOSE,KC_NONUS_BACKSLASH,RALT(KC_1),
    _______,_______,_______,_______,_______,KC_ENT,     /*|*/   KC_BSPC,_______,SQUARE_OPEN,SQUARE_CLOSE,LSFT(KC_2),KC_GRV
),


/* Numpad & Mouse
 * KC_PDOT is comma on the Turkish layout ¯\_(ツ)_/¯
 * ,-----------------------------------------. ,-----------------------------------------.
 * | ACL0 | ACL1 | ACL2 |M-clic|      |      | |      | NLCK |   /  |   *  |   -  | Bksp |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |L-clck|  Up  |R-clck|Scrl U| |      |   7  |   8  |   9  |   +  |  =   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |==XX==|      | Left | Down |Right |Scrl D| |      |   4  |   5  |   6  |   +  |  ,   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | VOLU |      | PREV |PAUSE | NEXT | |      |   1  |   2  |   3  |Enter |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | VOLD |      | MUTE | Bksp | Del  | |Enter |Space |   0  |   .  |Enter |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_5x12(
    KC_ACL0,KC_ACL1,KC_ACL2,KC_BTN3,_______,_______,    /*|*/   _______,KC_NUM,KC_PSLS,KC_PAST,KC_PMNS,KC_BSPC,
    _______,_______,KC_BTN1,KC_MS_U,KC_BTN2,KC_WH_U,    /*|*/   _______,KC_P7,KC_P8,KC_P9,KC_PPLS,KC_PEQL,
    _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,    /*|*/   _______,KC_P4,KC_P5,KC_P6,KC_PPLS,KC_PDOT,
    _______,KC_VOLU,_______,KC_MPRV,KC_MPLY,KC_MNXT,    /*|*/   _______,KC_P1,KC_P2,KC_P3,KC_PENT,_______,
    _______,KC_VOLD,_______,KC_MUTE,KC_BSPC,KC_DEL,     /*|*/   KC_PENT,KC_SPC,KC_P0,KC_SLSH,KC_PENT,_______
),

/* Adjust
 * ,-----------------------------------------. ,-----------------------------------------.
 * |EepRST|BotLdr| Debug|Reboot|      |      | |      |      |      |      |      |LckOSX|
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |CpsLck|      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |==XX==| macOS|      |      |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(
    EE_CLR,QK_BOOT,DB_TOGG, QK_RBT,_______,_______,     /*|*/   _______,_______,_______,_______,_______,LOCKSCREEN,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    KC_CAPS,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,TG(_MAC),_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______
),

/* MAC
 * This layout toggles Win/CMD and Left Alt keys's positions for Win and Mac compatibility
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |==XX==|      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      | Alt  | CMD  |      |      | |      |      |      |      |      |      |
 * `-----------------------------------------' `-----------------------------------------'
 */
[_MAC] = LAYOUT_ortho_5x12(
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______,
    _______,_______,KC_LALT,KC_LGUI,_______,_______,    /*|*/   _______,_______,_______,_______,_______,_______
)


};
