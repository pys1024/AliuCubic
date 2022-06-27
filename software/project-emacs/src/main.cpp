#include <Arduino.h>
#include "display.h"
#include "network.h"
#include "sd_card.h"
#include "lv_port_indev.h"
#include "lv_port_fs.h"
#include "lv_cubic_gui.h"
#include "picture.h"

/*** Component objects ***/
Display screen;
SdCard tf;
Network wifi;

// lv_ui guider_ui;

int LED0 = 25;
int LED1 = 33;

void setup() {
  Serial.begin(115200);

  /*** Init screen ***/
  screen.init();
  screen.setBackLight(0.9);

  /*** Init TOUCH PAD as input device ***/
  lv_port_indev_init();

  /*** Init on-board LED ***/
  pinMode (LED0, OUTPUT);
  pinMode (LED1, OUTPUT);
  digitalWrite (LED0, LOW);
  digitalWrite (LED1, LOW);

  String ssid = "Aliu-2.4g";
  String password = "Aliu102426";
  /*** Init micro SD-Card ***/
  if (!tf.init()) {
    Serial.println("TF card init failed");
    return;
  }
  picture.init();
  lv_port_fs_init();

  ssid = tf.readFileLine("/wifi.txt", 1);        // line-1 for WiFi ssid
  password = tf.readFileLine("/wifi.txt", 2);    // line-2 for WiFi password
  Serial.print("wifi info: ");
  Serial.print(ssid.c_str());
  Serial.print(" @");
  Serial.println(password.c_str());

  /*** Inflate GUI objects ***/
  lv_holo_cubic_gui();
  //    setup_ui(&guider_ui);

  /*** Read WiFi info from SD-Card, then scan & connect WiFi ***/
#if 0
  if (!wifi.init(ssid, password)) {
    Serial.println("Wifi init failed");
    return;
  }

  // Change to your BiliBili UID
  Serial.println(wifi.getBilibiliFans("20259914"));
#endif
  digitalWrite (LED0, HIGH);
  digitalWrite (LED1, HIGH);
}

// int frame_id = 0;
// char buf[100];

void loop() {
  // run this as often as possible
  screen.routine();
}
