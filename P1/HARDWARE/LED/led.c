#include "led.h"
#include "stm32f4xx.h"


void GPIOF10_Open(void)
{
/*
 RCC->AHB1ENR|= 1<<5;
	
	//PF9
 GPIOF->MODER &= ~(3<<2*9);
 GPIOF->MODER |= 1<<(2*9);
	
 GPIOF->OSPEEDR &= ~(3<<2*9);
 GPIOF->OSPEEDR |= 2<<(2*9);
	
 GPIOF->PUPDR &= ~(3<<2*9);
 GPIOF->PUPDR |=1<<(2*9);
	
	GPIOF->OTYPER &= ~(1<<9);
	GPIOF->OTYPER |=0<<9;
	
	GPIOF->ODR|= 1<<9;//1
	//GPIOF->ODR&=~(1<<9);//0
	//PF10-
	
	 GPIOF->MODER &= ~(3<<2*10);
 GPIOF->MODER |= 1<<(2*10);
	
 GPIOF->OSPEEDR &= ~(3<<2*10);
 GPIOF->OSPEEDR |= 2<<(2*10);
	
 GPIOF->PUPDR &= ~(3<<2*10);
 GPIOF->PUPDR |=1<<(2*10);
	
	GPIOF->OTYPER &= ~(1<<10);
	GPIOF->OTYPER |=0<<10;
	
	GPIOF->ODR|= 1<<10;
*/
	GPIO_InitTypeDef GPIOF_Device={.GPIO_Pin=GPIO_Pin_10,
																 .GPIO_Mode=GPIO_Mode_OUT,
		                             .GPIO_Speed=GPIO_Speed_50MHz,
		                             .GPIO_OType=GPIO_OType_PP,
		                             .GPIO_PuPd=GPIO_PuPd_UP
	};
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	GPIO_Init(GPIOF,&GPIOF_Device);
}

void GPIOF9_Open(void)
{
/*
 RCC->AHB1ENR|= 1<<5;
	
	//PF9
 GPIOF->MODER &= ~(3<<2*9);
 GPIOF->MODER |= 1<<(2*9);
	
 GPIOF->OSPEEDR &= ~(3<<2*9);
 GPIOF->OSPEEDR |= 2<<(2*9);
	
 GPIOF->PUPDR &= ~(3<<2*9);
 GPIOF->PUPDR |=1<<(2*9);
	
	GPIOF->OTYPER &= ~(1<<9);
	GPIOF->OTYPER |=0<<9;
	
	GPIOF->ODR|= 1<<9;//1
	//GPIOF->ODR&=~(1<<9);//0
	//PF10-
	
	 GPIOF->MODER &= ~(3<<2*10);
 GPIOF->MODER |= 1<<(2*10);
	
 GPIOF->OSPEEDR &= ~(3<<2*10);
 GPIOF->OSPEEDR |= 2<<(2*10);
	
 GPIOF->PUPDR &= ~(3<<2*10);
 GPIOF->PUPDR |=1<<(2*10);
	
	GPIOF->OTYPER &= ~(1<<10);
	GPIOF->OTYPER |=0<<10;
	
	GPIOF->ODR|= 1<<10;
*/
	GPIO_InitTypeDef GPIOF_Device={.GPIO_Pin=GPIO_Pin_9,
																 .GPIO_Mode=GPIO_Mode_OUT,
		                             .GPIO_Speed=GPIO_Speed_50MHz,
		                             .GPIO_OType=GPIO_OType_PP,
		                             .GPIO_PuPd=GPIO_PuPd_UP
	};
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	GPIO_Init(GPIOF,&GPIOF_Device);
}




void GPIOF10_Write(_Bool val){
	if(val==0){
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);
	}else{
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
	}	
}

void GPIOF9_Write(_Bool val){
	if(val==0){
		GPIO_ResetBits(GPIOF,GPIO_Pin_9);
	}else{
		GPIO_SetBits(GPIOF,GPIO_Pin_9);
	}	
}



void GPIOF_Close(void){
	
	GPIO_DeInit(GPIOF);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,DISABLE);
	
}


