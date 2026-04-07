/*
****************
Written by: Wil Fehr
apr 06, 2026

task: this program will read the ADC and turn on LEDs accordingly
1--> 12--> 123--> 1234

physical layout()
LED 1---LED 2---LED 3---LED 4----POTENTIOMETER---BOARD(USB->)

LED 1- GPIO 9
LED 2- GPIO 10
LED 3- GPIO 20
LED 4- GPIO 21
ADC - GPIO 0/A0, ADC1_CH0 

****************
*/

#include <stdio.h>
//#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "driver/adc.h"
#include "sdkconfig.h"

void app_main(void)
{

    

}
