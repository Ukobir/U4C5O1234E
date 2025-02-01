#include <stdio.h>
#include "pico/stdlib.h"
#include "functions.c"
#include "hardware/timer.h"

// Configurações dos pinos
const uint RGB_pin[3] = {13, 12, 11}; // Red=13, Blue=12, Green=11
// Sequência red, yellow(Blue) e green

// Função de callback que será chamada repetidamente pelo temporizador
// O tipo bool indica que a função deve retornar verdadeiro ou falso para continuar ou parar o temporizador.
bool repeating_timer_callback(struct repeating_timer *t);

// contador: variável global
int count = 0;

int main()
{
    stdio_init_all();

    initLEDs(RGB_pin); // função para iniciar os leds

    // Declaração de uma estrutura de temporizador de repetição.
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3e3, repeating_timer_callback, NULL, &timer);

    while (true)
    {
        printf("\t Eba, passou 1 segundo\n");
        sleep_ms(1000);
    }
}

bool repeating_timer_callback(struct repeating_timer *t)
{
    if(count == 0){
        count++;
        ligaRed(RGB_pin);
    }
    else if(count == 1){
        count++;
        ligaBlue(RGB_pin);
    }
    else if(count == 2){
        count = 0;
        ligaGreen(RGB_pin);
    }

    // Retorna true para manter o temporizador repetindo. Se retornar false, o temporizador para.
    return true;
}