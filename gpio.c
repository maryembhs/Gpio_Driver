#include "gpio.h"

void GPIO_Clock_Enable(uint32_t *GPIOx){
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD );
  uint16_t *RCCAHB1 = (uint16_t *)(0x40023830);
  
  if (GPIOx == GPIOA){
    *RCCAHB1 |=(1<<0);
  }
  else if (GPIOx == GPIOB){
    *RCCAHB1 |=(1<<1);
  }
  else if (GPIOx == GPIOC){
    *RCCAHB1 |=(1<<2);
  }
  else if (GPIOx == GPIOD)  {
    *RCCAHB1 |=(1<<3);
  }
 }

void GPIO_Config(uint32_t *GPIOx,uint8_t Pin,uint8_t Mode,uint8_t Type)
{
   uint16_t *GPIOx_MODER  = (uint16_t *)(0x40020C00);
   uint16_t *GPIOx_OTYPER  = (uint16_t *)(0x40020C00);
  
   if (Mode == INPUT ){
     *GPIOx_MODER &=(0<<24) ;
     *GPIOx_MODER &=(0<<25) ;
   } 
   
   if (Mode == OUTPUT ){
     *GPIOx_MODER |= (1<<24);
     *GPIOx_MODER &= ~(0<<24); 
   }
   
   if (Mode ==  ALTERNATE ){
     *GPIOx_MODER |= (1<<25);
     *GPIOx_MODER &= ~(0<<24);
   } 
    
   if (Mode == ANALOG_INPUT )
   {
     *GPIOx_MODER |=(1<<24) ;
     *GPIOx_MODER |=(1<<25) ;
   }
     
   if (Type == OUTPUT_PUSH_PULL  )
    {
      *GPIOx_OTYPER  &= ~(0<<12);
    }
   if (Type == OUTPUT_OPEN_DRAIN )
    {
      *GPIOx_OTYPER  |= (1<<12) ;
      
    }
     
}