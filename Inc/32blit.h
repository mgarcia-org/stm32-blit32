#undef UNUSED
#define UNUSED(x) ((void)(__typeof__(x))(x)) // suppress "UNUSED" warnings
#include <stdbool.h>
//#include "32blit.hpp"
#include "fatfs.h"
#include "persistence.h"
#include "externs.h"
#include "gpio_defs.h"

#define TRUE 1
#define FALSE 0

enum  {
    DPAD_LEFT = 1,
    DPAD_RIGHT = 2,
    DPAD_UP = 4,
    DPAD_DOWN = 8,
    A = 16,
    B = 32,
    X = 64,
    Y = 128,
    MENU = 256,
    HOME = 512,
    JOYSTICK = 1024
  };


// Functions defined by user code files
extern void init();
extern void update(uint32_t time);
extern void render(uint32_t time);

// SD storage
extern char *get_fr_err_text(FRESULT err);
extern char blit_sd_detected();

// LTDC and framebuffer handling
extern char __ltdc_start;
extern void blit_swap();
extern void blit_flip();
//extern blit::Surface &set_screen_mode(blit::ScreenMode new_mode);
//extern blit::Surface &set_screen_mode(blit::ScreenMode new_mode);
extern void blit_clear_framebuffer();

// Blit setup and main loop
extern void blit_tick();
extern void blit_init();

// IO
extern void blit_update_vibration();
extern void blit_update_led();
extern void blit_process_input();
extern void blit_i2c_tick();

// Audio
extern void blit_enable_amp();

// Switching execution
extern void blit_switch_execution(void);

void blit_menu_update(uint32_t time);
void blit_menu_render(uint32_t time);
void blit_menu();

extern void blit_enable_ADC();
extern void blit_disable_ADC();
