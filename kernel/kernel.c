#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include <stdint.h>

void kernel_main() 
{
    isr_install();
    irq_install();

    clear_screen();
    kprint("dP                                                      .88888.  .d88888b\n");
    kprint("88                                                     d8'   `8b 88.    \"'\n");
    kprint("88        .d8888b. .d8888b. .d8888b. 88d888b.          88     88 `Y88888b. \n");
    kprint("88        88'  `88 88'  `88 88'  `88 88'  `88 88888888 88     88       `8b \n");
    kprint("88        88.  .88 88.  .88 88.  .88 88    88          Y8.   .8P d8'   .8P\n");
    kprint("88888888P `88888P' `8888P88 `88888P8 dP    dP           `8888P'   Y88888P  \n");
    kprint("oooooooooooooooooooo~~~~.88~ooooooooooooooooooooooooooooooooooooooooooooooo\n");
    kprint("                    d8888P\n");
    kprint("\n> ");
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    } else if (strcmp(input, "PAGE") == 0) {
        /* Lesson 22: Code to test kmalloc, the rest is unchanged */
        uint32_t phys_addr;
        uint32_t page = kmalloc(1000, 1, &phys_addr);
        char page_str[16] = "";
        hex_to_ascii(page, page_str);
        char phys_str[16] = "";
        hex_to_ascii(phys_addr, phys_str);
        kprint("Page: ");
        kprint(page_str);
        kprint(", physical address: ");
        kprint(phys_str);
        kprint("\n");
    }
    kprint("You said: ");
    kprint(input);
    kprint("\n> ");
}
