section .bss
arg_input    resb    01
fact_output  resb    01
result       resb    4

section .data
space        db      ' '
space_len    equ     $-space

section .text
global _start

_start:
    ; Read the input argument from command line
    pop     rbx
    pop     rbx
    pop     rbx
    mov     dl, [rbx]            ; Fetch value from argv[1] and store in dl
    sub     dl, 30h              ; Convert ASCII to integer
    mov     [arg_input], dl      ; Save the input argument

    ; Call the recursive factorial function
    mov     rdi, arg_input
    call    factorial

    ; Display the result
    mov     rdi, fact_output
    call    disp

    ; Exit the program
    mov     rax, 60              ; syscall exit
    xor     rdi, rdi             ; Exit code 0
    syscall

; Recursive factorial function
factorial:
     

    ; Decrement the input argument
    dec     byte [rdi]

    ; Call factorial recursively with decremented argument
    push    rdi                  ; Save the current argument
    call    factorial             ; Recursive call
    pop     rdi                  ; Restore the original argument

    ; Multiply the result by the current argument value
    mov     rbx, byte [rdi]      ; Load the current argument
    mov     rax, byte [fact_output]  ; Load the result
    mul     rbx                  ; Multiply the result by the argument
    mov     byte [fact_output], al  ; Store the low byte of the result
    ret

.base_case:
    ; Base case: Return 1
    mov     byte [fact_output], 1
    ret

; Display function
disp:
    mov     bl, al              ; Copy the result to bl
    mov     rdi, result         ; Destination for formatted output
    mov     cx, 02              ; Loop counter for formatting

up1:
    rol     bl, 04              ; Rotate left 4 bits
    mov     al, bl              ; Move rotated value to al
    and     al, 0fh             ; Mask the lower 4 bits
    cmp     al, 09h             ; Compare with ASCII '9'
    jg      add_37              ; If greater than 9, add 37h
    add     al, 30h             ; Else, add 30h (ASCII '0')
    jmp     skip1               ; Jump to skip adding 37h

add_37:
    add     al, 37h             ; Add 37h to convert to ASCII A-F

skip1:
    mov     [rdi], al           ; Store the formatted character
    inc     rdi                 ; Move to the next byte in result
    dec     cx                  ; Decrement loop counter
    jnz     up1                 ; Jump if not zero

    ; Write the result to stdout
    mov     rdx, 4              ; Length of the result (4 bytes)
    mov     rsi, result         ; Pointer to the result
    mov     rax, 1              ; syscall write
    mov     rdi, 1              ; File descriptor 1 (stdout)
    syscall

    ; Write space characters to stdout
    mov     rdx, space_len      ; Length of space characters
    mov     rsi, space          ; Pointer to space characters
    mov     rax, 1              ; syscall write
    mov     rdi, 1              ; File descriptor 1 (stdout)
    syscall

    ret