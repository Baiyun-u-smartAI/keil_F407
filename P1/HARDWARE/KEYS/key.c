#include "key.h"
#include "delay.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//按键输入驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

//按键初始化函数
void GPIOE_Open(uint32_t Pin_Groups)
{
	

	
	GPIO_InitTypeDef GPIOF_Device={.GPIO_Pin=Pin_Groups,
																 .GPIO_Mode = GPIO_Mode_IN,
		                             .GPIO_Speed = GPIO_Speed_100MHz,
		                             .GPIO_PuPd = GPIO_PuPd_UP
	};
		
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);//使能GPIOE时钟

  GPIO_Init(GPIOE, &GPIOF_Device);//初始化GPIOE2,3,4

 
} 

_Bool GPIOE_Read(uint32_t PinNum){
	return GPIO_ReadInputDataBit(GPIOE,PinNum);

}




//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY0按下
//2，KEY1按下
//3，KEY2按下 
//4，WKUP按下 WK_UP
//注意此函数有响应优先级,KEY0>KEY1>KEY2>WK_UP!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(GPIOE_Read(GPIO_Pin_4)==0||GPIOE_Read(GPIO_Pin_3)==0||GPIOE_Read(GPIO_Pin_2)==0))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(GPIOE_Read(GPIO_Pin_4)==0)return 1;
		else if(GPIOE_Read(GPIO_Pin_3)==0)return 2;
		else if(GPIOE_Read(GPIO_Pin_2)==0)return 3;

	}else if(GPIOE_Read(GPIO_Pin_4)==1&&GPIOE_Read(GPIO_Pin_3)==1&&GPIOE_Read(GPIO_Pin_2)==1) key_up=1; 	    
 	return 0;// 无按键按下
}


