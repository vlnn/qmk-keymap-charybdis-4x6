#include QMK_KEYBOARD_H

// Tap Dance declarations
enum tap_dances {
    TD_SPC_TAB = 0,
    TD_SLASH_SPC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_TAB),
    [TD_SLASH_SPC] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_SPC),
};

enum unicode_names {
    UA_IE=10,
    UA_ie,
    UA_G,
    UA_g,
};

const uint32_t unicode_map[] PROGMEM = {
    [UA_IE] = 0x0404,  // Є
    [UA_ie] = 0x0454,  // є
    [UA_G]  = 0x0490,   // Ґ
    [UA_g]  = 0x0491,   // ґ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_charybdis_4x6(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                                        KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        MEH(KC_ESC), LALT_T(KC_A), LCTL_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RCTL_T(KC_L), RALT_T(KC_SCLN), KC_QUOT,
        KC_LCTL, LT(3,KC_Z), KC_X, KC_C, KC_V, KC_B,                                 KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LBRC,
                               KC_BSPC, KC_DEL, KC_ENT,                              KC_ENT, TD(TD_SPC_TAB),
                               KC_LALT, KC_LGUI,                                     LT(1,S(KC_LPRN))),
    [1] = LAYOUT_charybdis_4x6(
        QK_BOOT, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        EE_CLR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_LBRC, KC_P7, KC_P8, KC_P9, KC_RBRC, KC_NO,
        MEH(KC_ESC), KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                      KC_PPLS, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PEQL,
        KC_NO, KC_NO, KC_NO, KC_NO, EE_CLR, QK_BOOT,                                 KC_PAST, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_PDOT,
                               KC_NO, KC_NO, KC_TRNS,                                KC_TRNS, KC_TRNS,
                               KC_NO, KC_NO,                                         KC_TRNS),
    [2] = LAYOUT_charybdis_4x6(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_WBAK, KC_WFWD, KC_NO, KC_NO, KC_NO, DRGSCRL,
                               KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_BTN2,
                               KC_NO, DRGSCRL,                                       KC_BTN1),
};
