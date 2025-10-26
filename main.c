#include <stdbool.h>
#include <stdint.h>
#include "boards.h"
#include "nrf_delay.h"

void blink(int led, int times){
    for(int i = 0; i < times; i++){
        bsp_board_led_invert(led);
        nrf_delay_ms(200);
        bsp_board_led_invert(led);
        nrf_delay_ms(200);
    }
}

int main(void)
{
    bsp_board_init(BSP_INIT_LEDS);



    while (true)
    {
        blink(0, 5);
        nrf_delay_ms(500);
        blink(1, 2);
        nrf_delay_ms(500);
        blink(2, 6);
        nrf_delay_ms(500);
        blink(3, 3);
        nrf_delay_ms(500);

    }
}
