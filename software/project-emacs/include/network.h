#ifndef NETWORK_H
#define NETWORK_H

#include <WiFi.h>
#include <HTTPClient.h>


class Network
{
private:

public:
  bool init(String ssid, String password);
  unsigned int getBilibiliFans(String url);

};

#endif
