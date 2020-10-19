/*
 * RTOS_LED_Tasks.c
 *
 * Created: 10/19/2020 9:58:47 PM
 * Author : messi
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
void LedRed (void* ptr);
void LedGreen (void* ptr);
void LedBlue (void* ptr);
int main(void)
{
	DDRC |=(1<<7);
	DDRC |=(1<<2);
	DDRD |=(1<<3);
	xTaskCreate(LedRed,"Task1",50,NULL,0,NULL);
	xTaskCreate(LedGreen,"Task2",50,NULL,0,NULL);
	xTaskCreate(LedBlue,"Task3",50,NULL,0,NULL);
	vTaskStartScheduler();
    /* Replace with your application code */
    while (1) 
    {
    }
}

void LedRed (void* ptr)
{
	while (1)
	{
		PORTC ^=(1<<7);
		vTaskDelay(100/portTICK_PERIOD_MS);
	}
}
void LedGreen (void* ptr)
{
	while (1)
	{
		PORTC ^=(1<<2);
		vTaskDelay(250/portTICK_PERIOD_MS);
	}
}
void LedBlue (void* ptr)
{
	while (1)
	{
		PORTD ^=(1<<3);
		vTaskDelay(500/portTICK_PERIOD_MS);
	}
}