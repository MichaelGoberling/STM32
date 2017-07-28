/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#define PB7_SET_MASK 0x80
#define PB7_CLEAR_MASK 0x7F

void toggleLED(void);
void setGPIOBRegs(void);

int main(void)
{
	//Function call to initialize GPIOB clock en and GPIOB settings
	setGPIOBRegs();

	while(1)
	{
		toggleLED();
	}

	return 0;
}
void setGPIOBRegs(void)
{
	RCC->AHB1ENR |= 0x02;

	//Set mode to general purpose output
	GPIOB->MODER |= 0x10004000;

	//Not sure if needed to set...
	GPIOB->OTYPER |= 0x00;
	GPIOB->OSPEEDR |= 0x0000;
	GPIOB->PUPDR |= 0x0;
}


void toggleLED(void)
{
		//Set line to blue LED high
		GPIOB->ODR &= 0x00;

		for(int i = 0; i < 5000000; i++);

		//Set line to blue + red LED low
		GPIOB->ODR |= 0x0080;

		for(int i = 0; i < 5000000; i++);

		//Set line to red LED high
		GPIOB->ODR &= 0x00;

		for(int i = 0; i < 500000; i++);

		//Set line to  blue + red LED low
		GPIOB->ODR |= 0x4000;

		for(int i = 0; i < 500000; i++);
}
