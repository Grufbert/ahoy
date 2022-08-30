#ifndef __SETUP_HTML_H__
#define __SETUP_HTML_H__
const char setup_html[] PROGMEM = "<!doctype html><html><head><title>Setup - {DEVICE}</title><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"/><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><script type=\"text/javascript\">function toggle(name, hide) {var elm = document.getElementsByName(name)[0];if(hide) {if(!elm.classList.contains(\"hide\"))                        elm.classList.add(\"hide\");}else                    elm.classList.remove('hide');}function load() {document.querySelectorAll('input[name^=\"inv\"][name$=\"Addr\"]').forEach(elm =>{elm.addEventListener(\"keyup\", (e) =>{serial = elm.value.substring(0,4);iv = elm.name.substring(3,4);max = 0;for(i=0;i<4;i++) {toggle(\"inv\"+iv+\"ModPwr\"+i, true);toggle(\"inv\"+iv+\"ModName\"+i, true);}toggle(\"lbl\"+iv+\"ModPwr\", true);toggle(\"lbl\"+iv+\"ModName\", true);if(serial == \"1161\") max = 4;else if(serial == \"1141\") max = 2;else if(serial == \"1121\") max = 1;for(i=0;i<max;i++) {toggle(\"inv\"+iv+\"ModPwr\"+i, false);toggle(\"inv\"+iv+\"ModName\"+i, false);}if(max != 0) {toggle(\"lbl\"+iv+\"ModPwr\", false);toggle(\"lbl\"+iv+\"ModName\", false);}});evt = document.createEvent(\"HTMLEvents\");evt.initEvent(\"keyup\", false, true);elm.dispatchEvent(evt);});}</script></head><body onload=\"load()\"><h1>Setup</h1><div id=\"setup\" class=\"content\"><div id=\"content\"><a class=\"erase\" href=\"/erase\">ERASE SETTINGS (not WiFi)</a><form method=\"post\" action=\"{IP}/save\"><fieldset><legend class=\"des\">Device Host Name</legend><label for=\"device\">Device Name</label><input type=\"text\" class=\"text\" name=\"device\" value=\"{DEVICE}\"/></fieldset><button type=\"button\" class=\"s_collapsible\">WiFi</button><div class=\"s_content\"><fieldset><legend class=\"des\">WiFi</legend><p>Enter the credentials to your prefered WiFi station. After rebooting the device tries to connect with this information.</p><label for=\"ssid\">SSID</label><input type=\"text\" class=\"text\" name=\"ssid\" value=\"{SSID}\"/><label for=\"pwd\">Password</label><input type=\"password\" class=\"text\" name=\"pwd\" value=\"{PWD}\"/></fieldset></div><button type=\"button\" class=\"s_collapsible\">Inverter</button><div class=\"s_content\"><fieldset><legend class=\"des\">Inverter</legend>{INVERTERS}<br/><p class=\"subdes\">General</p><label for=\"invInterval\">Interval [s]</label><input type=\"text\" class=\"text\" name=\"invInterval\" value=\"{INV_INTVL}\"/><label for=\"invRetry\">Max retries per Payload</label><input type=\"text\" class=\"text\" name=\"invRetry\" value=\"{INV_RETRIES}\"/></fieldset></div><button type=\"button\" class=\"s_collapsible\">NTP Server</button><div class=\"s_content\"><fieldset><legend class=\"des\">NTP Server</legend><label for=\"ntpAddr\">NTP Server / IP</label><input type=\"text\" class=\"text\" name=\"ntpAddr\" value=\"{NTP_ADDR}\"/><label for=\"ntpPort\">NTP Port</label><input type=\"text\" class=\"text\" name=\"ntpPort\" value=\"{NTP_PORT}\"/></fieldset></div><button type=\"button\" class=\"s_collapsible\">MQTT</button><div class=\"s_content\"><fieldset><legend class=\"des\">MQTT</legend><label for=\"mqttAddr\">Broker / Server IP</label><input type=\"text\" class=\"text\" name=\"mqttAddr\" value=\"{MQTT_ADDR}\"/><label for=\"mqttPort\">Port</label><input type=\"text\" class=\"text\" name=\"mqttPort\" value=\"{MQTT_PORT}\"/><label for=\"mqttUser\">Username (optional)</label><input type=\"text\" class=\"text\" name=\"mqttUser\" value=\"{MQTT_USER}\"/><label for=\"mqttPwd\">Password (optional)</label><input type=\"text\" class=\"text\" name=\"mqttPwd\" value=\"{MQTT_PWD}\"/><label for=\"mqttTopic\">Topic</label><input type=\"text\" class=\"text\" name=\"mqttTopic\" value=\"{MQTT_TOPIC}\"/></fieldset></div><button type=\"button\" class=\"s_collapsible\">System Config</button><div class=\"s_content\"><fieldset><legend class=\"des\">System Config</legend><p class=\"des\">Pinout (Wemos)</p>{PINOUT}<p class=\"des\">Radio (NRF24L01+)</p><label for=\"rf24Power\">Amplifier Power Level</label><select name=\"rf24Power\">{RF24}</select><p class=\"des\">Serial Console</p><label for=\"serEn\">print inverter data</label><input type=\"checkbox\" class=\"cb\" name=\"serEn\" {SER_VAL_CB}/><br/><label for=\"serDbg\">Serial Debug</label><input type=\"checkbox\" class=\"cb\" name=\"serDbg\" {SER_DBG_CB}/><br/><label for=\"serIntvl\">Interval [s]</label><input type=\"text\" class=\"text\" name=\"serIntvl\" value=\"{SER_INTVL}\"/></fieldset></div><label for=\"reboot\">Reboot device after successful save</label><input type=\"checkbox\" class=\"cb\" name=\"reboot\"/><input type=\"submit\" value=\"save\" class=\"btn\" /></form></div></div><div id=\"footer\"><p class=\"left\"><a href=\"{IP}/\">Home</a></p><p class=\"left\"><a href=\"{IP}/update\">Update Firmware</a></p><p class=\"right\">AHOY - {VERSION}</p><p class=\"right\"><a href=\"{IP}/factory\">Factory Reset</a></p><p class=\"right\"><a href=\"{IP}/reboot\">Reboot</a></p></div><script type=\"text/javascript\">var coll = document.getElementsByClassName(\"s_collapsible\");var i;for (i = 0;i < coll.length;i++) {coll[i].addEventListener(\"click\", function() {this.classList.toggle(\"active\");var content = this.nextElementSibling;content.style.display = (content.style.display === \"block\") ? \"none\" : \"block\";});}</script></body></html>";
#endif /*__SETUP_HTML_H__*/
