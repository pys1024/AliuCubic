#include "picture.h"
#include <lvgl.h>
#include <SD.h>


Picture picture;

void Picture::init() {
  File iroot = SD.open("/" IMAGE_DIR);
  if (!iroot) {
    Serial.println("Failed to open directory: /" IMAGE_DIR);
    return;
  }
  if (!iroot.isDirectory()) {
    Serial.println("/" IMAGE_DIR " is not a diretory.");
    return;
  }

  cur_index = 0;
  picture_num = 0;
  String path_prefix = "S:";
  while (true) {
    File image = iroot.openNextFile();
    if (!image) {
      return;
    } else if (!image.isDirectory()) {
      memset(this->picture_list[picture_num], 0, MAX_PICTURE_NAME_LEN);
      strcpy(this->picture_list[picture_num], path_prefix.c_str());
      strcpy(this->picture_list[picture_num] + path_prefix.length(), image.name());

      Serial.printf("# IMAGE: %s\n", this->picture_list[picture_num]);
      Serial.printf("# SIZE: %d\n", image.size());

      picture_num++;
    }
  }
}

char* Picture::getPrevPictureName() {
  if (cur_index == 0) {
    cur_index = picture_num - 1;
  } else {
    cur_index--;
  }
  return this->picture_list[cur_index];
}

char* Picture::getNextPictureName() {
  if (cur_index >= picture_num - 1) {
    cur_index = 0;
  } else {
    cur_index++;
  }
  return this->picture_list[cur_index];
}
