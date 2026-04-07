/*
****************
Written by: Wil Fehr
apr 06, 2026

task: this program will rotate between 4 external LEDs
1--> 2--> 3--> 4--> 1

physical layout()
LED 1---LED 2---LED 3---LED 4-------BOARD(USB->)

LED 1- GPIO 9
LED 2- GPIO 10
LED 3- GPIO 20
LED 4- GPIO 21

****************
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

static const char *TAG = "rotate led";

//LEDs to blink
#define LED1 9
#define LED2 10
#define LED3 20
#define LED4 21

static uint8_t s_led_state = 1;

static void output_led(void){

    gpio_set_level(LED1, (s_led_state & 1));//bit 0
    gpio_set_level(LED2, (s_led_state & 2));//bit 1
    gpio_set_level(LED3, (s_led_state & 4));//bit 2
    gpio_set_level(LED4, (s_led_state & 8));//bit 3
}

static void configure_led(void){
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
    gpio_reset_pin(LED1);
    gpio_reset_pin(LED2);
    gpio_reset_pin(LED3);
    gpio_reset_pin(LED4);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(LED1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED2, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED3, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED4, GPIO_MODE_OUTPUT);
}

void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    configure_led();
    static uint8_t led = 0;

    while (1) {
        

        //ESP_LOGI(TAG, "Turning LED %s!", s_led_state == true ? "ON" : "OFF");
        switch(s_led_state){
            case 1:
                led = '1';
                break;
            case 2:
                led = '2';
                break;
            case 4:
                led = '3';
                break;
            case 8:
                led = '4';
                break;
            default:
                led = 'X';
                break;
        }
        ESP_LOGI(TAG, "LED %c", led);
        output_led();
        /* Toggle the LED state */
        s_led_state = s_led_state << 1;
        if(s_led_state >= 16){
            s_led_state = 1;
        }
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}
