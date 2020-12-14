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

    float temp = g_dht.readTemperature(true);
    if (isnan(temp)) {
        debug_serial_println(F("Failed to read from DHT sensor!"));
        return;
    }

    debug_serial_print(F("Temperature: "));
    debug_serial_print(temp);
    debug_serial_println(F("°F"));

    Seven_segment_display::get_instance().display_temperature(temp);

    // print_temperature(true);
}
