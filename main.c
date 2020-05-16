/*
 * file: main.c
 * author: Brendan Berg
 * MIT License
 * Copyright (c) 2020 Brendan Berg
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "multichannel_led/library.h"

int main()
{
    DDRB |= (1 << DDB5);

    while (true)
    {
        hello();
        _delay_ms(500);
    }

    return 0;
}
