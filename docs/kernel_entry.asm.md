# Assembly Code Documentation

This assembly code sets up Interrupt Service Routines (ISRs) and the Interrupt Descriptor Table (IDT).

## Instructions

- `START:`: Defines the entry point of the program.
- `extern start`: Declares the `start` function as an external function to be used later in the code.
- `call start`: Calls the `start` function.
- `jmp $`: Infinite loop to keep the program running.

- `extern _idt, HandleISR1, HandleISR12`: Declares three external symbols that will be used in the code.

- `global isr1, isr12`: Declares two global symbols `isr1` and `isr12`, which are used to define the ISR routines.

- `global LoadIDT`: Declares the `LoadIDT` function as a global symbol.

- `IDTDesc:`: Defines the Interrupt Descriptor Table (IDT) descriptor. It contains the size of the IDT and its location.

- `dw 2048`: Sets the size of the IDT to 2048.

- `dd _idt`: Sets the location of the IDT to the symbol `_idt`.

- `isr1:`: Defines the Interrupt Service Routine (ISR) for interrupt 1. It pushes all registers onto the stack, calls the `HandleISR1` function, pops all registers from the stack, and returns from the interrupt using `iret`.

- `pusha`: Pushes all registers onto the stack.

- `call HandleISR1`: Calls the `HandleISR1` function.

- `popa`: Pops all registers from the stack.

- `iret`: Returns from the interrupt.

- `isr12:`: Defines the ISR for interrupt 12. It follows the same format as `isr1`, but calls the `HandleISR12` function instead.

- `LoadIDT:`: Defines the `LoadIDT` function, which loads the IDT descriptor into memory, enables interrupts using the `sti` instruction, and returns.

- `lidt[IDTDesc]`: Loads the IDT descriptor into memory.

- `sti`: Enables interrupts.

- `ret`: Returns from the function.

## External Symbols

- `start`: The entry point of the program.

- `_idt`: The location of the Interrupt Descriptor Table.

- `HandleISR1`: The function that handles interrupt 1.

- `HandleISR12`: The function that handles interrupt 12.

## Global Symbols

- `isr1`: The ISR for interrupt 1.

- `isr12`: The ISR for interrupt 12.

- `LoadIDT`: The function that loads the IDT descriptor into memory and enables interrupts.