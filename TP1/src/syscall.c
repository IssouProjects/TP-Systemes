#include "syscall.h"
#include "hw.h"

#define PANIC() do { kernel_panic("syscall", 32);} while(0)

void sys_reboot(){
	int sys_call = 1;
	__asm("mov r0, %0" : "=r"(sys_call): :"r0");
	__asm("SWI #0");
}

void sys_nop(){
	int sys_call = 2;
	__asm("mov r0, %0" : "=r"(sys_call): :"r0");
	__asm("SWI #0");
}

void sys_settime(uint64_t date_ms){
	uint64_t date_tmp = date_ms;
	int sys_call = 3;
	__asm("mov r0, %0" : "=r"(sys_call): :"r0");
	__asm("mov r2, %0" : "=r"(date_tmp): :"r2");
	__asm("SWI #0");
}

void do_sys_reboot(){
	__asm("b 0x8000");
}

void do_sys_nop(){
	
}

void do_sys_settime(uint64_t date){
	set_date_ms(date);
}

__attribute__ ((naked)) void swi_handler(void){
	// how to get param
	__asm("stmfd sp!, {r1-r12, lr}");
	
	int param = 0;
	uint64_t date = 0;
	__asm("mov %0, r0" : "=r"(param));
	__asm("mov %0, r2" : "=r"(date));
	
	switch((int)param){
	case 1:	
		do_sys_reboot();
		break;
	case 2:
		do_sys_nop();
		break;
	case 3:
		do_sys_settime(date);
		break;
	default:
		PANIC();
		break;
	}
	
	__asm("ldmfd sp!, {r1-r12, pc}^");
}

// r0=1 SWI #0 => pas de retour

// r0=2 => reboot et retour
//	 sauvegarder les registres... (r0=2)

// r0=3 => aller

// r0=4 => retour



//reboot: adresse 0x8000
