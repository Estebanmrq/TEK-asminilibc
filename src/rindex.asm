;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; rindex
; 

BITS 64
section .text

; char *rindex(const char *rdi, int rsi);
; The rindex() function returns a pointer to the last occurrence of the character rsi in the string rdi.
global rindex
rindex:
    xor rcx, rcx ; rcx = 0
    xor rax, rax ; rax = NULL

loop:
    cmp byte[rdi + rcx], 0
    je checkend ; if (rdi[rcx] == '\0'): checkend()
    
    cmp sil, byte[rdi + rcx]
    je setchar ; if (rdi[rcx] == sil): setchar()

    inc rcx ; ++rcx
    jmp loop ; loop()

setchar:
    lea rax, [rdi + rcx] ; rax = &rdi[rcx]
    inc rcx ; ++rcx
    jmp loop ; loop()

checkend:
    cmp rsi, 0
    jne end ; if (rsi != '\0'): end()

    lea rax, [rdi + rcx] ; rax = &rdi[rcx]
    jmp end ; end()

end:
    ret ; return rax
