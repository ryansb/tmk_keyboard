#include "action_util.h"
#include "action_layer.h"
#define KC_SW0 KC_FN0
#define DEBUG_ACTION

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap 0: Base Layer
     *
     * ,--------------------------------------------------.         ,----------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  | ESC  |         |   -    |   6  |   7  |   8  |   9  |   0  |¯\_ツ_/¯|
     * |--------+------+------+------+------+-------------|         |--------+------+------+------+------+------+--------|
     * |   =    |   Q  |   W  |   D  |   F  |   K  |   (  |         |   )    |   J  |   U  |   R  |   L  |   ;  |   \    |
     * |--------+------+------+------+------+------|      |         |        |------+------+------+------+------+--------|
     * |  Tab   |   A  |   S  |   E  |   T  |   G  |------|         |--------|   Y  |   N  |   I  |   O  |   H  |   '    |
     * |--------+------+------+------+------+------|   [  |         |   ]    |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |         |        |   P  |   M  |   ,  |   .  |   /  | ~L1    |
     * `--------+------+------+------+------+-------------'         `---------------+------+------+------+------+--------'
     *   | LGui |      |      |      | Space|                                       | RGHT | DOWN |  UP  | LEFT | ~L2  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |C+A+<-| Home |       | PgUp |C+A+->|
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | End  |       | PgDn |      |      |
     *                                 | Bkspc| Del  |------|       |------| Enter| Space|
     *                                 | /Ctrl|/Alt  | Ctl+A|       |AltTab| /Ctrl|      |
     *                                 `--------------------'       `--------------------'
     *
     * Keymap 1: Symbols and misc
     *
     * ,--------------------------------------------------.         ,----------------------------------------------------.
     * |        |      |      |      |      |      |      |         |        |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|         |--------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |         |        |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |         |        |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|         |--------|      |      |      |      |FLIPTB|        |
     * |--------+------+------+------+------+------|      |         |        |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |         |        |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'         `---------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     * Keymap 2: FN keys
     *
     * ,--------------------------------------------------.         ,----------------------------------------------------.
     * |        |      |      |      |      |      |      |         |        |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|         |--------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |         |        |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |         |        |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|         |--------|      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |         |        |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |         |        |      |      |      |      |      |        |
     * `--------+------+------+------+------+-------------'         `---------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */


    // Base QWERTY Layer

    KEYMAP(
           GRV,  1,    2,    3,    4,    5, ESC,
           EQL,  Q,    W,    D,    F,    K, FN20,
           TAB,  A,    S,    E,    T,    G,
           LSFT, Z,    X,    C,    V,    B, LBRC,
           LGUI, TRNS, TRNS, TRNS, SPC,

                                           FN4,  HOME,
                                                 END,
                                      FN8, FN6,  FN30,
           //RIGHT
           MINS, 6,    7,    8,    9,    0,    FN27,
           FN21, J,    U,    R,    L,    SCLN, BSLS,
                 Y,    N,    I,    O,    H,    QUOT,
           RBRC, P,    M,    COMM, DOT,  SLSH, FN1,
                       LEFT, DOWN, UP,   RGHT, RGUI,
           PGUP, FN5,
           PGDN,
           FN31, FN7, SPC
           ),

    // SYMBOLS
    KEYMAP(
           FN0,  F1,   F2,   F3,   F4,   F5,   ESC,
           TRNS, MINS, EQL,  PPLS, PAST, SLSH, TRNS,
           FN22, GRV,  QUOT, FN11, DOT,  COMM,
           TRNS, FN12, FN13, FN14, FN15, FN16, TRNS,
           TRNS, TRNS, TRNS, TRNS, TRNS,

                                               TRNS, TRNS,
                                                     TRNS,
                                         TRNS, TRNS, TRNS,
        // right hand
           F12, F6,   F7,   F8,   F9,   F10,   F11,
           FN3,  FN23, FN24, LBRC, RBRC, BSLS, F12,
                 FN25, FN26, FN20, FN21, TRNS, TRNS,
           TRNS,  FN17, FN18, FN28, FN29, FN26, TRNS,
                       TRNS, TRNS, TRNS, TRNS, TRNS,
           TRNS, TRNS,
           TRNS,
           TRNS, TRNS, TRNS
    ),
    KEYMAP(  // Layer2: Mouse Left/ Arrows Right
        // left hand
           FN0,   NO,   NO,   NO,   NO,   NO, NO,
           NO,    NO,   WH_U, MS_U, WH_D, NO, NO,
           NO,    NO,   MS_L, MS_D, MS_R, NO,
           NO,    NO,   BTN1, BTN2, BTN3, NO, NO,
           NO,    NO,   NO,   NO,   NO,
                                              NO,   NO,
                                                    NO,
                                        BTN1, BTN2, BTN3,
        // right hand
           NO,   NO,   BTN1, BTN2, BTN3, NO,   NO,
           TRNS, INS,  HOME, UP,   PGUP, NO,   NO,
                 DEL,  LEFT, DOWN, RGHT, NO,   NO,
           NO,   NO,   END,  DOWN, PGDN, NO,   NO,
                       TRNS, TRNS, NO,   NO,   NO,
           NO,   NO,
           NO,
           NO,   TRNS,   NO
    ),

    /* KEYMAP(  // LayerN: fully transparent */
    /*     // left hand */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*                                            TRNS, TRNS,  */
    /*                                                  TRNS,  */
    /*                                      TRNS, TRNS, TRNS, */
    /*     // right hand */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*              TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*                    TRNS, TRNS, TRNS, TRNS, TRNS,  */
    /*        TRNS, TRNS,  */
    /*        TRNS,  */
    /*        TRNS, TRNS, TRNS */
    /* ), */


    // BASE LAYERS

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY
};

enum macro_id {
    MACRO_SHRUG,
    MACRO_REQUAL,
    MACRO_FLIP,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key
    ACTION_LAYER_MOMENTARY(2),                      // FN1 - Momentary L2
    ACTION_LAYER_ON(1, ON_RELEASE),                 // FN2 - Layer 1 ON
    ACTION_LAYER_OFF(1, ON_RELEASE),                // FN3 - Layer 1 OFF
    ACTION_MODS_KEY(MOD_LCTL | MOD_LALT, KC_LEFT),  // FN4 - Ctrl+Alt+left
    ACTION_MODS_KEY(MOD_LCTL | MOD_LALT, KC_RIGHT), // FN5 - Ctrl+Alt+right
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_DEL),          // FN6 - delete/alt tap combo
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_ENT),          // FN7 - enter/l-ctrl tap combo
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_BSPC),         // FN8 - backspace/l-ctrl tap combo
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),          // FN9 - Control/esc on tap
    ACTION_LAYER_MOMENTARY(1),                      // FN10 - Momentary Layer 1

    // SYMBOLS
    ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),             // FN11 - "
    ACTION_MACRO(MACRO_REQUAL),                     // FN12 - <-
    ACTION_MODS_KEY(MOD_LSFT, KC_2),                // FN13 - @
    ACTION_MODS_KEY(MOD_LSFT, KC_3),                // FN14 - #
    ACTION_MODS_KEY(MOD_LSFT, KC_4),                // FN15 - $
    ACTION_MODS_KEY(MOD_LSFT, KC_5),                // FN16 - %
    ACTION_MODS_KEY(MOD_LSFT, KC_6),                // FN17 - ^
    ACTION_MODS_KEY(MOD_LSFT, KC_7),                // FN18 - &
    ACTION_MODS_KEY(MOD_LSFT, KC_8),                // FN19 - *
    ACTION_MODS_KEY(MOD_LSFT, KC_9),                // FN20 - (
    ACTION_MODS_KEY(MOD_LSFT, KC_0),                // FN21 - )
    ACTION_MODS_KEY(MOD_LSFT, KC_GRV),              // FN22 - ~
    ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),             // FN23 - |
    ACTION_MODS_KEY(MOD_LSFT, KC_MINS),             // FN24 - _
    ACTION_MODS_KEY(MOD_LSFT, KC_COMM),             // FN25 - <
    ACTION_MACRO(MACRO_FLIP),                       // FN26 - (╯°□°)╯︵┻━┻
    ACTION_MACRO(MACRO_SHRUG),                      // FN27 - ¯\_ツ_/¯
    ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),             // FN28 - {
    ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),             // FN29 - }

    // MULTIKEY
    ACTION_MODS_KEY(MOD_LCTL, KC_A),                 // FN30
    ACTION_MODS_KEY(MOD_LALT, KC_TAB),               // FN31
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;

    if (event.pressed) {
        switch (id) {
        case MACRO_SHRUG:
            //return MACRO( D(LSFT), T(H), U(LSFT), T(E), D(L), U(L), D(L), U(L), D(O), U(O), D(DOT), U(DOT), D(W), U(W), D(O), U(O), D(R), U(R), D(L), U(L), D(D), U(D), D(ENTER), U(ENTER), END); // types "Hello.world{ENTER}"
            return MACRO(
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    // left hand // ¯
                    T(X),
                    T(A),
                    T(F), T(ENTER),
                    // backslash
                    T(BSLS),
                    // underscore
                    D(LSFT),
                    T(MINS),
                    U(LSFT),
                    // ツ
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    T(3),
                    T(0),
                    T(C),
                    T(4), T(ENTER),
                    // underscore
                    D(LSFT),
                    T(MINS),
                    U(LSFT),
                    // slash /
                    T(SLSH),
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    // right hand // ¯
                    T(X),
                    T(A),
                    T(F), T(ENTER),
                    END);
        case MACRO_REQUAL:
            return MACRO(
                    D(LSFT), T(COMM), U(LSFT),
                    T(MINS),
                    END);
        case MACRO_FLIP:
            return MACRO(
                    D(LSFT), T(9), U(LSFT),
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    // left hand // ╯
                    T(2),
                    T(5),
                    T(6),
                    T(F), T(ENTER),
                    // left eye // °
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    T(B),
                    T(0), T(ENTER),
                    // mouth // □
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    T(2),
                    T(5),
                    T(A),
                    T(1), T(ENTER),
                    // right eye // °
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    T(B),
                    T(0), T(ENTER),
                    D(LSFT), T(0), U(LSFT),
                    // right hand // ╯
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    T(2),
                    T(5),
                    T(6),
                    T(F), T(ENTER),
                    // flip arc // ︵
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    T(F),
                    T(E),
                    T(3),
                    T(5), T(ENTER),
                    // table leg 1 // ┻
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    T(2),
                    T(5),
                    T(3),
                    T(B), T(ENTER),
                    // table body // ━
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    T(2),
                    T(5),
                    T(0),
                    T(1), T(ENTER),
                    // table leg 2 // ┻
                    D(LCTL), D(LSFT), T(U), U(LSFT), U(LCTL),
                    T(2),
                    T(5),
                    T(3),
                    T(B), T(ENTER),
                    END);
        }
    }
    return MACRO_NONE;
}
