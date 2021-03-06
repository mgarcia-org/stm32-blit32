/*
In combination with a reserved section in volatile memory this struct provies 1k
of "persistent" storage in volatile RAM.

This storage is reserved for 32blit firmware level use, and will survive resets,
switches into bootloader mode and jumps between internal/external flash.

This storage will not survive a loss of power.
*/
#pragma once
//#include <stddef.h>
//#include <unitypes.h>

typedef enum {prtFirmware, prtGame} PersistResetTarget;

struct Persist {
  unsigned int magic_word;
  float volume;
  float backlight;
  unsigned int selected_menu_item;
  PersistResetTarget reset_target;
};

extern struct Persist persist;

// This magic word lets us know our persistent values are valid
// and not just random uninitialised memory.
// constexpr uint32_t persistence_magic_word = 0x03281170;
extern unsigned int persistence_magic_word;
