#include "temperature_sensor.h"

#include "arduino_debug.h"

// Digital pin connected to the DHT sensor
// On the attiny85, pin 5 is used as the reset pin, so it cannot be used.
// On the nanoatmega328, pin 0 is used for RX, so it cannot be used.
#if ENV == attiny85
#define DHTPIN 0
#else
#define DHTPIN 5
#endif

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
