#pragma once

#if !defined(KEYBOARD_LAYOUT_LANG)
  #error This keyboard layout language is not defined.
#endif

enum KeyModifier: uint8_t {
  none = 0,
  leftCtrl = 1,
  leftShift = 2,
  leftAlt = 4,
  leftWindows = 8,
  altGr = 64, // it seems that altGr cannot be replaced with Ctrl+Alt for Linux hosts: see Issue#1
};

KeyModifier operator| (KeyModifier lhs,KeyModifier rhs) {
  return static_cast<KeyModifier>( static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs) );
}

KeyModifier operator& (KeyModifier lhs,KeyModifier rhs) {
  return static_cast<KeyModifier>( static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs) );
}

class Akuhell {
public:
  inline size_t write(KeyboardKeycode k, KeyModifier modifier);
  inline size_t convertUtf8CharacterToKeycode(const String & ch, KeyboardKeycode & k, KeyModifier & modifier);
  inline void writeUtf8Character(const String & ch);
  inline void writeUtf8String(const String & str);
};

class Utf8 {
public:
  inline int charLen(byte firstByte);
  inline int strLen(const String & str);
  inline String charAt(const String & str, int index);
};
