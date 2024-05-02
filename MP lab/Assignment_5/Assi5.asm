

%macro rw 4

mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall

%endmacro

section .data

m1 db 10,"Count of Positive numbers: "
l1 equ $-m1

m2 db 10,"Count of Negative numbers: "
l2 equ $-m2

m3 db 10
l3 equ $-m3

array db 10h, 35h, 25h, 60h, 15h,-11h,-23h

section .bss

	count resb 2
	pcount resb 2
	ncount resb 2
	totalcount resb 2

section .text

global _start

_start:

	mov byte[count],07
	mov byte[pcount],00
	mov byte[ncount],00

mov rsi,array

Up:
mov rax, [rsi]
js neg
inc byte[pcount]
jmp Down

neg:
inc byte[ncount]

Down:
inc rsi
dec byte[count]
jnz Up

rw 1,1,m1,l1
mov bh,[pcount]
call display

rw 1,1,m2,l2
mov bh,[ncount]
call display

rw 1, 1, m3, l3

;exit call

mov rax,60
mov rdi,00
syscall


display:
	mov byte[count],02
	mov byte[totalcount], 00

loop:
      rol bh,04
	mov al,bh
	and al,0fH
	cmp al,09h
	jbe add_30
	add al,07h

add_30:
	add al,30h

mov[totalcount],al
dec byte[count]
jnz loop

rw 1, 1, totalcount, 02
rw 1, 1, m3, l3

ret


