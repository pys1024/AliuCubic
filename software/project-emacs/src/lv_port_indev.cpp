/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include <Arduino.h>
#include "lv_port_indev.h"
#include "lv_cubic_gui.h"
#include "picture.h"

static void encoder_init(void);
static void encoder_read(lv_indev_drv_t* indev_drv, lv_indev_data_t* data);
static void encoder_handler(void);


lv_indev_t* indev_encoder;

void lv_port_indev_init(void)
{
  /* Here you will find example implementation of input devices supported by LittelvGL:
   *  - Touchpad
   *  - Mouse (with cursor support)
   *  - Keypad (supports GUI usage only with key)
   *  - Encoder (supports GUI usage only with: left, right, push)
   *  - Button (external buttons to press points on the screen)
   *
   *  The `..._read()` function are only examples.
   *  You should shape them according to your hardware
   */


  static lv_indev_drv_t indev_drv;


  /*------------------
   * Encoder
   * -----------------*/

  /*Initialize your encoder if you have*/
  encoder_init();

  /*Register a encoder input device*/
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_ENCODER;
  indev_drv.read_cb = encoder_read;
  indev_encoder = lv_indev_drv_register(&indev_drv);

  /* Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
   * add objects to the group with `lv_group_add_obj(group, obj)`
   * and assign this input device to group to navigate in it:
   * `lv_indev_set_group(indev_encoder, group);` */


}

/**********************
 *   STATIC FUNCTIONS
 **********************/


/*------------------
 * Encoder
 * -----------------*/

/* Initialize your keypad */
static void encoder_init(void)
{
  /*Your code comes here*/
  pinMode (TOUCH0, INPUT);
  pinMode (TOUCH1, INPUT);
}

/* Will be called by the library to read the encoder */
static void encoder_read(lv_indev_drv_t* indev_drv, lv_indev_data_t* data)
{
  static int flag = 0;

  int t0 = digitalRead(TOUCH0);
  int t1 = digitalRead(TOUCH1);

  data->enc_diff = 0;
  data->state = LV_INDEV_STATE_REL;

  if (!flag) {
    if (t0) {
      data->enc_diff = 1;
      digitalWrite (25, LOW);
      Serial.println("# 11111111111111111");
      lv_img_set_src(img, picture.getPrevPictureName());
    } else if (t1) {
      data->enc_diff = -1;
      digitalWrite (33, LOW);
      Serial.println("# 22222222222222222");
      lv_img_set_src(img, picture.getNextPictureName());
    }
    flag = 1;
  } else if (!t0 && !t1){
    digitalWrite (25, HIGH);
    digitalWrite (33, HIGH);
    flag = 0;
  }

}

/*Call this function in an interrupt to process encoder events (turn, press)*/
static void encoder_handler(void)
{
  /*Your code comes here*/
}

