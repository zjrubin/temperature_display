#include "Seven_segment_display.h"
#include "arduino_debug.h"
#include "seven_segment_characters.h"
#include "temperature_sensor.h"

#include <Arduino.h>
#include <DHT.h>

void setup()
{
#if defined(ARDUINO_DEBUG) && defined(HAS_SERIAL)
    Serial.begin(BAUD_RATE);
#endif

    Seven_segment_display::setup_seven_segment_display();

    // Setup temperature sensor
    g_dht.begin();
}

void loop()
{
    Seven_segment_display::get_instance().display_cycle();
    delay(1000);

    print_temperature(true);  // fahrenheit = true
}
