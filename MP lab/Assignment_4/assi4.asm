%macro print 2
    mov rax,01
    mov rdi,01
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

%macro read 2
    mov rax,00
    mov rdi,00
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

%macro exit 0
    mov rax, 60
    mov rdi, 0
    syscall
%endmacro exit

section .data
m1 db 10, "Result : ", 10, 13
l1 equ $-m1

m2 db 10, "Enter Your Choice : ", 10, 13
l2 equ $-m2


menu db "1. Addition", 10
   db "2. Subtraction", 10
   db "3. Multiplication", 10
   db "4. Division", 10
   db "5. Exit", 10

len_menu equ $-menu

n1 db 20
n2 db 02

section .bss
choice resb 05
result resb 32

section .text

global _start
_start:

up:
mov rax, 0h
mov rbx, 0h

print menu, len_menu
print m2, l2

read choice, 1

cmp byte[choice], "1"
je plus

cmp byte[choice], "2"
je minus

cmp byte[choice], "3"
je multiply

cmp byte[choice], "4"
je divide

cmp byte[choice], "5"
je exit


plus:
mov rax, [n1]
mov rbx, [n2]
add rax, rbx
call display
exit

minus:
mov rax, [n1]
mov rbx, [n2]
sub rax, rbx
call display
exit

multiply:
mov al, [n1]
mov bl, [n2]
mul bl
call display
exit

divide:
xor rax, rax
xor rdx, rdx
mov al, [n1]
mov bl, [n2]

div bl
call display
exit

display:
mov rbx, rax
mov rdi, result
mov cx, 2

convert:
rol bl, 04
mov al, bl
and al, 0fh
cmp al, 09h
jle add_30
add al, 07h

add_30:
add al, 30h

mov [rdi], al
inc rdi
dec cx
jnz convert

print m1, l1
print result, 8
ret