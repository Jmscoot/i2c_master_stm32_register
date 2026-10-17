#include "stm32f4xx.h"
/*
 * I2C1_SDA(PB7), AF4
 * I2C1_SCL(PB8), AF4
 *
 */

/*
 *
 */
void i2c_gpio_config(void){
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOBEN;

	GPIOB->MODER|=(2<<14)|(2<<16);
	GPIOB->OSPEEDR|=(2<<14)|(2<<16);
	GPIOB->PUPDR|=(1<<14)|(1<<16);	// 외부 풀업 장치 없을 경우 stm 자체 gpio pull up을 걸어준다.
	GPIOB->AFR[1]|=(4<<0);
	GPIOB->AFR[0]|=(4<<28);
}

/*
 *
 */
void i2c_config(void){
	i2c_gpio_config();

	RCC->APB1ENR|=RCC_APB1ENR_I2C1EN;

	I2C1->
}
