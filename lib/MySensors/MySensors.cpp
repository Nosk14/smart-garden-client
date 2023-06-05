#include <Arduino.h>

#define SOIL_HUMIDITY_MIN 900
#define SOIL_HUMIDITY_MAX 4095
#define NUMBER_OF_SAMPLES 3
#define DELAY_BETWEEN_SAMPLES 200


int sampling_read(int pin){
    int acc = 0;
    for(int i = 0; i < NUMBER_OF_SAMPLES; i++){
        acc += analogRead(pin);
        if( i != NUMBER_OF_SAMPLES-1  ) delay(DELAY_BETWEEN_SAMPLES);
    }

    return acc / NUMBER_OF_SAMPLES;
}

float read_soil_humidity(int pin){
    int raw_value = sampling_read(pin);

    if(raw_value <= SOIL_HUMIDITY_MIN) return 100.0;
    if(raw_value >= SOIL_HUMIDITY_MAX) return 0.0;

    return (1-(float(raw_value-SOIL_HUMIDITY_MIN)/(SOIL_HUMIDITY_MAX - SOIL_HUMIDITY_MIN))) * 100;
}