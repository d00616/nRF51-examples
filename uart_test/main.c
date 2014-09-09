/*
 * This is an UART example
 *
 */

#include "boards.h"
#include "simple_uart.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"

/**
 * Define LED output pin
 */
#if defined LED_RGB_RED
 #define LED_ERROR LED_RGB_RED
#elif defined LED_0
 #define LED_ERROR LED_0
#endif

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
    #ifdef LED_ERROR
     configure_pin(LED_ERROR);
     nrf_gpio_pin_clear(LED_ERROR);
    #endif
    
    // sleep 5 seconds before enable serial port
    for (int i=0;i<25;i++)
    {
     nrf_gpio_pin_clear(LED_ERROR);
     nrf_delay_ms(100);
     nrf_gpio_pin_set(LED_ERROR);
     nrf_delay_ms(100);
    }
    
    // Set up serial port with defined from board.h
    simple_uart_config(RTS_PIN_NUMBER, TX_PIN_NUMBER, CTS_PIN_NUMBER, RX_PIN_NUMBER, HWFC);
    
    // Echo input
    for (;;)
    {
     simple_uart_put(simple_uart_get());
     nrf_gpio_pin_clear(LED_ERROR);
     nrf_delay_ms(20);
     nrf_gpio_pin_set(LED_ERROR);
     nrf_delay_ms(20);
    }

}

