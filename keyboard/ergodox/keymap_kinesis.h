#include "action_util.h"
#include "action_layer.h"
#define KC_SW0 KC_FN0
#define DEBUG_ACTION

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* TODO
       - L1 push goes to wrong layer (mouse instead of characters)
       - ~L2 stays in mouse layer
    */

    /* Keymap 0: Base Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  | ESC  |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   =    |   Q  |   W  |   E  |   R  |   T  |  Up  |           |  L0  |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  Tab   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
     * |--------+------+------+------+------+------|  Dn  |           |  L1  |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShitf |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LGui | RIGHT| LEFT | ~L1  |  ~L2 |                                       | ~L2  | ~L1  |   [  |   ]  | RGui |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |C+A+<-| Home |       | PgUp |C+A+->|
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | End  |       | PgDn |      |      |
     *                                 | Bkspc| Del  |------|       |------| Enter| Space|
     *                                 | /Ctrl|/Alt  | Ctl+A|       |AltTab| /Ctrl|      |
     *                                 `--------------------'       `--------------------'
     */


    // Base QWERTY Layer

    KEYMAP(
           GRV,  1,    2,    3,    4,    5, ESC,
           EQL,  Q,    W,    E,    R,    T, UP,
           TAB,  A,    S,    D,    F,    G,
           LSFT, Z,    X,    C,    V,    B, DOWN,
           LGUI, LEFT, RGHT, FN10, FN1,

                                           FN4,  HOME,
                                                 END,
                                      FN8, FN6,  FN30,
           //RIGHT
           TRNS, 6,    7,    8,    9,    0,    MINS,
           NO,   Y,    U,    I,    O,    P,    BSLS,
                 H,    J,    K,    L,    SCLN, QUOT,
           FN2,  N,    M,    COMM, DOT,  SLSH, RSFT,
                       FN1,  FN10, LBRC, RBRC, RGUI,
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
                 FN25, FN26, FN20, FN21, FN27, TRNS,
           TRNS,  FN17, FN18, FN28, FN29, SCLN, TRNS,
                       TRNS, TRNS, TRNS, TRNS, TRNS,
           TRNS, TRNS,
           TRNS,
           TRNS, TRNS, TRNS
    ),
    KEYMAP(  // Layer2: Mouse Left/ Arrows Right
        // left hand
           FN0,   NO,   BTN1, BTN2, BTN3, NO,   TRNS,
           NO,    NO,   WH_U, MS_U, WH_D, NO,   NO,
           NO,    NO,   MS_L, MS_D, MS_R, NO,
           NO,    NO,   BTN1, BTN2, BTN3, NO,   NO,
           NO,    NO,   NO,   NO,   NO,
                                               NO,   NO,
                                                     NO,
                                         BTN1, BTN2, BTN3,
        // right hand
           NO,   NO,   BTN1, BTN2, BTN3, NO,   NO,
           TRNS,  INS,  HOME, UP,   PGUP, NO,   NO,
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
    TEENSY_KEY,
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
    ACTION_MODS_KEY(MOD_LSFT, KC_1),                // FN12 - !
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
    ACTION_MODS_KEY(MOD_LSFT, KC_DOT),              // FN26 - >
    ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),             // FN27 - :
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
