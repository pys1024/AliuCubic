
/**
 * @file lv_port_indev_templ.h
 *
 */

/*Copy this file as "lv_port_indev.h" and set this value to "1" to enable content*/


#ifndef LV_PORT_INDEV_TEMPL_H
#define LV_PORT_INDEV_TEMPL_H

#define TOUCH0 32
#define TOUCH1 35

#ifdef __cplusplus
extern "C" {
#endif

  /*********************
   *      INCLUDES
   *********************/

  extern lv_indev_t* indev_encoder;

  void lv_port_indev_init(void);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_PORT_INDEV_TEMPL_H*/


