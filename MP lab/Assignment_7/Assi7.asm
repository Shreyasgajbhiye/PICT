section .data
title :
    db 10, "=====values of GDTR,LDTR,IDTR====="
title_len equ $-title

gdtmsg db 10, "2) GDT value : "
gmsg_len equ $-gdtmsg

ldtmsg db 10, "3) LDT value : "                                                  
lmsg_len equ $-ldtmsg

idtmsg db 10, "4) IDT value : "
imsg_len equ $-idtmsg

trmsg db 10, "5) TR value : "
trmsg_len equ $-trmsg

mswmsg db 10, "6) MSW value : "
mswmsg_len equ $-mswmsg
colmsg db ":"

rmodemsg db 10, "1) Processor In : Real Mode"
rmsg_len equ $-rmodemsg

pmodemsg db 10, "1) Processor In : Protected Mode"
pmsg_len equ $-pmodemsg

end db 10, "======================================",10
end_len equ $-end

section .bss
    gdt resd 1
    resw 1
    ldt resw 1
    idt resd 1
    resw 1
    tr resw 1
    msw resw 1  
    dnum_buff resb 04
    cr0_data resd 1

%macro display 2
    mov eax,4
    mov ebx,1
    mov ecx,%1
    mov edx,%2
    int 80h
%endmacro
 
section .text
global _start
_start:
    display title,title_len
    smsw eax                      
    mov [cr0_data],eax
    ror eax,1                        
    jc prmode
    display rmodemsg,rmsg_len
    jmp nxt1
   
prmode:    
    display pmodemsg,pmsg_len

nxt1:    
    sgdt [gdt]
    sldt [ldt]
    sidt [idt]
    str [tr]
    smsw [msw]
    display gdtmsg,gmsg_len

    mov bx,[gdt+4]
    call display_num
    display colmsg,1

    mov bx,[gdt+2]
    call display_num
    display colmsg,1

    mov bx,[gdt]
    call display_num
     
    display ldtmsg,lmsg_len
    mov bx,[ldt]
    call display_num
    display idtmsg,imsg_len
       
    mov bx,[idt+4]
    call display_num
    display colmsg,1

    mov bx,[idt+2]
    call display_num
    display colmsg,1
     
    mov bx,[idt]
    call display_num
   
    display trmsg,trmsg_len
    mov bx,[tr]
    call display_num

    display mswmsg,mswmsg_len
    mov bx,[msw]
    call display_num
    display end,end_len

exit:    
    mov eax,01
    mov ebx,00
    int 80h

display_num:
    mov esi,dnum_buff        
    mov ch,04                        
    mov cl,04                        

up1:
    rol bx,cl                      
    mov dl,bl                        
    and dl,0fh                      
    add dl,30h                      
    cmp dl,39h                      
    jbe skip1                        
    add dl,07h                      

skip1:
    mov [esi],dl                    
    inc esi                            
    dec ch                            
    jnz up1                          
     
    mov eax,4                        
    mov ebx,1
    mov ecx,dnum_buff
    mov edx,4
    int 80h
    ret
	

