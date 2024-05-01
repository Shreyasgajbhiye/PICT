section .data
section .bss
str1 resb 200
result resb 200

section .text
global _start
_start:
mov rax, 0
mov rdi,0
mov rsi, str1
mov rdx, 200
syscall


mov rbx, rax
mov rdi, result
mov cx, 16

up: rol rbx, 04
mov al, bl
and al, 0fh
cmp al, 09h
jg add_37
add al,30h
jmp skip
add_37: add al,37h
skip:mov[rdi], al
inc rdi
dec cx
jnz up

mov rax, 1
mov rdi, 1
mov rsi, result
mov rdx, 16
syscall

mov rax, 60
mov rdi, 0
syscall