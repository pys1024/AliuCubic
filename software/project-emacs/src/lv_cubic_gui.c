/*********************
 *      INCLUDES
 *********************/
#include "lv_cubic_gui.h"
#include "images.h"

lv_obj_t* img;

void lv_holo_cubic_gui(void)
{
  static lv_style_t default_style, pressed_style, focused_style,
    pressed_focus_style;
  lv_style_init(&default_style);
  lv_style_init(&pressed_style);
  lv_style_init(&focused_style);
  lv_style_init(&pressed_focus_style);

  lv_style_set_bg_color(&default_style, lv_color_black());
  lv_style_set_bg_color(&pressed_style, lv_color_make(0x80, 0x80, 0x80));
  lv_style_set_bg_color(&focused_style, lv_color_black());
  lv_style_set_bg_color(&pressed_focus_style, lv_color_hex(0xf88));

  lv_obj_add_style(lv_scr_act(), &default_style, LV_PART_MAIN|LV_STATE_DEFAULT);
  lv_obj_add_style(lv_scr_act(), &pressed_style, LV_PART_MAIN|LV_STATE_PRESSED);
  lv_obj_add_style(lv_scr_act(), &focused_style, LV_PART_MAIN|LV_STATE_FOCUSED);
  lv_obj_add_style(lv_scr_act(), &pressed_focus_style,
                   LV_PART_MAIN|LV_STATE_PRESSED|LV_STATE_FOCUSED);

  img = lv_img_create(lv_scr_act());
  /* lv_img_set_src(img, &logo); */
  lv_img_set_src(img, "S:/images/image1.bin");
  lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
  /* lv_scr_load_anim(lv_scr_act(), LV_SCR_LOAD_ANIM_NONE, 0, 0, false); */
}
