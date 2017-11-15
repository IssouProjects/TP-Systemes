#include "syscall.h"
#define PANIC() do {kernel_panic("syscall", 28);} while(0)

void sys_reboot() {
	int command = 1;
	__asm("mov r0, %0" : "=r"(command): :"r0");
	__asm("SWI #0");
}

void do_sys_reboot() {
	__asm("B 0x8000");
}

void swi_handler() {	
	int value = 0;
	
	__asm("mov %0, r0" : "=r"(value));
	
	if(value == 1) {
		do_sys_reboot();
	}
	else {
		PANIC();
	}
	
}
