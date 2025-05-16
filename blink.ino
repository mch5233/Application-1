#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN 2  // GPIO 2 is often tied to onboard LED

void blink_task(void *pvParameters) {
    bool led_on = false;
    while (1) {
        digitalWrite(LED_PIN, led_on ? HIGH : LOW);
        led_on = !led_on;
        Serial.printf("LED %s\n", led_on ? "ON" : "OFF");
        vTaskDelay(pdMS_TO_TICKS(250)); // 250 ms ON/OFF => 2 Hz
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    xTaskCreate(blink_task, "Blink Task", 2048, NULL, 1, NULL);
}

void loop() {
    // Nothing here — blinking handled by task
}
