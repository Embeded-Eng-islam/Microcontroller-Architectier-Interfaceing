/* learn-in-depth
Unit3_lesson3_lab2
Eng: Islam Abdelnasser Ibrahim
mastering embeded system online diploma */

#include <stdint.h>
extern int main();

void reset_handler();

void default_handler(){
	reset_handler();
}
void NMI() __attribute__((weak,alias("default_handler")));
void hard_fault()__attribute__((weak,alias("default_handler")));
void bus_fault() __attribute__((weak,alias("default_handler")));
void Reserved()__attribute__((weak,alias("default_handler")));
static uint32_t stack_top[256];

void (* const g_p_fun_vectors[])() __attribute__((section(".vectors")))={
(void(*)())((uint32_t)stack_top+sizeof(stack_top)),
&reset_handler,
&NMI,
&hard_fault,
&bus_fault,
&Reserved	
};
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

void reset_handler(void){
	//copy data from flash to sram
	uint32_t data_size= (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* p_src=(unsigned char*)&_E_text;
	unsigned char* p_dst=(unsigned char*)&_S_data;
	int i;
	for (i = 0; i < data_size; ++i)
	{
		*((unsigned char*)(p_dst++)) = *((unsigned char*)(p_src++));
	}
	//init the .bss with zero
	uint32_t bss_size= (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	p_dst = (unsigned char*)&_S_bss;
	for (i = 0; i < bss_size; ++i)
	{
		*((unsigned char*)(p_dst++))=(unsigned char)0;
	}
	main();
}
