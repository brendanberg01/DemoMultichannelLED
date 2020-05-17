/*
 * file: main.c
 * author: Brendan Berg
 * MIT License
 * Copyright (c) 2020 Brendan Berg
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "multichannel_led/multichannel_led.h"

int main()
{
    mled_Color colors[6] = {{220u, 20u, 20u},
                            {220u, 20u, 20u},
                            {20u, 220u, 20u},
                            {20u, 220u, 20u},
                            {20u, 20u, 220u},
                            {20u, 20u, 220u}};

    mled_Channel channels[2] = {{&PORTB, &DDRB, 1u, 2u, 3u, -1},
                                {&PORTB, &DDRB, 0u, 3u, 3u, +1}};

    mled_init(channels, 2u);

    while (true)
    {
        mled_transmission_start(channels, 2u, colors);
        _delay_ms(500);
    }

    return 0;
}
