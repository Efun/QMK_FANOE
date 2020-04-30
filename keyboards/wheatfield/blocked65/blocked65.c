#include "blocked65.h"

__attribute__ ((weak))
void matrix_init_keymap(void) {}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
__attribute__ ((weak))
uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}
__attribute__ ((weak))
void led_set_keymap(uint8_t usb_led) {}

__attribute__ ((weak))
void action_function_keymap(keyrecord_t *record, uint8_t id, uint8_t opt) {}

void matrix_init_user(void) {
  matrix_init_keymap();
}

void matrix_scan_user(void) {
  matrix_scan_keymap();
}

void action_function_user(keyrecord_t *record, uint8_t id, uint8_t opt) {
  action_function_keymap(record, id, opt);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool caps_toggle;

  switch (keycode) {
  case KC_CAPS:
    if (!record->event.pressed) { caps_toggle = !caps_toggle; }
    if (caps_toggle) {
      rgblight_setrgb(0xFF, 0x00, 0x00);
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    } else {
      rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
    }
    break;
  default:
    break;
  }

  return process_record_keymap(keycode, record);
}

void led_set_user(uint8_t usb_led) {
  led_set_keymap(usb_led);
}
