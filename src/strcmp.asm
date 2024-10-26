;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; strcmp
; 

BITS 64
section .text

; int strcmp(const char *rdi, const char *rsi);
; The strcmp() function compares the two strings rdi and rsi. The comparison is done using unsigned characters.
global strcmp
strcmp:
    xor rcx, rcx ; rcx = 0
    
loop:
    mov al, byte [rdi + rcx] ; al = rdi[rcx] 
    sub al, byte [rsi + rcx] ; al -= rsi[rcx]

    cmp al, 0
    je checkstr ; if (al == 0): checkstr()
    jg sup ; elif (al > 0): sup()
    jmp inf ; else: inf()

checkstr:
    cmp byte [rdi + rcx], 0
    je equal ; if (rdi[rcx] == '\0'): equal()

    inc rcx ; ++rcx
    jmp loop ; loop()

inf:
    mov rax, -1 ; rax = -1
    jmp end ; end()

sup:
    mov rax, 1 ; rax = 1
    jmp end ; end()

equal:
    xor rax, rax ; rax = 0

end:
    ret ; return rax
