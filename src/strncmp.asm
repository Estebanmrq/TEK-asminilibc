;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; strncmp
; 

BITS 64
section .text

; int strncmp(const char *rdi, const char *rsi, size_t rdx);
; The strncmp() function is similar, except it compares only the first (at most) rdx bytes of rdi and rsi.
global strncmp
strncmp:
    xor rcx, rcx ; rcx = 0
    
loop:
    cmp rcx, rdx
    je equal ; if (rcx == rdx): equal()

    mov al, byte [rdi + rcx] ; al = rdi[rcx]
    sub al, byte [rsi + rcx] ; al -= rsi[rcx]

    cmp al, 0
    je checkstr ; if (al == 0): checkstr()

    jmp end ; end()

checkstr:
    cmp byte [rdi + rcx], 0
    je equal ; if (rdi[rcx] == '\0'): equal()

    inc rcx ; ++rcx
    jmp loop ; loop()

equal:
    xor rax, rax ; rax = 0

end:
    movsx rax, al ; rax = resize(al, 64bits)
    ret ; return rax
