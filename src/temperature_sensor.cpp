#include "temperature_sensor.h"

#include "arduino_debug.h"

#define DHTPIN 2       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22  // DHT 22  (AM2302), AM2321

DHT g_dht{DHTPIN, DHTTYPE};

void print_temperature(bool fahrenheit = false)
{
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow
    // sensor)
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float temp = g_dht.readTemperature(fahrenheit);

    // Check if any reads failed and exit early (to try again).
    if (isnan(temp)) {
        debug_serial_println(F("Failed to read from DHT sensor!"));
        return;
    }

    debug_serial_print(F("Temperature: "));
    debug_serial_print(temp);
    debug_serial_println(F("°F"));
}
