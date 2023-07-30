/**
 * @brief DS18B20 temperature sensor example.
 *
 * Measures temperature once per second. Uses DallasTemperature library.
 * 
 * Copyright 2023 JSC TechMinds
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <acdu.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(ONEWIRE::PIN_ONEWIRE);
DallasTemperature tempSensor(&oneWire);

void setup() {
    // Initialize serial communication.
    Serial.begin(115200);

    // Initialize temperature sensor.
    tempSensor.begin();
}

void loop() {
    if (tempSensor.getDeviceCount() == 1) {
        tempSensor.requestTemperatures();
        Serial.println(tempSensor.getTempCByIndex(0));
    } else {
        Serial.println("No sensor connected.");
    }
    delay(3000);
}