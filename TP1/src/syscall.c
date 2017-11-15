#include "syscall.h"
#define PANIC() do {kernel_panic("syscall", 28);} while(0)

void sys_reboot() {
	int command = 1;
	__asm("mov r0, %0" : "=r"(command): :"r0");
	__asm("SWI #0");
}

void sys_nop() {
	int command = 2;
	__asm("mov r0, %0" : "=r"(command): :"r0");
	__asm("SWI #0");
}

void do_sys_reboot() {
	__asm("B 0x8000");
}

void do_sys_nop() {
}

__attribute__ ((naked)) void swi_handler() {	
	__asm("stmfd sp!, {r1-r12, lr}");
	
	int value = 0;
	
	__asm("mov %0, r0" : "=r"(value));
	
	if(value == 1) {
		do_sys_reboot();
	}
	else if(value == 2) {
		do_sys_nop();
	}
	else {
		PANIC();
	}
	__asm("ldmfd sp!, {r1-r12, pc}^");
}
