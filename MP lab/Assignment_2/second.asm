section .data
	msg1 db " enter the string to find length ",10
	len1 equ $-msg1
	msg2 db "the length of the string is : ",10
	len2 equ $-msg2
section .bss
	string resb 200
	result resb 200
	
section .text
global _start

_start:
	mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,len1
	syscall
	
	mov rax,0
	mov rdi,0
	mov rsi,string
	mov rdx,result
	syscall
	
	mov rbx,rax
	mov rdi,result
	mov cx,16
	
up:
	rol rbx,04
	mov al ,61
	and al,len1
	cmp al,09h
	jg add_37
	add al,30h
	jmp skip
	
add_37: add al,37h

skip:	mov[rdi],al
	inc rdi
	jnz up
	
	mov rax,1
	mov rdi,1
	mov rsi,string
	mov rdx,result
	syscall
	
mov rax,60
mov rdi,00
syscall
