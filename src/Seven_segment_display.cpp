#include "Seven_segment_display.h"

#include "seven_segment_characters.h"

#include <Arduino.h>

#define ONES(x) x % 10
#define TENS(x) (x / 10) % 10
#define HUNDREDS(x) (x / 100) % 10
#define THOUSANDS(x) (x / 1000) % 10

const uint8_t Seven_segment_display::m_seven_segment_digits[] = {
    ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

const uint8_t Seven_segment_display::m_seven_segment_letters[] = {
    0x00,          0x00,     0x00,     0x00,     0x00,
    0x00,          0x00,     0x00,     0x00,     0x00,
    0x00,          0x00,     0x00,     0x00,     0x00,
    0x00,          0x00,     0x00,     0x00,     0x00,
    0x00,          0x00,     0x00,     0x00,     0x00,
    0x00,          0x00,     0x00,     0x00,     0x00,
    0x00,          0x00,     0x00,     0x00,     LETTER_DOUBLE_QUOTE,
    0x00,          0x00,     0x00,     0x00,     LETTER_SINGLE_QUOTE,
    0x00,          0x00,     0x00,     0x00,     0x00,
    LETTER_HYPHEN, DP,       0x00,     ZERO,     ONE,
    TWO,           THREE,    FOUR,     FIVE,     SIX,
    SEVEN,         EIGHT,    NINE,     0x00,     0x00,
    0x00,          0x00,     0x00,     0x00,     0x00,
    LETTER_A,      LETTER_B, LETTER_C, LETTER_D, LETTER_E,
    LETTER_F,      LETTER_G, LETTER_H, LETTER_I, LETTER_J,
    LETTER_K,      LETTER_L, LETTER_M, LETTER_N, LETTER_O,
    LETTER_P,      LETTER_Q, LETTER_R, LETTER_S, LETTER_T,
    LETTER_U,      LETTER_V, LETTER_W, LETTER_X, LETTER_Y,
    LETTER_Z,      0x00,     0x00,     0x00,     0x00,
    0x00,          0x00,     LETTER_a, LETTER_b, LETTER_c,
    LETTER_d,      LETTER_e, LETTER_f, LETTER_g, LETTER_h,
    LETTER_i,      LETTER_j, LETTER_k, LETTER_l, LETTER_m,
    LETTER_n,      LETTER_o, LETTER_p, LETTER_q, LETTER_r,
    LETTER_s,      LETTER_t, LETTER_u, LETTER_v, LETTER_w,
    LETTER_x,      LETTER_y, LETTER_z};

const int Seven_segment_display::m_clock_pin = 3;
const int Seven_segment_display::m_latch_pin = 4;
const int Seven_segment_display::m_data_pin = 5;

// Initialize starting value of the display
uint8_t Seven_segment_display::m_display_digits[] = {8};

void Seven_segment_display::setup_seven_segment_display()
{
    // Set the pin modes
    pinMode(m_clock_pin, OUTPUT);
    pinMode(m_latch_pin, OUTPUT);
    pinMode(m_data_pin, OUTPUT);
}

void Seven_segment_display::display_cycle()
{
    for (uint8_t i = 0; i < 10; ++i) {
        m_display_digits[0] = i;
        show();
        delay(500);
    }
}

void Seven_segment_display::show() const
{
    digitalWrite(m_latch_pin, LOW);

    // Shift out each pair of digits
    for (size_t i = 0; i < m_num_display_digits; ++i) {
        shiftOut(m_data_pin, m_clock_pin, LSBFIRST,
                 m_seven_segment_digits[m_display_digits[i]]);
    }

    digitalWrite(m_latch_pin, HIGH);
}
