/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  BACKLIT,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Colemak-DH
 * ,-----------------------------------------------------------------------------------.
 * | Tab  | Q   |   W  |   F   |  P  |   B   |   J  |   L  |   U  |   Y  |  Å  |  Ä    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |GUI A|LALT R|SHFT  S|CTL T|   G   |   M  |RCTL N|SHFT E|LALT I|GUI O|  Ö    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  Z  |   X  |   C   |   D  |  V   |  K   |   H  |   ,  |   .  |  -  |Enter  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl| Alt  | GUI   |Lower|    Space     | Raise| Bksp |      |     |       |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,               KC_Q,              KC_W,              KC_F,              KC_P,   KC_B,  KC_J,              KC_L,              KC_U,              KC_Y,           KC_LBRC, KC_QUOT,
    KC_ESC, MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_S),MT(MOD_LCTL, KC_T),   KC_G,  KC_M,MT(MOD_RCTL, KC_N),MT(MOD_RSFT, KC_E),MT(MOD_LALT, KC_I),MT(MOD_RGUI, KC_O), KC_SCLN,
    KC_LSFT,              KC_Z,              KC_X,              KC_C,              KC_D,   KC_V,  KC_K,              KC_H,           KC_COMM,            KC_DOT,           KC_SLSH, KC_ENT ,
    _______,            KC_LCTL,           KC_LALT,           KC_LGUI,             LOWER, KC_SPC,KC_SPC,             RAISE,           KC_BSPC,           _______,          _______, _______
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   >  |   !  |   "  |   #  |   €  |   %  |   &  |   /  |   \  |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   @  |      |      |      |   (  |  )   | home |  up  | end  |   ;  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   <  |   >   | left | down | right|     |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |      |             |      | Next | Vol- | Vol+ | Play |
 * `------------- ----------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,   KC_PERC,       KC_CIRC, KC_AMPR, LSFT(LALT(KC_7)), _______, _______, KC_BSPC,
    KC_DEL , RALT(KC_2), _______, _______, _______,LSFT(KC_8),    LSFT(KC_9), KC_HOME, KC_UP  , KC_END , LSFT(KC_COMM), KC_PIPE,
    _______, _______, _______, _______, _______,  KC_GRV ,   LSFT(KC_GRV), KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
    _______, KC_LCTL, KC_LALT, KC_LGUI, _______,   _______,       _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise 
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |      |   '  |  "   |  {   |   }  |   -  |  ´  |   =   |      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  [   |   ]   |ISO # |ISO /|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,     KC_1,    KC_2,    KC_3,      KC_4,             KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    KC_DEL,  _______, _______, KC_BSLS,LSFT(KC_2), RALT(LSFT(KC_8)), RALT(LSFT(KC_9)), KC_MINS,  KC_EQL, LSFT(KC_0), _______, KC_BSLS,
    _______, _______, _______, _______,   _______,       RALT(KC_8),       RALT(KC_9), KC_NUHS, KC_NUBS, _______, _______, _______,
    _______, _______, _______, _______,   _______,          _______,          _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |   F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7    |  F8   |  F9     | F10  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BOOTLD|   F11 | F12  | .    | .    | Click|Rclick|ScrollDn|MouseUp|ScrollUp |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Debug| AGnorm|AGswap| .    |      | .    |Mclick|MouseLt |MouseDn|MouseRt  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |       |      |      |      |             |        |       |         |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    QK_BOOT, KC_F11,  KC_F12, _______, _______, KC_BTN1, KC_BTN2, KC_WH_D, KC_MS_U, KC_WH_U,  _______, _______,
    _______,AG_NORM, AG_SWAP, _______, _______, _______, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R,  _______, _______,
    DEBUG , _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            // static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                // if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                // if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            // play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
