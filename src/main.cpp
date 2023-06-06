#include <constants.h>
#include <Arduino.h>
#include <stdio.h>
#include <MyWiFi.h>
#include <MyMQTT.h>
#include <MySensors.h>


#define US_TO_SECONDS 1000000ULL
#define SOIL_HUMIDITY_SENSOR 32
#define TIME_TO_SLEEP 14400ULL // 4 hours in seconds

void setup() {
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * US_TO_SECONDS);
}

void loop() {
  float soil_humidity = read_soil_humidity(SOIL_HUMIDITY_SENSOR);

  char payload[8];
  snprintf(payload, 8, "%.2f", soil_humidity);

  wifi_connect(WIFI_SSID, WIFI_PASSWORD);
  mqtt_connect(MQTT_HOST);

  mqtt_publish("test", payload);

  mqtt_disconnect();
  wifi_disconnect();

  esp_deep_sleep_start();
}
