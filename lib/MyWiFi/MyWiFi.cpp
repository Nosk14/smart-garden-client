#include "WiFi.h"

void wifi_connect(const char* ssid, const char *password){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
    }
}

void wifi_disconnect(){
    WiFi.disconnect();
}
