/* this is a lab 4 in embedded c 
Eng: Islam Abdelnasser Ibrahim
Embedded system online diploma */
#include <stdint.h>
typedef volatile unsigned long Vuint32;
#define SYSCTL_RCGC2_R (*((Vuint32*)0x400FE108))
#define GPIO_PortF_DATA_R (*((Vuint32*)0x400253FC))
#define GPIO_PortF_DIR_R (*((Vuint32*)0x40025400))
#define GPIO_PortF_DEN_R (*((Vuint32*)0x4002551C))
int main(void){
	SYSCTL_RCGC2_R =0x20;
    int i;
    for(i=0;i<20000;i++);
    GPIO_PortF_DIR_R |= 1<<3;
    GPIO_PortF_DEN_R |= 1<<3;
	
	while(1){

		GPIO_PortF_DATA_R |=(1<<3);
		for(i=0;i<20000;i++);
		GPIO_PortF_DATA_R &=(~(1<<3));
		for(i=0;i<20000;i++);


	}

	return 0;
}
