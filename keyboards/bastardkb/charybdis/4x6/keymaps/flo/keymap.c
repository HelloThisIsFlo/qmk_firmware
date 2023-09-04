/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUM = 1,
    LAYER_SYM = 2,
    LAYER_FUN = 3,
    LAYER_PTR = 4,
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_PTR

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE


#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL XXXXXXX
#    define DPI_MOD XXXXXXX
#    define S_D_MOD XXXXXXX
#    define SNIPING XXXXXXX
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────────────────────────────────────────╮   ╭───────────────────────────────────────────────────────────────────────────────────────────────╮
                XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,          KC_W,          KC_L,          KC_Y,          KC_P,          KC_B,                    KC_Z,          KC_F,          KC_O,          KC_U,       KC_QUOT,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,  LCTL_T(KC_C),  LALT_T(KC_R),  LGUI_T(KC_S),  LSFT_T(KC_T),          KC_G,                    KC_M,  LSFT_T(KC_N),  LGUI_T(KC_E),  LALT_T(KC_I),  LCTL_T(KC_A),       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,    LT(4,KC_Q),          KC_J,          KC_V,          KC_D,          KC_K,                    KC_X,          KC_H,       KC_SLSH,       KC_COMM,  LT(4,KC_DOT),       XXXXXXX,
  // ╰───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────╯
                                                             XXXXXXX,  LT(2,KC_SPC),  LT(3,KC_ENT),         LSFT_T(KC_BSPC),   LT(1,KC_ESC),
                                                                            XXXXXXX,       XXXXXXX,                 XXXXXXX
  //                                                      ╰──────────────────────────────────────────╯   ╰──────────────────────────────────────────╯
    ),

    [LAYER_NUM] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────────────────────────────────────────╮   ╭───────────────────────────────────────────────────────────────────────────────────────────────╮
                XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,       XXXXXXX,         KC_P7,         KC_P8,         KC_P9,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,       XXXXXXX,         KC_P4,         KC_P5,         KC_P6,       XXXXXXX,                 KC_LEFT,       KC_DOWN,         KC_UP,       KC_RGHT,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,       XXXXXXX,         KC_P1,         KC_P2,         KC_P3,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ╰───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────╯
                                                               KC_P0,       XXXXXXX,       XXXXXXX,                 XXXXXXX,       _______,
                                                                            XXXXXXX,       XXXXXXX,                 XXXXXXX
  //                                                      ╰──────────────────────────────────────────╯   ╰──────────────────────────────────────────╯
    ),


    [LAYER_SYM] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────────────────────────────────────────╮   ╭───────────────────────────────────────────────────────────────────────────────────────────────╮
                XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,       KC_QUOT,         KC_LT,         KC_GT,       KC_DQUO,       KC_PDOT,                 KC_AMPR,       XXXXXXX,       KC_LBRC,       KC_RBRC,       KC_PERC,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,       KC_EXLM,       KC_PMNS,       KC_PPLS,       KC_PEQL,       KC_HASH,                 KC_PIPE,       KC_COLN,       KC_LPRN,       KC_RPRN,       KC_QUES,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,       KC_CIRC,       KC_PSLS,       KC_PAST,       KC_BSLS,       XXXXXXX,                 KC_TILD,        KC_DLR,       KC_LCBR,       KC_RCBR,         KC_AT,       XXXXXXX,
  // ╰───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────╯
                                                             XXXXXXX,       _______,       XXXXXXX,                 XXXXXXX,       XXXXXXX,
                                                                            XXXXXXX,       XXXXXXX,                 XXXXXXX
  //                                                      ╰──────────────────────────────────────────╯   ╰──────────────────────────────────────────╯
    ),

    [LAYER_FUN] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────────────────────────────────────────╮   ╭───────────────────────────────────────────────────────────────────────────────────────────────╮
                XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,         KC_F9,         KC_F8,         KC_F7,        KC_F12,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,         KC_F6,         KC_F5,         KC_F4,        KC_F11,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,         KC_F3,         KC_F2,         KC_F1,        KC_F10,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ╰───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────╯
                                                             XXXXXXX,       XXXXXXX,       _______,                 XXXXXXX,       XXXXXXX,
                                                                            XXXXXXX,       XXXXXXX,                 XXXXXXX
  //                                                      ╰──────────────────────────────────────────╯   ╰──────────────────────────────────────────╯
    ),

    [LAYER_PTR] = LAYOUT(
  // ╭───────────────────────────────────────────────────────────────────────────────────────────────╮   ╭───────────────────────────────────────────────────────────────────────────────────────────────╮
                XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       DPI_MOD,       S_D_MOD,                 S_D_MOD,       DPI_MOD,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,       KC_LGUI,       KC_LALT,       KC_LCTL,       KC_LSFT,       XXXXXXX,                 XXXXXXX,       KC_RSFT,       KC_RCTL,       KC_RALT,       KC_RGUI,       XXXXXXX,
  // ├───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────┤
                XXXXXXX,       _______,       DRGSCRL,       SNIPING,         EE_CLR,      QK_BOOT,                 QK_BOOT,         EE_CLR,       SNIPING,       DRGSCRL,       _______,       XXXXXXX,
  // ╰───────────────────────────────────────────────────────────────────────────────────────────────┤   ├───────────────────────────────────────────────────────────────────────────────────────────────╯
                                                             KC_BTN2,       KC_BTN1,       KC_BTN3,                 KC_BTN3,       KC_BTN1,
                                                                            XXXXXXX,       KC_BTN2,                 KC_BTN2
  //                                                      ╰──────────────────────────────────────────╯   ╰──────────────────────────────────────────╯
    ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_PTR);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_PTR);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb(RGB_RED);
#endif // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(RGB_RED);
    rgb_matrix_update_pwm_buffers();
#endif // RGB_MATRIX_ENABLE
}
