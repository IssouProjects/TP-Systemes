void sys_reboot() {
	int command = 1;
	//invoke();
	__asm("mov r0, %0" : "=r"(command): :"r0");
	__asm("SWI #0");
}

void swi_handler() {	
	/*
	register int value asm("r0");
	if(value == 1) {
		print("yos");
	}
	* */
}
