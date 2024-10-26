;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; index
; 

BITS 64
section .text

; char *index(const char *rdi, int rsi);
; The index() function returns a pointer to the first occurrence of the character rsi in the string rdi.
global index
index:
    xor rcx, rcx ; rcx = 0

loop:
    lea rax, [rdi + rcx] ; rax = &rdi[rcx]

    cmp sil, byte [rdi + rcx]
    je end ; if (rdi[rcx] == serached char): end()

    cmp byte [rdi + rcx], 0
    je notfind ; if (rdi[rcx] == '\0'): notfind()

    inc rcx ; ++rcx
    jmp loop ; loop()

notfind:
    mov rax, 0 ; rax = NULL

end:
    ret ; return rax
