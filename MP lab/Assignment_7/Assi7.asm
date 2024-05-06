%MACRO PRINT 2
    MOV RAX, 1
    MOV RDI, 1
    MOV RSI, %1
    MOV RDX, %2
    SYSCALL
%ENDMACRO PRINT

%MACRO EXIT 0
    MOV RAX, 60
    MOV RDI, 0
    SYSCALL
%ENDMACRO EXIT

section .data
    MSG1 DB 10, "GDTR :- "
    LEN1 EQU $-MSG1
    MSG2 DB 10, "IDTR :- "
    LEN2 EQU $-MSG2
    MSG3 DB 10, "LDTR :- "
    LEN3 EQU $-MSG3
    MSG4 DB 10, "TR :- "
    LEN4 EQU $-MSG4
    MSG5 DB 10, "MSW :- "
    LEN5 EQU $-MSG5
    MSG6 DB 10, "CPUID :- "
    LEN6 EQU $-MSG6

    MSG7 DB 10, "The CPU is in Protected Mode"
    LEN7 EQU $-MSG7
    MSG8 DB 10, "The CPU is not in Protected Mode"
    LEN8 EQU $-MSG8
section .bss
    GDTR_DATA RESB 6
    IDTR_DATA RESB 6
    LDTR_DATA RESB 2
    TR_DATA RESB 2
    MSW_DATA RESB 4
    CPU_DATA RESB 4

    DATA RESB 16
section .text
    global _start

_start:

    XOR EAX, EAX

    CPUID
    MOV [CPU_DATA], EAX

    SMSW EAX
    MOV [MSW_DATA], EAX

    SGDT [GDTR_DATA]
    SIDT [IDTR_DATA]
    SLDT [LDTR_DATA]
    STR [TR_DATA]

    PRINT MSG5, LEN5

    MOV AX, [MSW_DATA+2]
    CALL DISPLAY 
    MOV AX, [MSW_DATA]
    CALL DISPLAY

    PRINT MSG6, LEN6

    MOV AX, [CPU_DATA+2]
    CALL DISPLAY 
    MOV AX, [CPU_DATA]
    CALL DISPLAY

    PRINT MSG1, LEN1

    MOV AX , [GDTR_DATA+4]
    CALL DISPLAY
    MOV AX , [GDTR_DATA+2]
    CALL DISPLAY
    MOV AX , [GDTR_DATA]
    CALL DISPLAY

    PRINT MSG2, LEN2
    
    MOV AX , [IDTR_DATA+4]
    CALL DISPLAY
    MOV AX , [IDTR_DATA+2]
    CALL DISPLAY
    MOV AX , [IDTR_DATA]
    CALL DISPLAY

    PRINT MSG3, LEN3

    MOV AX , [LDTR_DATA]
    CALL DISPLAY

    PRINT MSG4, LEN4
    
    MOV AX , [TR_DATA]
    CALL DISPLAY

    MOV EAX, [MSW_DATA]
    BT EAX, 0
    JC DOWN1

    PRINT MSG8, LEN8
DOWN1:
    PRINT MSG7, LEN7
    
    EXIT

DISPLAY:
mov bx, ax
mov rdi, DATA
mov cx, 4

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

PRINT DATA, 16
ret