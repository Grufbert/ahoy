//-----------------------------------------------------------------------------
// 2022 Ahoy, https://www.mikrocontroller.net/topic/525778
// Creative Commons - http://creativecommons.org/licenses/by-nc-sa/3.0/de/
//-----------------------------------------------------------------------------

#if defined(ESP8266)
  #include "Arduino.h"
  #include <ESP8266WiFi.h>
  #include <ESP8266WebServer.h>
  #include <ESP8266HTTPUpdateServer.h>
#elif defined(ESP32)
  #include <WiFi.h>
  #include <WebServer.h>
  #include <HTTPUpdateServer.h>
#else
  #error "This ain't a ESP8266 or ESP32"
#endif


#include <DNSServer.h>
#include <Ticker.h>
#include "app.h"
#include "config.h"
#include "EEPROM.h"

#include <esp_task_wdt.h>

app myApp;

//-----------------------------------------------------------------------------
void setup() {
    // TODO NEED TO BE HERE FOR ESP32
    bool success = EEPROM.begin(1000);
    if(!success)
        DPRINTLN(F("eep.h:begin error"));
    else
        DPRINTLN(F("eep.h:begin success"));

    myApp.setup(WIFI_TRY_CONNECT_TIME);

    // TODO: move to HmRadio
    attachInterrupt(digitalPinToInterrupt(myApp.getIrqPin()), handleIntr, FALLING);

    esp_task_wdt_init(10, false);
}


//-----------------------------------------------------------------------------
void loop() {
    myApp.loop();
    esp_task_wdt_reset();
}


//-----------------------------------------------------------------------------
ICACHE_RAM_ATTR void handleIntr(void) {
    myApp.handleIntr();
}
