[org 0x00]
[bits 16]

section code

.init:
    mov eax, 0x07c0
    mov ds, eax
    mov eax, 0xb800
    mov es, eax
    mov eax, 0 ; set eax to 0 -> i = 0
    mov ebx, 0 ; Index of the character in the string that we are printing
    mov ecx, 0 ; Actual address of the chracter on the screen memory
    mov dl, 0 ; Actual value of the character that we are printing

.clear:
    mov byte [es:eax], 0
    inc eax
    mov byte [es:eax], 0x30
    inc eax

    cmp eax, 2 * 25 * 80

    jl .clear

mov eax, text1
call .print

.end:
    jmp $

.print:
    mov dl, byte [eax + ebx]
    
    cmp dl, 0
    je .print_end
    
    mov byte [es:ecx], dl

    inc ebx
    inc ecx
    inc ecx
    
    jmp .print

.print_end:
    ret

text: db 'Hello world!', 0
text1: db 'This is my first operating system programming experience!', 0

times 510 - ($ - $$) db 0x00 ; Pads the file with 0s, making the file the right size

db 0x55
db 0xaa