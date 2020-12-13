#include "Seven_segment_display.h"
#include "seven_segment_characters.h"

#include <Arduino.h>

void setup()
{
    Seven_segment_display::setup_seven_segment_display();
}

void loop()
{
    Seven_segment_display::get_instance().display_cycle();
    delay(1000);
}
