/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN0 = 4;
const int LED_PIN1 = 5;
const int LED_PIN2 = 8;
const int LED_PIN3 = 11;
const int LED_PIN4 = 14;
const int BTN_PIN1 = 28;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN1);
    gpio_set_dir(BTN_PIN1, GPIO_IN);
    gpio_pull_up(BTN_PIN1);

    gpio_init(LED_PIN0);
    gpio_init(LED_PIN1);
    gpio_init(LED_PIN2);
    gpio_init(LED_PIN3);
    gpio_init(LED_PIN4);
    gpio_set_dir(LED_PIN0, GPIO_OUT);
    gpio_set_dir(LED_PIN1, GPIO_OUT);
    gpio_set_dir(LED_PIN2, GPIO_OUT);
    gpio_set_dir(LED_PIN3, GPIO_OUT);
    gpio_set_dir(LED_PIN4, GPIO_OUT);

    int i;
    while(1){
        if (!gpio_get(BTN_PIN1)) {
        i = 0;
        gpio_put(LED_PIN0,1);
        while (i<=258) {
        
            gpio_put(LED_PIN4, 1);
            sleep_ms(5);
            
            gpio_put(LED_PIN4, 0);
            gpio_put(LED_PIN3, 1);
            sleep_ms(5);
            
            gpio_put(LED_PIN3, 0);
            gpio_put(LED_PIN2, 1);
            sleep_ms(5);
            
            gpio_put(LED_PIN2, 0);
            gpio_put(LED_PIN1, 1);
            sleep_ms(5);
            
            gpio_put(LED_PIN1, 0);
            i++;
        }
        gpio_put(LED_PIN0,0);
    }
    }
    /*
    */
}