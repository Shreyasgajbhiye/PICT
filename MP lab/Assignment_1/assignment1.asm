



; Assignment  


section .data
     msg1 db "Accept five 64 bit Number ",10
     len1 equ $-msg1
     msg2 db "Display five 64 bit number",10
     len2 equ $-msg2

section .bss
     array resd 200
     counter resb 1

section .text
global _start
_start:
	mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,len1
	syscall
      
mov byte[counter],05
mov rbx,00

loop1:
        mov rax,0
	mov rdi,0
	mov rsi,array
	add rsi,rbx
	mov rdx,17
	syscall
     	add rbx,17
      	dec byte[counter]
      	JNZ loop1
     
        mov rax,1
    	mov rdi,1
    	mov rsi,msg2
    	mov rdx,len2
    	syscall

mov rbx,00
loop2:
        mov rax,1                    
        mov rdi, 1                    
    	mov rsi, array                
    	add rsi,rbx
    	mov rdx,17                
    	syscall
        add rbx,17
        dec byte[counter]
        JNZ loop2
                
mov rax,60
mov rdi,00
syscall
