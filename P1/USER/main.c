#include "sys.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "delay.h"


int main(void)
{
/*
delay_init(168);
LED_Init();
	
	while(1){
	 GPIOF->ODR&=~(1<<9);
		GPIOF->ODR&=~(1<<10);
	delay_ms(500);
		
		GPIOF->ODR |= 1<<9;
		GPIOF->ODR |=1<<10;
		delay_ms(500);
	
	}
*/
/*
	delay_init(168);
	
	GPIOF10_Open();
	u16 n=15;
	while(n--){
		GPIOF10_Write(0);
		delay_ms(3000);
//		GPIOF10_Write(1);
//		delay_ms(1000);
	}
	GPIOF_Close();
//	GPIOF10_Write(0);
*/
	delay_init(168);
	beep_init();
	GPIOF8_Write(1);
	delay_ms(100);
	GPIOF_Close();
	
	GPIOF10_Open();
	GPIOF10_Write(1);
	
	GPIOE_Open(GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4);
	u8 KeyOnPress;
	while(1){
		KeyOnPress=KEY_Scan(0);
		if(KeyOnPress==1) {
			GPIOF10_Write(0);
			delay_ms(300);
			GPIOF10_Write(1);
		}
		delay_ms(10);
		
	};

	
	
}



