/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "keymap_swedish.h"

enum layers {
    _COLEMAK = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _RGB,
    // _UNICODE,
    // _MOUSE,
    _BRACKET,
    _QWERTY,
};

// enum custom_keycodes {
//     BR_Q = SAFE_RANGE,
// };

// enum unicode_names {
//     SAD,
//     VERY_SAD,
//     HAPPY,
//     VERY_HAPPY,
//     THUMBD,
//     THUMBU,
//     LIGHTB,
//     CELEBRATE,
// };

// const uint32_t PROGMEM unicode_map[] = {
//     [SAD]  = 0x1f622, // 😢
//     [VERY_SAD] = 0x1f62d, // 😭
//     [HAPPY] = 0x1f642, // 🙂
//     [VERY_HAPPY] = 0x1f600, // 😀
//     [THUMBD] = 0x1f44d, // 👍
//     [THUMBU] = 0x1f44e, // 👎
//     [LIGHTB] = 0x1f4a1, // 💡
//     [CELEBRATE] = 0x1f389, // 🎉
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Adjust |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  \     |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Mouse  |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | :    |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Swap H |   Z  |   X  |   C  |   V  |   B  |RGB   | XXX  |  |Ctrsht|Colmak|   N  |   M  | ,  < | . >  | /  ? |  _     |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ENC  | Del  | Enter| Esc  |      |  | Bksp |      | Space| Tab  | ENC  |
 *                        |      | Raise| Lower| Meta | LAlt |  | LCtrl| LShft| Lower| Raise|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      MO(_ADJUST),  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      MO(_BRACKET),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      SH_OS,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   MO(_RGB),  XXXXXXX,    C_S_T(KC_NO), DF(_COLEMAK), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UNDS,
      XXXXXXX, LT(_RAISE, KC_DEL), LT(_LOWER, KC_ENT), LGUI_T(KC_ESC), KC_LALT,    LCTL_T(KC_BSPC), KC_LSFT, LT(_LOWER, KC_SPC),  LT(_RAISE, KC_TAB), XXXXXXX
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |  _   |  ?   |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  ;   |  "     |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  | ____ |      |   &  |  =   |  <   |  >   |  \   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      | Del  | Enter| ____ | ____ |  | ____ | Space| Tab  | Bksp |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
      XXXXXXX, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                       XXXXXXX, KC_UNDS, KC_QUES, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                        KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_SCLN, KC_DQUO,
      XXXXXXX, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, XXXXXXX, XXXXXXX,   _______, XXXXXXX, KC_AMPR, KC_EQL,  KC_LABK, KC_RABK,  KC_BSLS, XXXXXXX,
                                 XXXXXXX, KC_DEL,  KC_ENT,  _______, _______,   KC_BSPC, _______,  KC_SPC, KC_TAB,  XXXXXXX
    ),
/*
 * Raise Layer: Number keys, movement, repeat Space, Bksp etc
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |McrSt |  1   |  2   |  3   |      |                              | Left | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  4   |  5   |  6   |  0   |                              |  H   |  J   |  K   |  L   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Swap H |      |  7   |  8   |  9   |      |      |      |  | ____ |      |      | PgDn | PgUp |      |      | Swap H |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      | Del  | Enter| ____ | ____ |  | ____ | Space| Tab  | Bksp |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      XXXXXXX, DM_REC1, KC_1,    KC_2,    KC_3, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, DM_PLY1, KC_4,    KC_5,    KC_6, KC_0,                                          KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
      SH_TG,   XXXXXXX, KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX, XXXXXXX,   _______, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, SH_TG,
                              XXXXXXX, _______,  _______,  _______, _______,   _______, _______,  _______,  _______, XXXXXXX
    ),
/*
 * Adjust Layer: Function keys, Movement
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              | Left | Down | Up   | Right| F11  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|      |      |  |      |      |      | PgDn | PgUp |      | F12  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      | PSCR |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F10,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11,                                       KC_MPRV, KC_MPLY, KC_MUTE,  KC_MNXT, KC_F11,  XXXXXXX,
      XXXXXXX, XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F12, XXXXXXX, XXXXXXX,   _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, KC_F12,  XXXXXXX,
                                 XXXXXXX, _______, _______, _______, _______,   _______, _______, KC_PSCR, _______, XXXXXXX
    ),
/*
 * LED RGB layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      | RESET| TOGGL|                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | SATUR|      |      |      |                              | HUI  | NEXTM| PREVM|      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      | BRIGH|      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      | ____ |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RGB] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_P, RGB_TOG,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX,                                     RGB_HUI, RGB_MOD, RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
/*
 * Unicode, emoji layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      | Å      |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | 😢 😭|      |      |      |                              | 🙂 😀| 👎   | 👍   | 💡   | Ö    | Ä      |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      | 🎉   |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    // [_UNICODE] = LAYOUT(
    //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, X(LIGHTB), XXXXXXX, XXXXXXX, XXXXXXX, SE_ARNG,
    //   XXXXXXX, XXXXXXX, XXXXXXX, XP(SAD, VERY_SAD), XXXXXXX, XXXXXXX,                    XP(HAPPY, VERY_HAPPY), X(THUMBD), X(THUMBU), XXXXXXX, SE_ODIA, SE_ADIA,
    //   XXXXXXX, XXXXXXX, XXXXXXX, X(CELEBRATE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    // ),
// /*
//  * mouse layer
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        | MACC0| MACC1| MACC2|      |      |                              | MLeft| Mdown| Mup  |MRight|      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      | WHDwn| WHUp |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  | ____ | ____ | MLClk| MRClk|      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_MOUSE] = LAYOUT(
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//       XXXXXXX, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, XXXXXXX, XXXXXXX,                              KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
//       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,       XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,
//                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, KC_MS_BTN1, KC_MS_BTN3, XXXXXXX
//     ),
// /*
//  * bracket layer
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        | BR_Q |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_BRACKET] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
/*
 * Colemak layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Adjust |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  | :    |  \     |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | Mouse  |   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Swap H |   Z  |   X  |   C  |   V  |   B  | RGB  | XXX  |  |Ctrsht|Qwerty|   K  |   M  | ,  < | . >  | /  ? |  _     |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ENC  | Del  | Enter| Esc  |      |  | Bksp |      | Space| Tab  | ENC  |
 *                        |      | Raise| Lower| Meta | LAlt |  | LCtrl| LShft| Lower| Raise|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT(
      MO(_ADJUST),  KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,                                                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_COLN, KC_BSLS,
      MO(_BRACKET),   KC_A,   KC_R,   KC_S,   KC_T,   KC_D,                                                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
      SH_OS,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   MO(_RGB),  XXXXXXX,    C_S_T(KC_NO), DF(_QWERTY), KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UNDS,
      XXXXXXX, LT(_RAISE, KC_DEL), LT(_LOWER, KC_ENT), LGUI_T(KC_ESC), KC_LALT,    LCTL_T(KC_BSPC), KC_LSFT, LT(_LOWER, KC_SPC),  LT(_RAISE, KC_TAB), XXXXXXX
    ),
/*
//  * layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
    /* return update_tri_layer_state(state, _LOWER, _RAISE, _REPEAT); */
    /* switch (get_highest_layer(state)) { */
    /*     case _RAISE: */
    /*         rgblight_setrgb (0x00,  0x00, 0xFF); */
    /*         break; */
    /*     case _LOWER: */
    /*         rgblight_setrgb (0xFF,  0x00, 0x00); */
    /*         break; */
    /*     case _RGB: */
    /*         rgblight_setrgb (0x00,  0xFF, 0x00); */
    /*         break; */
    /*     case _ADJUST: */
    /*         rgblight_setrgb (0x7A,  0x00, 0xFF); */
    /*         break; */
    /*     case _MOUSE: */
    /*         rgblight_setrgb (0x7A,  0xFF, 0x00); */
    /*         break; */
    /*     case _UNICODE: */
    /*         rgblight_setrgb (0x00,  0xFF, 0xFF); */
    /*         break; */
    /*     default: //  for any other layers, or the default layer */
    /*         rgblight_setrgb (0x7A,  0xFF, 0xFF); */
    /*         break; */
    /* } */
    /* return state; */
/* } */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

/* static void render_kyria_logo(void) { */
/*     static const char PROGMEM kyria_logo[] = { */
/*         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0, */
/*         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 */
/*     }; */
/*     oled_write_raw_P(kyria_logo, sizeof(kyria_logo)); */
/* } */

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB ("), false);
            oled_write_char(rgblight_get_mode() + '0', false);
            oled_write_P(PSTR(")\n"), false);
            break;
        // case _UNICODE:
        //     oled_write_P(PSTR("Unicode\n"), false);
        //     break;
        // case _MOUSE:
        //     oled_write_P(PSTR("Mouse\n"), false);
        //     break;
        case _BRACKET:
            oled_write_P(PSTR("Brackes\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // TODO swap hands
    if (swap_hands) {
        oled_write_P(PSTR("Swapped hands"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    // } else {
        /* render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc) */
        /* render_kyria_logo(); */
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _LOWER:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _RAISE:
                if (clockwise) {
                    for (int i=0; i<10; i++) {
                        tap_code(KC_WH_D);
                    }
                } else {
                    for (int i=0; i<10; i++) {
                        tap_code(KC_WH_U);
                    }
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
        }
    }
    return true;
}
#endif

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//     case BR_Q:
//         if (record->event.pressed) {
//             // when keycode QMKBEST is pressed
//             SEND_STRING("]q");
//         } else {
//             // when keycode QMKBEST is released
//         }
//         break;
//     }
//     return true;
// };
