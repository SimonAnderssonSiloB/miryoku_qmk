// Custom Colemak DH layout for Crkbd (split_3x6_3)
// Based on Miryoku-style layers with custom shortcuts

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    BASE,
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
    FUN,
    MISC,
    DEBUG,
    CODE,
    EDIT,
    BROWSE
};

// Custom keycodes
enum custom_keycodes {
    U_SAVA = SAFE_RANGE,  // Save All (OS-aware)
};

// Unicode map indices
enum unicode_names {
    U_AO_L,  // å
    U_AO_U,  // Å
    U_AE_L,  // ä
    U_AE_U,  // Ä
    U_OE_L,  // ö
    U_OE_U,  // Ö
};

const uint32_t unicode_map[] PROGMEM = {
    [U_AO_L] = 0x00E5,  // å
    [U_AO_U] = 0x00C5,  // Å
    [U_AE_L] = 0x00E4,  // ä
    [U_AE_U] = 0x00C4,  // Ä
    [U_OE_L] = 0x00F6,  // ö
    [U_OE_U] = 0x00D6,  // Ö
};

// Use UP(lower, upper) for shift-aware Unicode pairs
#define DE_AO UP(U_AO_L, U_AO_U)
#define DE_AE UP(U_AE_L, U_AE_U)
#define DE_OE UP(U_OE_L, U_OE_U)

// Shortcut defines
#define U_FND  C(KC_F)          // Find
#define U_AFD  C(S(KC_F))      // Advanced find
#define U_FIL  C(KC_P)          // Search file
#define U_RPLC C(KC_H)          // Replace

#define U_SRC  C(KC_T)          // Search
#define U_CLS  A(KC_F4)         // Close application

#define U_COM  C(KC_SLSH)       // Comment out selection

#define U_BLD  C(S(KC_B))       // Build
#define U_RUN  C(KC_F5)         // Run
#define U_DBG  KC_F5            // Run in debug
#define U_RFS  KC_F5            // Refresh

#define U_TBP  KC_F9            // Toggle breakpoint
#define U_RSM  C(S(A(KC_F5)))   // Resume execution

#define U_SAV  C(KC_S)          // Save

#define U_NAB  KC_BTN4          // Navigate back
#define U_NAF  KC_BTN5          // Navigate forward

#define U_NTB  C(KC_N)          // New tab
#define U_NTBW C(KC_T)          // New tab (web)
#define U_CTB  C(KC_F4)         // Close tab
#define U_UCT  C(S(KC_T))       // Undo close tab

#define U_INC  KC_F12           // Go into code
#define U_REF  S(KC_F12)        // Go to references

#define U_FOR  S(A(KC_F))       // Format

#define U_STG  C(KC_NUBS)       // Stage
#define U_USG  C(S(KC_GT))      // Unstage

#define U_VBF  S(A(KC_Q))       // Vimium highlight links
#define U_VBFF S(A(KC_W))       // Vimium highlight links alt

// Undo/Redo/Cut/Copy/Paste
#define U_UND  C(KC_Z)
#define U_RDO  C(KC_Y)
#define U_CUT  C(KC_X)
#define U_CPY  C(KC_C)
#define U_PST  C(KC_V)

// Convenience
#define U_NA   KC_NO
#define U_NP   KC_NO
#define U_NU   KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * BASE: Colemak DH
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │ MISC │  Q   │  W   │  F   │  P   │  B   │       │  J   │  L   │  U   │  Y   │  '   │  Å   │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │ CODE │GUI/A │ALT/R │CTL/S │SFT/T │  G   │       │  M   │SFT/N │CTL/E │ALT/I │GUI/O │  Ä   │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │ EDIT │DBG/Z │  X   │  C   │  D   │  V   │       │  K   │  H   │  ,   │  .   │  /   │  Ö   │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │MED/Es│NAV/Sp│MOU/Tb│       │SYM/En│NUM/Bs│FUN/Dl│
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [BASE] = LAYOUT_split_3x6_3(
        MO(MISC),      LT(BROWSE,KC_Q),   KC_W,         KC_F,         KC_P,         KC_B,               KC_J,         KC_L,         KC_U,         KC_Y,         KC_QUOT,      DE_AO,
        MO(CODE),      LGUI_T(KC_A),      LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,               KC_M,         LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), DE_AE,
        MO(EDIT),      LT(DEBUG,KC_Z),    KC_X,         KC_C,         KC_D,         KC_V,               KC_K,         KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      DE_OE,
                                              LT(MEDIA,KC_ESC), LT(NAV,KC_SPC), LT(MOUSE,KC_TAB),      LT(SYM,KC_ENT), LT(NUM,KC_BSPC), LT(FUN,KC_DEL)
    ),

    /*
     * NAV: Navigation
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │ BOOT │      │      │      │      │       │ Redo │Paste │ Copy │ Cut  │ Undo │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │ GUI  │ ALT  │ CTL  │ SFT  │      │       │ Caps │  ←   │  ↓   │  ↑   │  →   │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │AltGr │      │      │      │       │ Ins  │ Home │ PgDn │ PgUp │ End  │      │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │      │      │      │       │Enter │ Bspc │ Del  │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [NAV] = LAYOUT_split_3x6_3(
        U_NA, QK_BOOT, U_NA,    U_NA,    U_NA,    U_NA,               U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   U_NA,
        U_NA, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,               KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, U_NA,
        U_NA, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,               KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  U_NA,
                                         U_NA,    U_NA,    U_NA,       KC_ENT,  KC_BSPC, KC_DEL
    ),

    /*
     * MOUSE: Mouse Keys
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │ BOOT │      │      │      │      │       │ Redo │Paste │ Copy │ Cut  │ Undo │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │ GUI  │ ALT  │ CTL  │ SFT  │      │       │      │ Ms←  │ Ms↓  │ Ms↑  │ Ms→  │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │AltGr │      │      │      │       │      │ Wh←  │ Wh↓  │ Wh↑  │ Wh→  │      │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │      │      │      │       │ Btn1 │ Btn3 │ Btn2 │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [MOUSE] = LAYOUT_split_3x6_3(
        U_NA, QK_BOOT, U_NA,    U_NA,    U_NA,    U_NA,               U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   U_NA,
        U_NA, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,               U_NU,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NA,
        U_NA, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,               U_NU,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, U_NA,
                                         U_NA,    U_NA,    U_NA,       KC_BTN1, KC_BTN3, KC_BTN2
    ),

    /*
     * MEDIA: Media & Code Navigation
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │ BOOT │      │      │      │      │       │      │      │ Refs │      │      │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │ GUI  │ ALT  │ CTL  │ SFT  │      │       │ Caps │NavBk │GoDef │ Vol+ │NavFw │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │AltGr │      │      │      │       │      │      │      │      │      │      │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │      │      │      │       │ Stop │ Play │ Mute │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [MEDIA] = LAYOUT_split_3x6_3(
        U_NA, QK_BOOT, U_NA,    U_NA,    U_NA,    U_NA,               U_NA,    U_NA,    U_REF,   U_NA,    U_NA,    U_NA,
        U_NA, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,               KC_CAPS, U_NAB,   U_INC,   KC_VOLU, U_NAF,   U_NA,
        U_NA, U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,               U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NA,
                                         U_NA,    U_NA,    U_NA,       KC_MSTP, KC_MPLY, KC_MUTE
    ),

    /*
     * NUM: Numbers
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │  [   │  7   │  8   │  9   │  ]   │       │      │      │      │      │ BOOT │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │  ;   │  4   │  5   │  6   │  =   │       │      │ SFT  │ CTL  │ ALT  │ GUI  │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │  `   │  1   │  2   │  3   │  \   │       │      │      │      │AltGr │      │      │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │  .   │  0   │  -   │       │      │      │      │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [NUM] = LAYOUT_split_3x6_3(
        U_NA, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,            U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT, U_NA,
        U_NA, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,             U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_NA,
        U_NA, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,            U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,    U_NA,
                                         KC_DOT,  KC_0,    KC_MINS,    U_NA,    U_NA,    U_NA
    ),

    /*
     * SYM: Symbols
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │  {   │  &   │  *   │  (   │  }   │       │      │      │      │      │ BOOT │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │  :   │  $   │  %   │  ^   │  +   │       │      │ SFT  │ CTL  │ ALT  │ GUI  │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │  ~   │  !   │  @   │  #   │  |   │       │      │      │      │AltGr │      │      │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │  (   │  )   │  _   │       │      │      │      │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [SYM] = LAYOUT_split_3x6_3(
        U_NA, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,            U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT, U_NA,
        U_NA, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,            U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_NA,
        U_NA, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,            U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,    U_NA,
                                         KC_LPRN, KC_RPRN, KC_UNDS,    U_NA,    U_NA,    U_NA
    ),

    /*
     * FUN: Function Keys
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │ F12  │  F7  │  F8  │  F9  │PrtSc │       │      │      │      │      │ BOOT │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │ F11  │  F4  │  F5  │  F6  │ScrLk │       │      │ SFT  │ CTL  │ ALT  │ GUI  │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │ F10  │  F1  │  F2  │  F3  │Pause │       │      │      │      │AltGr │      │      │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │ App  │Space │ Tab  │       │      │      │      │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [FUN] = LAYOUT_split_3x6_3(
        U_NA, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,            U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT, U_NA,
        U_NA, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,            U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, U_NA,
        U_NA, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,            U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA,    U_NA,
                                         KC_APP,  KC_SPC,  KC_TAB,     U_NA,    U_NA,    U_NA
    ),

    /*
     * MISC: Git & Navigation
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │Stage │Unstag│      │      │      │       │      │      │      │      │      │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │      │      │      │      │       │      │      │      │      │      │      │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │      │      │      │      │       │      │      │      │      │      │      │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │NavBk │NavFw │      │       │      │      │      │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [MISC] = LAYOUT_split_3x6_3(
        U_NA, U_STG,   U_USG,   U_NA,    U_NA,    U_NA,               U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
        U_NA, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,               U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
        U_NA, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,               U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
                                         U_NAB,   U_NAF,   U_NA,       U_NA,    U_NA,    U_NA
    ),

    /*
     * DEBUG: Debugger Controls
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │StpOvr│StpIn │Resume│      │TglBrk│       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │      │ Refs │GoDef │      │       │TglBrk│StpOvr│StpIn │ Run  │ BASE │ BASE │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │StpOvr│StpIn │Resume│Reflsh│       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │NavBk │NavFw │NewTab│       │Build │ Run  │ Dbg  │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [DEBUG] = LAYOUT_split_3x6_3(
        U_NA, KC_F10,  KC_F11,  U_RSM,   U_NA,    U_TBP,              TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
        U_NA, U_NA,    U_NA,    U_REF,   U_INC,   U_NA,               U_TBP,    KC_F10,   KC_F11,   KC_F5,    TO(BASE), TO(BASE),
        U_NA, U_NA,    KC_F10,  KC_F11,  U_RSM,   U_RFS,              TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
                                         U_NAB,   U_NAF,   U_NTB,      U_BLD,    U_RUN,    U_DBG
    ),

    /*
     * CODE: Refactor & Quick Actions
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │      │      │      │      │      │       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │Rename│QkFix │CmpSug│C-R   │      │       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │NavBk │NavFw │NewTbW│Reflsh│       │NavFw │ BASE │ BASE │ BASE │ BASE │ BASE │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │UndoTb│ClsTb │ClsApp│       │NavBk │Vimium│VimAlt│
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [CODE] = LAYOUT_split_3x6_3(
        U_NA, U_NA,    U_NA,       U_NA,       U_NA,       U_NA,       TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
        U_NA, KC_F2,   C(KC_DOT), C(KC_SPC), C(KC_R),    U_NA,       TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
        U_NA, U_NA,    U_NAB,      U_NAF,      U_NTBW,     U_RFS,      U_NAF,    TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
                                               U_UCT,      U_CTB,   U_CLS,      U_NAB,    U_VBF,    U_VBFF
    ),

    /*
     * EDIT: Editing & Clipboard
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │      │      │      │      │      │       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │SelAll│AdvFnd│ Find │SrchFl│Replce│       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │ Copy │ Cut  │Paste │Commnt│Format│       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │ Undo │ Redo │ Save │       │SavAll│ BASE │ BASE │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [EDIT] = LAYOUT_split_3x6_3(
        U_NA, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,               TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
        U_NA, C(KC_A), U_AFD,   U_FND,   U_FIL,   U_RPLC,             TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
        U_NA, U_CPY,   U_CUT,   U_PST,   U_COM,   U_FOR,              TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
                                         U_UND,   U_RDO,   U_SAV,      U_SAVA,  TO(BASE), TO(BASE)
    ),

    /*
     * BROWSE: Browser & Tab Management
     * ┌──────┬──────┬──────┬──────┬──────┬──────┐       ┌──────┬──────┬──────┬──────┬──────┬──────┐
     * │      │      │NewTab│ClsTb │UndoTb│      │       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │Reflsh│NavBk │NavFw │      │       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * ├──────┼──────┼──────┼──────┼──────┼──────┤       ├──────┼──────┼──────┼──────┼──────┼──────┤
     * │      │      │      │      │      │      │       │ BASE │ BASE │ BASE │ BASE │ BASE │ BASE │
     * └──────┴──────┴──────┴──────┴──────┴──────┘       └──────┴──────┴──────┴──────┴──────┴──────┘
     *                      ┌──────┬──────┬──────┐       ┌──────┬──────┬──────┐
     *                      │      │      │Search│       │ BASE │ BASE │ BASE │
     *                      └──────┴──────┴──────┘       └──────┴──────┴──────┘
     */
    [BROWSE] = LAYOUT_split_3x6_3(
        U_NA, U_NA,    U_NTB,   U_CTB,   U_UCT,   U_NA,               TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
        U_NA, U_NA,    KC_F5,   U_NAB,   U_NAF,   U_NA,               TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
        U_NA, U_NA,    U_NA,    U_NA,    U_NA,    U_NA,               TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE), TO(BASE),
                                         U_NP,    U_NP,    U_SRC,      TO(BASE), TO(BASE), TO(BASE)
    )
};

// Unicode input mode can be changed at runtime with:
//   UC_WINC (Windows WinCompose)
//   UC_MAC  (macOS)
//   UC_LNX  (Linux)
// Default is set in config.h

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case U_SAVA:
            if (record->event.pressed) {
                uint8_t current_mode = get_unicode_input_mode();
                if (current_mode == UNICODE_MODE_MACOS) {
                    // macOS: Cmd+Option+S
                    register_code(KC_LGUI);
                    register_code(KC_LALT);
                    tap_code(KC_S);
                    unregister_code(KC_LALT);
                    unregister_code(KC_LGUI);
                } else {
                    // Windows/Linux: Ctrl+K then S (chord)
                    register_code(KC_LCTL);
                    tap_code(KC_K);
                    unregister_code(KC_LCTL);
                    tap_code(KC_S);
                }
            }
            return false;
    }
    return true;
}

