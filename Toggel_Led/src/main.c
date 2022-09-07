//this is my first Embedded project in the Embedded System World
typedef volatile unsigned int Vuint32;
#define Rcc_Base 0x40021000
#define GPIO_PortA 0x40010800

#define Rcc_ABP2ENR *(Vuint32*)(0x40021000+0x18)
#define GPIO_Crh *(Vuint32*)(0x40010800+0x04)
#define GPIO_Odr *(Vuint32*)(0x40010800+0x0c)
int main(void){
	Rcc_ABP2ENR =Rcc_ABP2ENR|(1<<2);
	GPIO_Crh &=(0xff0fffff);
	GPIO_Crh |=(0x00200000);
	while(1){

		GPIO_Odr|=(1<<13);
		for( int i=0;i<500;i++);
		GPIO_Odr&=(~(1<<13));
		for(int i=0;i<500;i++);


	}

	return 0;
}
