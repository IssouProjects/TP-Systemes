#include "stdint.h"

void sys_reboot();

void sys_nop();

void sys_settime(uint64_t date_ms);

void do_sys_nop();

void do_sys_settime(uint64_t date);

void swi_handler(void);

void kernel_panic(char* string, int number);

void do_sys_reboot();
