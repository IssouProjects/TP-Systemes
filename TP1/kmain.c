#include "syscall.h"

void dummy()
{
    return;
}

int div(int dividend, int divisor)
{
    int result = 0;
    int remainder = dividend;

    while(remainder >= divisor)
    {
        result++;
        remainder -= divisor;
    }

    return result;
}

int compute_volume(int rad)
{
    int rad3 = rad * rad * rad;

    return div(4*355*rad3, 3*113);
}

int kmain(void)
{
	__asm("cps 0x10");
	
	sys_reboot();
	
	int user_mode = 1073742288;
	__asm("mov r2, %0" : "=r"(user_mode): :"r2");
	__asm("msr CPSR, r2");

	int svc_mode = 1073742291;
	__asm("mov r2, %0" : "=r"(svc_mode): :"r2");
	__asm("msr CPSR, r2");

    int radius = 5;
    int volume;

    dummy();
    volume = compute_volume(radius);

    return volume;
}
