C Code Documentation
====================

Overview
--------

This C code is part of a larger project called "Atomkraft OS". It includes the `start()` function, which initializes various components of the OS, creates and schedules tasks, and enters an infinite loop where it continuously processes tasks and flushes the screen.

Included Libraries
------------------

*   `graphics.h`: provides functions for interacting with the graphics hardware and drawing to the screen.

Functionality
-------------

1.  Initializes a `VBEInfoBlock` struct with information about the display.
2.  Sets the initial mouse coordinates to the center of the screen.
3.  Initializes a string literal and a character buffer.
4.  Sets the `base` and `base12` variables to the addresses of the `isr1` and `isr12` interrupt service routines, respectively.
5.  Initializes the mouse and the Interrupt Descriptor Table (IDT).
6.  Creates and schedules tasks:
    *   `ClearScreenTask`: clears the screen.
    *   `DrawProducersName`: draws the producer's name on the screen.
    *   `TaskbarTask`: creates a taskbar at the top of the screen.
    *   `DrawMouseTask`: implements the mouse handler.
7.  Enters an infinite loop where it continuously processes tasks and flushes the screen.

Variables
---------

*   `VBE`: a pointer to a `VBEInfoBlock` struct that contains information about the display.
*   `mx`: the x-coordinate of the mouse cursor.
*   `my`: the y-coordinate of the mouse cursor.
*   `str1`: a string literal containing a welcome message.
*   `p`: a pointer to the first character in `str1`.
*   `characterBuffer`: a character buffer used for storing user input.
*   `characterBufferPointer`: a pointer to the first character in `characterBuffer`.
*   `characterBufferLength`: the current length of `characterBuffer`.
*   `base`: the address of the `isr1` interrupt service routine.
*   `base12`: the address of the `isr12` interrupt service routine.

Tasks
-----

*   `ClearScreenTask`: clears the screen.
*   `DrawProducersName`: draws the producer's name on the screen.
*   `TaskbarTask`: creates a taskbar at the top of the screen.
*   `DrawMouseTask`: implements the mouse handler.

Infinite Loop
-------------

The `while` loop in `start()` continuously calls `ProcessTasks()` to execute the scheduled tasks and `Flush()` to update the screen.