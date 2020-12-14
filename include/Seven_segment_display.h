#pragma once

#include <stddef.h>
#include <stdint.h>

class Seven_segment_display {
  public:
    // Setup function. Called once during setup
    static void setup_seven_segment_display();

    // Returns a reference to the only instance of model (following the
    // Singleton Pattern)
    static Seven_segment_display& get_instance()
    {
        // TODO: should this be "static inline"?
        static Seven_segment_display s;
        return s;
    }

    void display_temperature(float temperature);

    void display_cycle();

  private:
    // Put the contents of the display onto the seven segment displays
    void show() const;

    // Disallow instantiation/destruction of this class from elsewhere
    Seven_segment_display(){};
    ~Seven_segment_display(){};

    // Disallow copy/move construction or assignment
    Seven_segment_display(const Seven_segment_display&) = delete;
    Seven_segment_display& operator=(const Seven_segment_display&) = delete;
    Seven_segment_display(Seven_segment_display&&) = delete;
    Seven_segment_display& operator=(Seven_segment_display&&) = delete;

    static const uint8_t m_seven_segment_digits[];
    static const uint8_t m_seven_segment_letters[];

    static const int m_clock_pin;
    static const int m_latch_pin;
    static const int m_data_pin;

    static const size_t m_num_display_digits = 1;
    static uint8_t m_display_digits[m_num_display_digits];
};
