#include "beep.h"
#include "sys.h"

void beep_init(void){
		GPIO_InitTypeDef GPIOF_Device={.GPIO_Pin=GPIO_Pin_8,
																 .GPIO_Mode=GPIO_Mode_OUT,
		                             .GPIO_Speed=GPIO_Speed_100MHz,
		                             .GPIO_OType=GPIO_OType_PP,
		                             .GPIO_PuPd=GPIO_PuPd_DOWN
	};
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	GPIO_Init(GPIOF,&GPIOF_Device);
	GPIOF8_Write(0);
	
}

void GPIOF8_Write(_Bool val){
	if(val==0){
		GPIOF->ODR&=~(1<<8);
	}else{
		GPIOF->ODR|=(1<<8);
	}	
}


