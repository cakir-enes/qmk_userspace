/* Copyright 2023 ozkan
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

enum keymap_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SPACE,
  _SODA,
  _NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /* Qwerty
    * ,-------------------------------------------------------------------------------------------------.
    * |  Tab |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * |NPdEsc|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   Ş  |   İ  |
    * |------+------+------+------+------+------|             |------+------+------+------+------+------|
    * |SftCps|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   Ö  |   Ç  |   .  |SftEtr|
    * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
    * |Sda|<>| Ctrl | Alt  |  OS  |Lowr|,|Space*|LftClk|RgtClk| Bksp |Rise|"| Left | Down |  Up  |Right |
    * `-------------------------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_ortho_4x12_grid_ardakilic(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        LT(_NUMPAD, KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        LSFT_T(KC_CAPS), KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT) /*KC_ENT*/,
        LT(_SODA, KC_GRV), KC_LCTL, KC_LALT, KC_LGUI, LT(_LOWER, KC_BSLS), LT(_SPACE, KC_SPC), KC_MS_BTN1, KC_MS_BTN2, KC_BSPC, LT(_RAISE, KC_NONUS_BACKSLASH), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

    /* Lower
     * ,-------------------------------------------------------------------------------------------------.
     * |   >  |   !  |   '  |   ^  |   +  |   %  |             |   &  |   /  |   (  |   )  |   =  | BKSP |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |      |  :   |             |   _  |   ?  |   -  |  Ğ   |  Ü   |  -   |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |  F5  |  F6  |  F7  |  F8  |      |      |             |      |  "$" |  "{" |  "}" |  <   |  ">" |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |  F9  |  F10 |  F11 |  F12 |      |  DEL |LftClk|RgtClk| BKSP |      |  "[" |  "]" |  '   |   "  |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12_grid_ardakilic(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
        KC_F1,  KC_F2,   KC_F3,   KC_F4,   _______,   LSFT(KC_SLSH),   KC_PLUS,   KC_UNDS,    KC_PLUS,    KC_LBRC, KC_RBRC, KC_EQL,
        KC_F5, KC_F6,   KC_F7,   KC_F8,   _______,  _______,  _______,  DOLLAR_SIGN, CURLY_OPEN, CURLY_CLOSE, KC_GRV, LSFT(KC_GRV),
        KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_DEL, KC_MS_BTN1, KC_MS_BTN2, KC_BSPC, _______,   SQUARE_OPEN, SQUARE_CLOSE, LSFT(KC_2), KC_NONUS_BACKSLASH
    ),

    /* Raise
     * ,-------------------------------------------------------------------------------------------------.
     * |  <>| |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |      |  :   |             |   _  |   *  |   -  | "\"  | "|"  |  ,   |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |  F5  |  F6  |  F7  |  F8  |      |      |             |      |   #  |   "  | "~"  | "`"  |  <>| |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |  F9  |  F10 |  F11 |  F12 |      | DEL  |LftClk|RgtClk| BKSP |      | Next | Vol- | Vol+ | Play |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12_grid_ardakilic(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_F1,  KC_F2,   KC_F3,   KC_F4,   _______,   LSFT(KC_SLSH),   KC_PLUS,   KC_MINS, KC_EQL,  BACKSLASH, VERTICAL_PIPE, KC_BSLS,
        KC_F5, KC_F6,   KC_F7,   KC_F8,   _______,  _______,  _______,  HASHTAG, KC_NUBS, TILDE, BACKTICK, KC_GRV,
        KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_DEL, KC_MS_BTN1, KC_MS_BTN2, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    /* Soda Layer. Adjust and other stuff
     * ,-------------------------------------------------------------------------------------------------.
     * |EepRST|BotLdr| Debug|Reboot|      |      |             |      |      |  Up  |      |      |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |BRGTH+| SAT+ | HUE+ |RGBMOD|  RGB |             |      | Left | Down |Right |      | Mute |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |BRGTH-| SAT- | HUE- |      |      |             |      |      | Next | Vol- | Vol+ | Play |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |      |      |MSC_N |AUD_N |M_TOGG|A_TOGG|      |      |      |Brght▼|Brght▲|
     * `-------------------------------------------------------------------------------------------------'
     */
    [_SODA] = LAYOUT_ortho_4x12_grid_ardakilic(
        EE_CLR,  QK_BOOT, DB_TOGG, QK_RBT, _______, _______, _______, _______, KC_UP, _______, _______, _______,
        _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_MUTE,
        _______, RGB_VAD, RGB_SAD, RGB_HUD, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
        _______, _______, _______, _______, _______, QK_MUSIC_MODE_NEXT, QK_AUDIO_VOICE_NEXT, QK_MUSIC_TOGGLE, QK_AUDIO_TOGGLE, _______, _______, _______, KC_BRMD, KC_BRMU
    ),

    /* Space Layer (Space Bar Layer Tap)
     * ,-------------------------------------------------------------------------------------------------.
     * |      |CMD+1 |CMD+2 |CMD+3 |CMD+4 |CMD+5 |             |CMD+6 |CMD+7 |CMD+8 |CMD+9 |CMD+0 |LCKOSX|
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             |      |      |      |  Up  |      |      |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             |      |      | Left | Down |Right |      |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |LftClk|RgtClk|      |      |      |      |Brght▼|Brght▲|
     * `-------------------------------------------------------------------------------------------------'
     */
    [_SPACE] = LAYOUT_ortho_4x12_grid_ardakilic(
        _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8),  LGUI(KC_9), LGUI(KC_0), LOCKSCREEN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
        _______, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______, _______, KC_BRMD, KC_BRMU
    ),

    /* Numpad Layer
     * KC_PDOT is comma on the Turkish layout ¯\_(ツ)_/¯
     * ,-------------------------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |             | Space|   7  |   8  |   9  |   -  | Bksp |
     * |------+------+------+------+------+------+             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             | Enter|   4  |   5  |   6  |   +  |   *  |
     * |------+------+------+------+------+------|             |------+------+------+------+------+------|
     * |      |      |      |      |      |      |             | Enter|   1  |   2  |   3  |   +  |   /  |
     * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |LftClk|RgtClk| Bkspc|   0  |   0  |   .  |   ,  |   =  |
     * `-------------------------------------------------------------------------------------------------'
     */
    [_NUMPAD] = LAYOUT_ortho_4x12_grid_ardakilic(
        _______, _______, _______, _______, _______, _______, KC_SPC, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_BSPC,
        _______, _______, _______, _______, _______, _______, KC_PENT, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST,
        _______, _______, _______, _______, _______, _______, KC_PENT, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_PSLS,
        _______, _______, _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, KC_BSPC,  KC_P0, KC_P0, KC_SLSH, KC_PDOT, KC_PEQL
    ),

};
