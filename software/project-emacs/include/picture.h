#ifndef __PICTURE_H__
#define __PICTURE_H__

#define IMAGE_DIR   "images"
#define MAX_PICTURE_NUM   50
#define MAX_PICTURE_NAME_LEN   30

#include <Arduino.h>

class Picture {
 private:
  char picture_list[MAX_PICTURE_NUM][MAX_PICTURE_NAME_LEN];
  uint32_t picture_num = 0;
  uint32_t cur_index = 0;
 public:
  void init(void);
  char* getPrevPictureName(void);
  char* getNextPictureName(void);
};

extern Picture picture;

#endif
