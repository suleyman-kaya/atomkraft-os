# Description

This makefile is used to assemble, compile, and link source code files to create an operating system image file. The resulting image file can then be run using a virtual machine or can be written to a physical disk.

## Targets
`all`

This target is the default target and depends on the bootloader target. When executed, it creates the operating system image file.


`bootloader`

This target performs the following tasks:

1. Assemble `boot/boot.asm` to create the bootloader binary file `boot/bin/boot.bin`.
2. Assemble `boot/kernel_entry.asm` to create the kernel entry object file `boot/bin/kernel_entry.bin`.
3. Compile `boot/final.c` to create the kernel object file `boot/bin/kernel.o`.
4. Link `boot/bin/kernel_entry.bin` and `boot/bin/kernel.o` to create the kernel image file `boot/bin/kernel.img`.
5. Use `objcopy` to extract the `.text` section from `boot/bin/kernel.img` and create the kernel binary file `boot/bin/kernel.bin.`
6.Concatenate `boot/bin/boot.bin` and `boot/bin/kernel.bin` to create the operating system image file `os.img`.


`clear`

This target is used to remove the `os.img` file.


`run`

This target is used to run the operating system image file `os.img` using the QEMU virtual machine.


## How to Use

To build the operating system image file, simply run the `make` command in the terminal. This will build the image file `os.img`.

To remove the `os.img` file, run the command `make clear`.

To run the operating system image file using QEMU, run the command `make run`.

Note: This makefile assumes that the necessary dependencies are already installed in the system, including nasm and gcc.