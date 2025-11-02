#include <stdint.h>
#include "nrf_gpio.h"
#include "nrf_delay.h"

#define LED_G NRF_GPIO_PIN_MAP(0, 6)
#define LED_RED NRF_GPIO_PIN_MAP(0, 8)
#define LED_GREEN NRF_GPIO_PIN_MAP(1, 9)
#define LED_BLUE NRF_GPIO_PIN_MAP(0, 12)

#define BUTTON NRF_GPIO_PIN_MAP(1,6)

void configure(void)
{
    nrf_gpio_cfg_input(BUTTON, NRF_GPIO_PIN_PULLUP);

    nrf_gpio_cfg_output(LED_G);
    nrf_gpio_cfg_output(LED_RED);
    nrf_gpio_cfg_output(LED_GREEN);
    nrf_gpio_cfg_output(LED_BLUE);
}



int main(void)
{
    configure();

    uint32_t leds[] = {LED_G, LED_RED, LED_GREEN, LED_BLUE};
    int8_t led_numbers[] = {7,2,3,1};
    int8_t current_led = 0;
    int8_t current_number = 0; 

    for (int i = 0; i < 4; i++) nrf_gpio_pin_set(leds[i]);

    while (1)
    {
        
        if (nrf_gpio_pin_read(BUTTON) == 0)
        {

            nrf_gpio_pin_clear(leds[current_led]);
            nrf_delay_ms(500);
            if (nrf_gpio_pin_read(BUTTON) == 1)
                continue;
            nrf_gpio_pin_set(leds[current_led]);
            nrf_delay_ms(500);

            current_number = (current_number + 1) % led_numbers[current_led];
            if (current_number == 0)
                current_led = (current_led + 1) % 4;
        }

    }
}
