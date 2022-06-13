
//#include "Arduino.h"

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESP8266WebServer.h>
  #include <ESP8266HTTPUpdateServer.h>
#elif defined(ESP32)
  #include <WiFi.h>
  #include <WebServer.h>
  #include <HTTPUpdateServer.h>
#else
  #error "This ain't a ESP8266 or ESP32, dumbo!"
#endif

#include <DNSServer.h>
#include <Ticker.h>
#include "app.h"
#include "config.h"

app myApp;

//-----------------------------------------------------------------------------
void setup() {
    myApp.setup(WIFI_TRY_CONNECT_TIME);

    // TODO: move to HmRadio
    attachInterrupt(digitalPinToInterrupt(myApp.getIrqPin()), handleIntr, FALLING);
}


//-----------------------------------------------------------------------------
void loop() {
    myApp.loop();
}


//-----------------------------------------------------------------------------
ICACHE_RAM_ATTR void handleIntr(void) {
    myApp.handleIntr();
}
