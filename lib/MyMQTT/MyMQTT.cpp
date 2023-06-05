#include <WiFi.h>
#include <PubSubClient.h>


WiFiClient wifiClient;
PubSubClient mqtt(wifiClient);

void mqtt_connect(const char* host){
    mqtt.setServer(host, 1883);
    mqtt.connect("ESP32");
}

boolean mqtt_connected(){
    return mqtt.connected();
}

void mqtt_disconnect(){
    mqtt.disconnect();
}

boolean mqtt_publish(const char* topic, const char* payload){
    return mqtt.publish(topic, payload);
}