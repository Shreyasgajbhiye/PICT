section .data
	msg1 db "Enter the string: ",0xA,0xD
	msg1len equ $-msg1
	msg2 db "The length of the string: ",0xA,0xD
	msg2len equ $-msg2
section .bss
	str: resb 10
	result: resb 10
section .text
	global _start
	_start:
		mov rax,1
		mov rdi,1
		mov rsi,msg1
		mov rdx,msg1len
		syscall
		
	
		mov rax,0
		mov rdi,0
		mov rsi,str
		mov rdx,16
		syscall

		dec rax
		mov rbx,rax
		mov rdi,result
		mov cx,16
		
	up:	rol rbx,04
		mov al,bl
		and al,0fh
		cmp al,09h
		Jg add_37
		add al,30h
		JMP skip
		
	add_37:  add al,07h
	
	skip:     mov [rdi],al
		inc rdi
		dec cx
		JNZ up

		mov rax,1
		mov rdi,1
		mov rsi,result
		mov rdx,16
		syscall		
		
		mov rax,60
		mov rdi,0
		syscall
