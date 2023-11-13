/* Copyright 2017 Paul James (paul@peej.co.uk)
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LAYER,
    _MOD_LAYER,
    _FUNCT
};

#define SFT_A SFT_T(KC_A)
#define SFT_F1 SFT_T(KC_F1)
#define SFT_Z SFT_T(KC_Z)
#define SFT_F6 SFT_T(KC_F6)
#define LAY_X LT(_LAYER, KC_X)
#define LAY_F7 LT(_LAYER, KC_F7)
#define LAY_SLS LT(_LAYER, KC_SLSH)
#define LAY_SPC LT(_LAYER, KC_SPACE)

#define LOCK LGUI(KC_L)
#define MAC_LCK LGUI(LCTL(KC_Q))

#define LAYER MO(_LAYER)
#define FUNCT MO(_FUNCT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ,----------------------------------------   ----------------------------------------.
 * |  Tab  |  Esc  |   (   |   {   |   [   |   |   ]   |   }   |   )   |   '   | BkSp  |
 * |   ~   |   `   |   <   |   _   |   -   |   |   +   |   =   |   >   |   \   |  Del  |
 * |-------+-------+-------+-------+-------+   |-------+-------+-------+-------+-------|
 * |   Q   |   W   |   E   |   R   |   T   |   |   Y   |   U   |   I   |   O   |   P   |
 * |   1   |   2   |   3   |   4   |   5   |   |   6   |   7   |   8   |   9   |   0   |
 * |-------+-------+-------+-------+-------+   |-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |   |   H   |   J   |   K   |   L   | Enter |
 * |  F1   |  F2      F3   |  F4   |  F5   |   | PgUp  | Home  |  Up   |  End  |   ;   |
 * |-Shift-+-------+-------+-------+-------+   |-------+-------+-------+-------+-------|
 * |   Z   |   X   |   C   |   V   |   B   |   |   N   |   M   |   ,   |   .   |   /   |
 * |  F6   |  F7   |  F8   |  F9   |  F10  |   | PgDn  | Left  | Down  | Right |       |
 * `-Shift---Layer-+-------+-------+-------+   |-------+-------+-------+---------Layer-'
 *                 | Ctrl  |  Gui  |  Alt  |   | Space | Layer | Shift |
 *                 |       |       |       |   | Funct |       |       |
 *                 `------------------------   `-Layer-----------------'
 */

[_BASE] = LAYOUT_split_4x5_3(
    KC_TAB,  KC_ESC,  KC_LPRN, KC_LCBR, KC_LBRC,    KC_BSPC, KC_QUOT, KC_RPRN, KC_RCBR, KC_RBRC,
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,
    SFT_A,   KC_S,    KC_D,    KC_F,    KC_G,       KC_ENT,  KC_L,    KC_K,    KC_J,    KC_H,
    SFT_Z,   LAY_X,   KC_C,    KC_V,    KC_B,       LAY_SLS, KC_DOT,  KC_COMM, KC_M,    KC_N,
                      KC_LCTL, KC_LGUI, KC_LALT,    KC_RSFT, LAYER,   LAY_SPC
),

[_LAYER] = LAYOUT_split_4x5_3(
    KC_TILD, KC_GRV,  KC_LABK, KC_UNDS, KC_MINS,    KC_DEL,  KC_BSLS, KC_RABK, KC_EQL,  KC_PLUS,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_0,    KC_9,    KC_8,    KC_7,    KC_6,
    SFT_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_SCLN, KC_END,  KC_UP,   KC_HOME, KC_PGUP,
    SFT_F6,  LAY_F7,  KC_F8,   KC_F9,   KC_F10,     _______, KC_RGHT, KC_DOWN, KC_LEFT, KC_PGDN,
                      _______, _______, _______,    _______, _______, FUNCT
),

[_MOD_LAYER] = LAYOUT_split_4x5_3(
    KC_TILD, _______, _______, _______, _______,    _______, _______, _______, _______, KC_Q,
    KC_TAB,  _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                      _______, _______, _______,    _______, _______, _______
),

[_FUNCT] = LAYOUT_split_4x5_3(
    QK_BOOT, DB_TOGG, QK_LOCK, QK_LEAD, MAC_LCK,    MAGIC_SWAP_LALT_LGUI, _______, _______, _______, LOCK,
    QK_REP, QK_AREP, _______, _______, _______,     _______, _______, _______, _______, _______,
    DT_DOWN, DT_PRNT, DT_UP, EE_CLR, QK_RBT,        _______, _______, _______, _______, _______,
    CW_TOGG, AC_TOGG, _______, _______, _______,    _______, _______, _______, _______, _______,
                      DM_REC1, DM_RSTP, DM_PLY1,    _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (get_mods() & MOD_MASK_CAG) {
        if (record->event.pressed) {
            layer_on(_MOD_LAYER);
        } else {
            layer_off(_MOD_LAYER);
        }
    }

    if (record->event.pressed) {
        if (keycode == KC_BSPC && (get_mods() & MOD_MASK_ALT)) {
            tap_code(KC_DEL);
            return false;
        }
    }

    return true;
};
