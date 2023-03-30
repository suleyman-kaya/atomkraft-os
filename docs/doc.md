<details>
    <summary>boot.asm</summary>
        This assembly code is designed to be a bootloader that switches the computer to graphics mode, reads data from the hard disk, loads the Global Descriptor Table (GDT), and then switches to protected mode.

        The first line, `[org 0x7c00]`, specifies the origin of the code to be at memory address 0x7c00. This is the conventional memory location where a bootloader is loaded.

        The second line, `[bits 16]`, specifies that the code will be 16-bit code.

        The `.switch` section is where the bootloader switches to graphics mode and reads data from the hard disk. The code first sets the appropriate values for the VESA BIOS Extension (VBE) query and then makes a BIOS interrupt call to obtain information about the graphics mode. It then sets the appropriate values for the VBE mode switch and makes another BIOS interrupt call to switch to graphics mode. Next, it sets the data segment (DS) and extra segment (ES) registers to 0, and reads data from the hard disk. The code then turns off interrupts and loads the GDT table. It sets the CR0 register to enable protected mode and jumps to the `protected_start` label.

        The `.protected_start` section switches to 32-bit protected mode and sets up the data segment registers. It then updates the stack pointer and makes a call to the address 0x1000. After that, the code enters an infinite loop.

        The `.gdt_begin` section defines the beginning of the GDT table. The table includes a null descriptor, a code segment descriptor, and a data segment descriptor. The `.gdt_end` and `.gdt_descriptor` sections define the end of the GDT table and the GDT descriptor, respectively.

        Finally, the code uses the `times` directive to pad the file with zeros until it reaches the size of 512 bytes. The last two bytes of the file are set to `0x55` and `0xaa`, which are the boot sector signature bytes.
</details>
<details>
    <summary>boot/</summary>
        ## Directories
        
        ### /bin
        there are only output files
        
        ### /utilities
        we have a font2c converter here
        
        ## Files
        
        ![boot.asm](boot.asm.md)
        ![final.c](final.c.md)
        ![font.c](font.c.md)
        ![graphics.c](graphics.c.md)
        ![graphics.h](graphics.h.md)
        ![graphic_elements.c](graphic_elements.c.md)
        ![input.c](input.c.md)
        ![kernel_entry.asm](kernel_entry.asm.md)
        ![main.c](main.c.md)
        ![task.c](task.c.md)
</details>