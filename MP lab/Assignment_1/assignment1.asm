section .data
msg1 db 10,13 "Enter 5 numbers :"
len1 equ $-msg1
msg2 db 10,13 "% numbers are : "
len2 equ $-msg2

section .bss
counter resb 1
array resd 200

section .text
global _start
_start:

mov byte[counter], 05
loop:
mov rax, 0
mov rdi, 0
mov rsi, array
add rsi, rbx
mov rdx, 17
syscall
add rsi, 17
dec byte[counter]
jnz loop


mov byte[counter], 05
mov rbx, 00
loop1:
mov rax, 1
mov rdi, 1
mov rsi, array
mov rdx, 17
syscall
add rsi, 17
dec byte[counter]
jnz loop1


mov rax, 60
mov rdi,0
syscall