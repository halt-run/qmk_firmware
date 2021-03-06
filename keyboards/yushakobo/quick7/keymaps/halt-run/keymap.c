/* Copyright 2020 yushakobo
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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        LALT(KC_TAB),   KC_MUTE, RGB_MOD,
        KC_MRWD,   KC_MPLY,    KC_MFFD,
        KC_MPRV,   KC_MSTP,    KC_MNXT
    )
};

/* Please note that the original keymap has support for 2 encoders,
but in this one we are only using the second one. You can still access
encoder 0 by adding the appropriate condition below.*/
void encoder_update_user(uint8_t index, bool clockwise) {
      if (index == 1) { // Volume encoder, defined as top / right
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
