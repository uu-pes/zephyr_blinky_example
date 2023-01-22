#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define DELAY_MS    500
#define STACK_SIZE  500 

#define LED0_NODE   DT_ALIAS(led0) 
struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios); 

void task(struct gpio_dt_spec* led, int delay) 
{
    gpio_pin_configure_dt(led, GPIO_OUTPUT_ACTIVE); 

    for(;;)
    {
        gpio_pin_toggle_dt(led); 
        k_msleep(delay); 
    }
}

K_THREAD_DEFINE(blinky, STACK_SIZE, task, &led0, DELAY_MS, NULL, 5, 0, 0);
