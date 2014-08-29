/* Copyright (c) 2009 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/**
* @example Board/pca10003/blinky_example/main.c
*
* @brief Blinky Example Application main file.
*
* This file contains the source code for a sample application using GPIO to drive LEDs.
*
*/

#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "boards.h"

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    // Configure LED-pins as outputs.
    nrf_gpio_cfg_output(LED_RGB_RED);
    NRF_GPIO->PIN_CNF[LED_RGB_RED] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                             | (GPIO_PIN_CNF_DRIVE_H0H1 << GPIO_PIN_CNF_DRIVE_Pos)
                             | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)
                             | (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos)
                             | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);

    nrf_gpio_cfg_output(LED_RGB_GREEN);
    NRF_GPIO->PIN_CNF[LED_RGB_GREEN] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                             | (GPIO_PIN_CNF_DRIVE_H0H1 << GPIO_PIN_CNF_DRIVE_Pos)
                             | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)
                             | (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos)
                             | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);

    nrf_gpio_cfg_output(LED_RGB_BLUE);
    NRF_GPIO->PIN_CNF[LED_RGB_BLUE] = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                             | (GPIO_PIN_CNF_DRIVE_H0H1 << GPIO_PIN_CNF_DRIVE_Pos)
                             | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)
                             | (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos)
                             | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);

    char c=0;

    // LED 0 and LED 1 blink alternately.
    while(true)
    {
        if (c & 1) nrf_gpio_pin_clear(LED_RGB_RED);
         else nrf_gpio_pin_set(LED_RGB_RED);

        if (c & 2) nrf_gpio_pin_clear(LED_RGB_GREEN);
         else nrf_gpio_pin_set(LED_RGB_GREEN);
    

        if (c & 4) nrf_gpio_pin_clear(LED_RGB_BLUE);
         else nrf_gpio_pin_set(LED_RGB_BLUE);

        nrf_delay_ms(500);
        c++;
    }
}

