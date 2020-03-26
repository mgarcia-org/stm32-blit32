# stm32-blit32
decoupling firmware from 32blit engine
Decoupling the firmware would open up SDL1/2 porting, which means more software ported to 32blit.


This is just a quick test to see if I can decouple the firmware from the 32blit engine
https://github.com/pimoroni/32blit-beta

Copy and paste the 32blit-stm32 folder and copy my Src and Inc file into them and my makefile.
It compiles, but doesn't build.. the lib or link


I'm guessing the makefile line 198:
```
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@
	$(SZ) $@
 ```
 
Converts to: 

cd build && arm-none-eabi-gcc *.o

The results is  alot of warnings:


warning: user_diskio.o uses 2-byte wchar_t yet the output is to use 4-byte wchar_t; use of wchar_t values across objects may fail



And link errors, two types:


1. _exit _write and _close etc I'm guessing it's not linking to a stdlib or something?


2. htim2 which is instanced in tim.c line 29, not sure why it's not 'linking'?



```
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/lib/libc.a(lib_a-exit.o): in function `exit':
exit.c:(.text.exit+0x2c): undefined reference to `_exit'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit.o: in function `blit_update_vibration':
32blit/32blit-beta/C-stm32/Src/32blit.c:583: undefined reference to `htim4'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit.o: in function `blit_update_led':
32blit/32blit-beta/C-stm32/Src/32blit.c:600: undefined reference to `htim3'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/32blit.c:600: undefined reference to `htim15'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit.o: in function `HAL_TIM_PeriodElapsedCallback':
32blit/32blit-beta/C-stm32/Src/32blit.c:630: undefined reference to `htim2'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit.o: in function `HAL_GPIO_EXTI_Callback':
32blit/32blit-beta/C-stm32/Src/32blit.c:654: undefined reference to `blit_menu'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/32blit.c:660: undefined reference to `htim2'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit.o: in function `blit_switch_execution':
32blit/32blit-beta/C-stm32/Src/32blit.c:809: undefined reference to `USBD_Stop'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/32blit.c:825: undefined reference to `qspi_enable_memorymapped_mode'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/32blit.c:844: undefined reference to `htim2'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/32blit.c:844: undefined reference to `hUsbDeviceHS'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: fatfs_sd.o: in function `SPI_TxBuffer':
32blit/32blit-beta/C-stm32/Src/fatfs_sd.c:43: undefined reference to `hspi1'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: fatfs_sd.o: in function `SPI_TxByte':
32blit/32blit-beta/C-stm32/Src/fatfs_sd.c:36: undefined reference to `hspi1'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: fatfs_sd.o: in function `SPI_RxByte':
32blit/32blit-beta/C-stm32/Src/fatfs_sd.c:55: undefined reference to `hspi1'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: main.o: in function `main':
32blit/32blit-beta/C-stm32/Src/main.c:131: undefined reference to `MX_TIM2_Init'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/main.c:132: undefined reference to `MX_TIM4_Init'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/main.c:133: undefined reference to `MX_TIM3_Init'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/main.c:143: undefined reference to `MX_SPI1_Init'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/main.c:144: undefined reference to `MX_SPI4_Init'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/main.c:146: undefined reference to `MX_TIM15_Init'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/main.c:148: undefined reference to `MX_RNG_Init'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/main.c:149: undefined reference to `MX_USB_DEVICE_Init'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/main.c:150: undefined reference to `MX_JPEG_Init'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: startup_stm32h750xx.o:(.text+0x0): undefined reference to `_sidata'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: startup_stm32h750xx.o:(.text+0x4): undefined reference to `_sdata'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: startup_stm32h750xx.o:(.text+0xc): undefined reference to `_sbss'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: startup_stm32h750xx.o:(.text+0x10): undefined reference to `_ebss'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: startup_stm32h750xx.o: in function `RegularBoot':
32blit/32blit-beta/C-stm32/startup_stm32h750xx.s:62: undefined reference to `_estack'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/startup_stm32h750xx.s:70: undefined reference to `_sidata'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/startup_stm32h750xx.s:76: undefined reference to `_sdata'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/startup_stm32h750xx.s:86: undefined reference to `itcm_data'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/startup_stm32h750xx.s:92: undefined reference to `itcm_text_start'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/startup_stm32h750xx.s:93: undefined reference to `itcm_text_end'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/startup_stm32h750xx.s:98: undefined reference to `_sbss'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/startup_stm32h750xx.s:106: undefined reference to `_ebss'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: startup_stm32h750xx.o:(.isr_vector+0x0): undefined reference to `_estack'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: stm32h7xx_it.o: in function `OTG_HS_IRQHandler':
32blit/32blit-beta/C-stm32/Src/stm32h7xx_it.c:277: undefined reference to `HAL_PCD_IRQHandler'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/32blit-beta/C-stm32/Src/stm32h7xx_it.c:281: undefined reference to `hpcd_USB_OTG_HS'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: stm32h7xx_it.o: in function `TIM2_IRQHandler':
32blit/32blit-beta/C-stm32/Src/stm32h7xx_it.c:310: undefined reference to `htim2'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/lib/libc.a(lib_a-sbrkr.o): in function `_sbrk_r':
sbrkr.c:(.text._sbrk_r+0x18): undefined reference to `_sbrk'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/lib/libc.a(lib_a-writer.o): in function `_write_r':
writer.c:(.text._write_r+0x24): undefined reference to `_write'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/lib/libc.a(lib_a-closer.o): in function `_close_r':
closer.c:(.text._close_r+0x18): undefined reference to `_close'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/lib/libc.a(lib_a-fstatr.o): in function `_fstat_r':
fstatr.c:(.text._fstat_r+0x20): undefined reference to `_fstat'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/lib/libc.a(lib_a-isattyr.o): in function `_isatty_r':
isattyr.c:(.text._isatty_r+0x18): undefined reference to `_isatty'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/lib/libc.a(lib_a-lseekr.o): in function `_lseek_r':
lseekr.c:(.text._lseek_r+0x24): undefined reference to `_lseek'
32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/bin/ld: 32blit/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/../../../../arm-none-eabi/lib/libc.a(lib_a-readr.o): in function `_read_r':
readr.c:(.text._read_r+0x24): undefined reference to `_read'
```
