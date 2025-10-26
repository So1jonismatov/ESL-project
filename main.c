#include <stdbool.h>
#include <stdint.h>
#include "boards.h"
#include "nrf_delay.h"

int main(void)
{
    bsp_board_init(BSP_INIT_LEDS);

    while (true)
    {
        bsp_board_led_invert(0);
        nrf_delay_ms(500);
        bsp_board_led_invert(0);

        bsp_board_led_invert(1);
        nrf_delay_ms(500);
        bsp_board_led_invert(1);

        bsp_board_led_invert(2);
        nrf_delay_ms(500);
        bsp_board_led_invert(2);

        bsp_board_led_invert(3);
        nrf_delay_ms(500);
        bsp_board_led_invert(3);
    }
}
