#include <stdio.h>
#include "pico/stdlib.h"

// Função para iniciar os leds
void initLEDs(const uint gpio[3])
{
    for (int i = 0; i < 3; i++)
    {
        gpio_init(gpio[i]);
        gpio_set_dir(gpio[i], GPIO_OUT);
        gpio_put(gpio[i], 0);
    }
}

void ligaRed(const uint gpio[3])
{
    gpio_put(gpio[0], 1);
    gpio_put(gpio[1], 0);
    gpio_put(gpio[2], 0);
}

void ligaBlue(const uint gpio[3])
{
    gpio_put(gpio[0], 0);
    gpio_put(gpio[1], 1);
    gpio_put(gpio[2], 0);
}

void ligaGreen(const uint gpio[3])
{
    gpio_put(gpio[0], 0);
    gpio_put(gpio[1], 0);
    gpio_put(gpio[2], 1);
}