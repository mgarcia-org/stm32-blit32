// *****************     GLOBALS  VARS    *****************

#ifdef INSTANCE_EXTERN_VARS_HERE
#define INSTANCE
#else
#define INSTANCE extern
#endif
void init_gpio(void);
void init_disp(void);
void init_sound(void);


  struct LED {
	  unsigned char r ;
	  unsigned char g ;
	  unsigned char b ;
	  unsigned char a ;
  };


  struct VEC3 {
    float x;
    float y;
    float z;
  };

  struct VEC2 {
      float x;
      float y;
    };

//sound.c
INSTANCE unsigned short g_audio_frame; // see audio.cpp   uint16_t get_audio_frame()

// display.c
INSTANCE unsigned char   g_surface_data[320][240]; // hi res
INSTANCE char g_needs_render;


INSTANCE unsigned int g_buttons;
INSTANCE float g_hack_left;
INSTANCE float g_hack_right;
INSTANCE float g_vibration;
INSTANCE struct VEC2 g_joystick;
INSTANCE struct VEC3 g_tilt;
INSTANCE struct LED g_LED;
