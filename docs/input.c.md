This is a C program that handles mouse and keyboard interrupts on an x86 architecture. It includes functions for initializing the Interrupt Descriptor Table (IDT), remapping the Programmable Interrupt Controllers (PICs), and handling interrupts.

The program defines various variables, including `mx` and `my` which are used to store the current position of the mouse cursor, `left_clicked`, `right_clicked`, and `middle_clicked` which are used to store the current state of the mouse buttons, and `current_byte` and `bytes` which are used to store data received from the keyboard.

The program also defines constants for the various flags and buttons that can be set in the mouse and keyboard data.

The `InitialiseIDT()` function initializes the IDT and maps interrupt handlers to specific interrupts. The `RemapPIC()` function remaps the PICs to different interrupt vectors to avoid conflicts with other devices.

The `HandleISR1()` function is an interrupt service routine that is called whenever a key is pressed on the keyboard. It reads the scan code of the key and stores it in the `Scancode` variable.

The `HandleISR12()` function is an interrupt service routine that is called whenever the mouse generates an interrupt. It calls the `HandleMouseInterrupt()` function to handle the mouse interrupt and then acknowledges the interrupt by sending an End of Interrupt (EOI) signal to the PICs.

The `InitialiseMouse()` function initializes the mouse by sending commands to the mouse controller and enabling the mouse interrupts. It sets the mouse resolution to its maximum and enables the mouse buttons.

The `MouseWait()` function waits for the mouse controller to become ready before sending or receiving data.

The `MouseWrite()` function sends data to the mouse controller.

The `MouseRead()` function reads data from the mouse controller.

Note that this program assumes that the keyboard and mouse are connected to the x86 architecture. It also assumes that the PICs are present and properly configured.