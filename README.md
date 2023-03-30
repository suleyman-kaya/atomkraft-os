# atomkraft: my first operating system programming experience

![screenshot.png](Screenshots/screenshot.png)

## Installation instructions
This OS built and tested on Ubuntu 20.04

Installing and running AtomkraftOS on qemu-kvm:

`sh -c "$(curl -fsSL https://raw.githubusercontent.com/suleyman-kaya/atomkraft-os/main/installer.sh)"`

## Done:
- 32bits - protected mode [✅]
- Keyboard and mouse interruptions [✅]
- Double bufferring [✅]
- A graphics library to render strings, windows, etc. [✅]
- A task system to implement applications in main.c [✅]
- A parameter system to make development process easy to programmers [✅]

## To-do's:
- FAT file system
- A shell
- Ring buffer
- Multithreading
- Maybe some sounds
