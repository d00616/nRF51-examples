/*
 * This is an LED blinking example
 * Its support RGB or up to eigt single color LEDs
 * High drive is enabled. A maximum current of 15mA for all enabled ports are available (3*5mA .. 15*1mA)
 *
 */

#include "boards.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

/**
 * Configure a pin as high drive output
 */
static __INLINE void configure_pin(uint32_t pin)
{
    NRF_GPIO->PIN_CNF[pin]  = (GPIO_PIN_CNF_SENSE_Disabled << GPIO_PIN_CNF_SENSE_Pos)
                            | (GPIO_PIN_CNF_DRIVE_H0H1 << GPIO_PIN_CNF_DRIVE_Pos)
                            | (GPIO_PIN_CNF_PULL_Disabled << GPIO_PIN_CNF_PULL_Pos)
                            | (GPIO_PIN_CNF_INPUT_Connect << GPIO_PIN_CNF_INPUT_Pos)
                            | (GPIO_PIN_CNF_DIR_Output << GPIO_PIN_CNF_DIR_Pos);
}


/**
 * Main function
 */
int main(void)
{
    // Configure Pins as HIGH drive Output
    #ifdef LED_RGB_RED
     configure_pin(LED_RGB_RED);
    #endif

    #ifdef LED_RGB_GREEN
     configure_pin(LED_RGB_GREEN);
    #endif
    
    #ifdef LED_RGB_BLUE
     configure_pin(LED_RGB_BLUE);
    #endif

    #ifdef LED_0
     configure_pin(LED_0);
    #endif

    #ifdef LED_1
     configure_pin(LED_1);
    #endif
    
    #ifdef LED_2
     configure_pin(LED_2);
    #endif

    #ifdef LED_3
     configure_pin(LED_3);
    #endif
    
    #ifdef LED_4
     configure_pin(LED_4);
    #endif

    #ifdef LED_5
     configure_pin(LED_5);
    #endif
    
    #ifdef LED_6
     configure_pin(LED_6);
    #endif

    #ifdef LED_7
     configure_pin(LED_7);
    #endif
    
    // endless loop
    for(char c=0;;c++)
    {
    #ifdef LED_RGB_RED
      if (c & 1) nrf_gpio_pin_clear(LED_RGB_RED);
       else nrf_gpio_pin_set(LED_RGB_RED);
    #endif
     
    #ifdef LED_RGB_GREEN
      if (c & 2) nrf_gpio_pin_clear(LED_RGB_GREEN);
       else nrf_gpio_pin_set(LED_RGB_GREEN);
    #endif    

    #ifdef LED_RGB_BLUE
      if (c & 4) nrf_gpio_pin_clear(LED_RGB_BLUE);
       else nrf_gpio_pin_set(LED_RGB_BLUE);
    #endif    

    #ifdef LED_0
      if (c & 1) nrf_gpio_pin_clear(LED_0);
       else nrf_gpio_pin_set(LED_0);
    #endif

    #ifdef LED_1
      if (c & 2) nrf_gpio_pin_clear(LED_1);
       else nrf_gpio_pin_set(LED_1);
    #endif

    #ifdef LED_2
      if (c & 4) nrf_gpio_pin_clear(LED_2);
       else nrf_gpio_pin_set(LED_2);
    #endif

    #ifdef LED_3
      if (c & 8) nrf_gpio_pin_clear(LED_3);
       else nrf_gpio_pin_set(LED_3);
    #endif

    #ifdef LED_4
      if (c & 16) nrf_gpio_pin_clear(LED_3);
       else nrf_gpio_pin_set(LED_3);
    #endif

    #ifdef LED_5
      if (c & 32) nrf_gpio_pin_clear(LED_5);
       else nrf_gpio_pin_set(LED_5);
    #endif

    #ifdef LED_6
      if (c & 64) nrf_gpio_pin_clear(LED_6);
       else nrf_gpio_pin_set(LED_6);
    #endif

    #ifdef LED_7
      if (c & 128) nrf_gpio_pin_clear(LED_7);
       else nrf_gpio_pin_set(LED_7);
    #endif

      nrf_delay_ms(500);
    }
}

