#include QMK_KEYBOARD_H

// Tap Dance declarations
enum tap_dances {
    TD_SPC_TAB = 0,
    TD_OPENBRACE,
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum { HOLD = 1, SINGLE_TAP = 2, DOUBLE_TAP = 3, TRIPLE_TAP = 4, QUAD_TAP = 5 };

int cur_dance(qk_tap_dance_state_t *state) {
  if (state->pressed)
    return HOLD;

  if (state->count == 1)
    return SINGLE_TAP;

  if (state->count == 2)
    return DOUBLE_TAP;

  if (state->count == 3)
    return TRIPLE_TAP;

  if (state->count == 4)
    return QUAD_TAP;

  return -1;
}

static int spl_o_tap_state = 0;
static int spl_c_tap_state = 0;

void space_cadet_open_finished(qk_tap_dance_state_t *state, void *user_data) {
  spl_o_tap_state = cur_dance(state);
  switch (spl_o_tap_state) {
  case SINGLE_TAP:
    register_mods(MOD_BIT(KC_LSFT));
    register_code(KC_9); // (
    break;
  case DOUBLE_TAP:
    register_mods(MOD_BIT(KC_LSFT));
    register_code(KC_LBRC); // {
    break;
  case TRIPLE_TAP:
    register_code(KC_LBRC); // [
    break;
  case QUAD_TAP:
    register_mods(MOD_BIT(KC_LSFT));
    register_code(KC_COMMA); // <
    break;
  case HOLD:
    register_mods(MOD_BIT(KC_LSFT));
  }
}

void space_cadet_open_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (spl_o_tap_state) {
  case SINGLE_TAP:
    unregister_code(KC_9);
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  case DOUBLE_TAP:
    unregister_code(KC_LBRC); // [
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  case TRIPLE_TAP:
    unregister_code(KC_LBRC); // {
    break;
  case QUAD_TAP:
    unregister_code(KC_COMMA); // <
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  case HOLD:
    unregister_mods(MOD_BIT(KC_LSFT));
    break;
  }
  spl_o_tap_state = 0;
}

void space_cadet_close_finished(qk_tap_dance_state_t *state, void *user_data) {
  spl_c_tap_state = cur_dance(state);
  switch (spl_c_tap_state) {
  case SINGLE_TAP:
    register_mods(MOD_BIT(KC_RSFT));
    register_code(KC_0); // )
    break;
  case DOUBLE_TAP:
    register_mods(MOD_BIT(KC_RSFT));
    register_code(KC_RBRC); // }
    break;
  case TRIPLE_TAP:
    register_code(KC_RBRC); // ]
    break;
  case QUAD_TAP:
    register_mods(MOD_BIT(KC_RSFT));
    register_code(KC_DOT); // >
    break;
  case HOLD:
    register_mods(MOD_BIT(KC_RSFT));
  }
}

void space_cadet_close_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (spl_c_tap_state) {
  case SINGLE_TAP:
    unregister_code(KC_0); // )
    unregister_mods(MOD_BIT(KC_RSFT));
    break;
  case DOUBLE_TAP:
    unregister_code(KC_RBRC); // }
    unregister_mods(MOD_BIT(KC_RSFT));
    break;
  case TRIPLE_TAP:
    unregister_code(KC_RBRC); // ]
    break;
  case QUAD_TAP:
    unregister_code(KC_DOT); // >
    unregister_mods(MOD_BIT(KC_RSFT));
    break;
  case HOLD:
    unregister_mods(MOD_BIT(KC_RSFT));
    break;
  }
  spl_c_tap_state = 0;
}


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_TAB),
    [TD_OPENBRACE] = ACTION_TAP_DANCE_FN_ADVANCED(
        NULL, space_cadet_open_finished, space_cadet_open_reset),
};

const uint16_t PROGMEM circ[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM ampr[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM past[] = {KC_I, KC_O, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(circ, KC_CIRC),
    COMBO(ampr, KC_AMPR),
    COMBO(past, KC_PAST),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_charybdis_4x6(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                                        KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        HYPR_T(KC_ESC), LALT_T(KC_A), LCTL_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F),KC_G, KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RCTL_T(KC_L), RALT_T(KC_SCLN), KC_QUOT,
        TD(TD_OPENBRACE), LT(3,KC_Z), KC_X, KC_C, KC_V, KC_B,                        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_OPENBRACE),
                               KC_BSPC, KC_DEL, KC_ENT,                              RSFT_T(KC_ENT), TD(TD_SPC_TAB),
                               KC_LALT, KC_PGUP,                                     LT(1,KC_PGDN)),
    [1] = LAYOUT_charybdis_4x6(
        QK_BOOT, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        EE_CLR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_LBRC, KC_P7, KC_P8, KC_P9, KC_RBRC, KC_NO,
        HYPR_T(KC_ESC), KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                   KC_PPLS, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PEQL,
        KC_NO, KC_NO, KC_NO, KC_NO, EE_CLR, QK_BOOT,                                 KC_PAST, KC_P1, KC_P2, KC_P3, KC_PSLS, KC_PDOT,
                               KC_NO, KC_NO, KC_TRNS,                                KC_TRNS, KC_TRNS,
                               KC_NO, KC_NO,                                         KC_TRNS),
    [2] = LAYOUT_charybdis_4x6(
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_WBAK, KC_WFWD, KC_NO, KC_NO, KC_NO, DRGSCRL,
                               KC_NO, KC_NO, KC_NO,                                  KC_NO, KC_BTN2,
                               KC_NO, DRGSCRL,                                       KC_BTN1),
};
