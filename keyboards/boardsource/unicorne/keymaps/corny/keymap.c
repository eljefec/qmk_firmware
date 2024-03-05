/*
Copyright 2024 @eljefec

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Layer enums
#define LAYER_COLEMAK 0
#define LAYER_QWERTY 1
#define LAYER_NAV 2
#define LAYER_NUM 3
#define LAYER_SYM 4
#define LAYER_MED 5
#define LAYER_FUN 6
#define LAYER_MOS 7
#define LAYER_COUNT 8

const char *LAYER_NAMES[LAYER_COUNT] = {
    "COLEMAK",
    "QWERTY",
    "NAV",
    "NUMBER",
    "SYMBOL",
    "MEDIA",
    "FUNCTION",
    "MOUSE"
    };

// Composite keys
#define C_PGDN C(KC_PGDN)
#define C_PGUP C(KC_PGUP)
#define G_LEFT G(KC_LEFT)
#define G_RIGHT G(KC_RIGHT)
#define G_UP G(KC_UP)
#define G_DOWN G(KC_DOWN)
#define ST_Z LSFT_T(KC_Z)
#define ST_SLSH RSFT_T(KC_SLSH)
#define CT_QUOT CTL_T(KC_QUOT)
#define LT_SPC LT(LAYER_NAV, KC_SPC)
#define LT_BSPC LT(LAYER_MOS, KC_BSPC)
#define LT_TAB LT(LAYER_NUM, KC_TAB)
#define LT_ENT LT(LAYER_MED, KC_ENT)
#define LT_ESC LT(LAYER_SYM, KC_ESC)
#define LT_DEL LT(LAYER_FUN, KC_DEL)

// One-shot keys
#define O_LGUI OSM(MOD_LGUI)
#define O_LALT OSM(MOD_LALT)
#define O_LCTL OSM(MOD_LCTL)
#define O_LSFT OSM(MOD_LSFT)
#define O_RSFT OSM(MOD_RSFT)

// Home row mods for Colemak-DH
#define G_MT_A GUI_T(KC_A)
#define A_MT_R ALT_T(KC_R)
#define C_MT_S CTL_T(KC_S)
#define S_MT_T LSFT_T(KC_T)
#define S_MT_N RSFT_T(KC_N)
#define C_MT_E CTL_T(KC_E)
#define A_MT_I ALT_T(KC_I)
#define G_MT_O GUI_T(KC_O)

// Home row mods for QWERTY
#define A_MT_S ALT_T(KC_S)
#define C_MT_D CTL_T(KC_D)
#define S_MT_F LSFT_T(KC_F)
#define S_MT_J RSFT_T(KC_J)
#define C_MT_K CTL_T(KC_K)
#define A_MT_L ALT_T(KC_L)
#define G_MT_SCL GUI_T(KC_SCLN)

// Layer keys
#define DF_QWE DF(LAYER_QWERTY)
#define DF_COL DF(LAYER_COLEMAK)
#define DF_NAV DF(LAYER_NAV)
#define DF_NUM DF(LAYER_NUM)
#define DF_SYM DF(LAYER_SYM)
#define DF_MED DF(LAYER_MED)
#define DF_FUN DF(LAYER_FUN)
#define DF_MOS DF(LAYER_MOS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_VOLD, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       O_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  O_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       O_LALT,    ST_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, ST_SLSH, CT_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           LT_ESC,  LT_TAB,  LT_SPC,    LT_BSPC,  LT_ENT,  LT_DEL
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    ST_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, ST_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX,  DF_QWE,  DF_COL,  DF_NAV, XXXXXXX,                       G_LEFT,  G_DOWN,    G_UP, G_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  O_LGUI,  O_LALT,  O_LCTL,  O_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,  KC_APP,  C_PGUP,  C_PGDN, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX,  DF_QWE,  DF_COL,  DF_NUM, XXXXXXX,                      KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  O_LGUI,  O_LALT,  O_LCTL,  O_LSFT, XXXXXXX,                       KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_MINS,    KC_0,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX,  DF_QWE,  DF_COL,  DF_SYM, XXXXXXX,                      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  O_LGUI,  O_LALT,  O_LCTL,  O_LSFT, XXXXXXX,                      KC_PLUS,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_UNDS, KC_LPRN, KC_RPRN
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_MED] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                      XXXXXXX,  DF_MED,  DF_COL,  DF_QWE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                      XXXXXXX,  O_LSFT,  O_LCTL,  O_LALT,  O_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      XXXXXXX,  DF_FUN,  DF_COL,  DF_QWE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                      XXXXXXX,  O_LSFT,  O_LCTL,  O_LALT,  O_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [LAYER_MOS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  DF_MOS,  DF_COL,  DF_QWE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX,                      XXXXXXX,  O_LSFT,  O_LCTL,  O_LALT,  O_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN3, KC_BTN2, KC_BTN1,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )

/*
  // Template for new layer
    [LAYER_X] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
*/

};

enum combo_events {
  EMAIL,
  SPECIAL_Y,
  SPECIAL_I,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM email_combo[] = {KC_W, KC_F, KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM special_y_combo[] = {KC_W, KC_F, KC_P, KC_Y, COMBO_END};
const uint16_t PROGMEM special_i_combo[] = {KC_W, KC_F, KC_P, KC_I, COMBO_END};

combo_t key_combos[] = {
  [EMAIL] = COMBO_ACTION(email_combo),
  [SPECIAL_Y] = COMBO_ACTION(special_y_combo),
  [SPECIAL_I] = COMBO_ACTION(special_i_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case EMAIL:
      if (pressed) {
        SEND_STRING("EMAIL");
      }
      break;
    case SPECIAL_Y:
      if (pressed) {
        SEND_STRING("SPECIAL_Y");
      }
      break;
    case SPECIAL_I:
      if (pressed) {
        SEND_STRING("SPECIAL_I");
      }
      break;
  }
}

#ifdef OLED_ENABLE
void center_cursor_if_needed(const char* data, uint8_t line)
{
    const uint32_t len = strlen(data);
    if (len < oled_max_chars())
    {
        const uint8_t col = oled_max_chars() / 2 - strlen(data) / 2;
        if (line >= oled_max_lines())
        {
            line = 0;
        }
        oled_set_cursor(col, line);
    }
}

void oled_write_centered(const char* data, uint8_t line)
{
    static const char* prev_data = NULL;
    if (prev_data != data)
    {
        center_cursor_if_needed(data, line);
        oled_write_P(data, false);
    }
    prev_data = data;
}

uint8_t get_my_highest_layer(void)
{
    return get_highest_layer(layer_state | default_layer_state);
}

void render_layer(uint8_t line)
{
    const uint8_t highest_layer = get_my_highest_layer();
    if (highest_layer < LAYER_COUNT)
    {
        oled_write_centered(LAYER_NAMES[highest_layer], line);
    }
    else
    {
        oled_clear();
    }
}

typedef struct
{
    uint8_t modMask;
    uint8_t printBufferIndex;
    char charWhenModActive;
} ModMaskPrintSetting;

const ModMaskPrintSetting MOD_MASK_PRINT_SETTINGS[] = {
    {MOD_MASK_GUI, 0, 'G'},
    {MOD_MASK_ALT, 1, 'A'},
    {MOD_MASK_CTRL, 2, 'C'},
    {MOD_MASK_SHIFT, 3, 'S'},
};

uint8_t get_my_mods(void)
{
    return get_mods() | get_oneshot_mods();
}

void render_mods(uint8_t line)
{
    const uint8_t mods = get_my_mods();
    char mod_print_buffer[5];
    const uint8_t MOD_MASK_PRINT_SETTINGS_COUNT = sizeof(MOD_MASK_PRINT_SETTINGS) / sizeof(MOD_MASK_PRINT_SETTINGS[0]);
    for (uint8_t i = 0; i < MOD_MASK_PRINT_SETTINGS_COUNT; ++i)
    {
        const ModMaskPrintSetting* setting = &MOD_MASK_PRINT_SETTINGS[i];
        if (mods & setting->modMask)
        {
            mod_print_buffer[setting->printBufferIndex] = setting->charWhenModActive;
        }
        else
        {
            mod_print_buffer[setting->printBufferIndex] = ' ';
        }
    }
    mod_print_buffer[4] = '\0';

    oled_write_centered(mod_print_buffer, line);
}

typedef struct
{
    uint8_t layer;
    uint8_t mods;
} MainRenderState;

void render_layer_mods(void)
{
    static MainRenderState prev_state = {0, 0};
    const uint8_t highest_layer = get_my_highest_layer();
    const uint8_t mods = get_my_mods();
    MainRenderState cur_state = {highest_layer, mods};
    if (memcmp(&prev_state, &cur_state, sizeof(MainRenderState)) != 0)
    {
        oled_clear();
        render_layer(1);
        render_mods(3);
    }
    prev_state = cur_state;
}

const char* VERSES[] = {
//  "____________________________________________________________________________________", // <-- Max string without wrapping is 84 chars long
    "Do not be anxious about anything, but in every situation, ...",
    "by prayer and petition, with thanksgiving, present your requests to God.",
    "And the peace of God, which transcends all understanding, ...",
    "will guard your hearts and minds in Christ Jesus.",
    "Finally, brothers and sisters, whatever is true, noble, right, pure, lovely, ",
    "admirable--if anything is excellent or praiseworthy--think about such things.",
    "Be strong and courageous.",
    "Do not be afraid; do not be discouraged, ...",
    "for the Lord your God will be with you wherever you go.",
    "Come to me, all you who are weary and burdened, and I will give you rest.",
    "Take my yoke upon you and learn from me, for I am gentle and humble in heart, ...",
    "and you will find rest for your souls."};
uint8_t VERSE_COUNT = sizeof(VERSES) / sizeof(VERSES[0]);

void render_next_verse(void)
{
    static uint8_t verse_index = 0;
    verse_index++;
    if (verse_index >= VERSE_COUNT)
    {
        verse_index = verse_index % VERSE_COUNT;
    }
    oled_write_centered(VERSES[verse_index], 0);
}

bool is_base_layer(const uint8_t layer)
{
    return layer == LAYER_COLEMAK || layer == LAYER_QWERTY;
}

void render_verse(void)
{
    static uint8_t prev_layer = LAYER_COLEMAK;
    const uint8_t highest_layer = get_highest_layer(layer_state | default_layer_state);
    if (prev_layer != highest_layer && !is_base_layer(highest_layer))
    {
        oled_clear();
        render_next_verse();
    }
    prev_layer = highest_layer;
}

bool oled_task_user(void) {
    if (is_keyboard_master())
    {
        render_layer_mods();
    }
    else
    {
        render_verse();
    }
    return false;
}
#endif