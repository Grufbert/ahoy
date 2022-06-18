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

#if ESP32
#include <esp_task_wdt.h>
#endif

app myApp;

//-----------------------------------------------------------------------------
void setup() {
    #if ESP32
    EEPROM.begin(1000);
    esp_task_wdt_init(10, false); //disable watchtdog
    #endif

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
