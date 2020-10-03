#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"

void main() 
{
    isr_install();
    irq_install();

    clear_screen();
    kprint("dP                                                      .88888.  .d88888b\n");
    kprint("88                                                     d8\'   `8b 88.    \"'\n");
    kprint("88        .d8888b. .d8888b. .d8888b. 88d888b.          88     88 `Y88888b. \n");
    kprint("88        88'  `88 88'  `88 88'  `88 88'  `88 88888888 88     88       `8b \n");
    kprint("88        88.  .88 88.  .88 88.  .88 88    88          Y8.   .8P d8'   .8P\n");
    kprint("88888888P `88888P' `8888P88 `88888P8 dP    dP           `8888P'   Y88888P  \n");
    kprint("oooooooooooooooooooo~~~~.88~ooooooooooooooooooooooooooooooooooooooooooooooo\n");
    kprint("                    d8888P\n");
    kprint("\n> ");
}

void user_input(char *input)
{
    if (strcmp(input, "END") == 0)
    {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    }

    kprint("You said: ");
    kprint(input);
    kprint("\n> ");
}
