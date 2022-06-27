#ifndef DISPLAY_H
#define DISPLAY_H

#include <lvgl.h>

#define LCD_BL_PIN 5
#define LCD_BL_PWM_CHANNEL 0
#define MY_DISP_HOR_RES 240
#define MY_DISP_VER_RES 240


class Display
{
private:


public:
  void init();
  void routine();
  void setBackLight(float);
};

#endif
