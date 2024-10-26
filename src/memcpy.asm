;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; memcpy
; 

BITS 64
section .text

; void *memcpy(void *restrict rdi, const void *restrict rsi, size_t rdx);
; The memcpy() function copies rdx bytes from memory area rsi to memory area rdi. The memory areas must not overlap.
global memcpy
memcpy:
    xor rcx, rcx ; rcx = 0

loop:
    cmp rcx, rdx
    jge end ; if (rcx >= rdx): end()
 
    mov al, byte [rsi + rcx] ; al = rsi[rcx]
    mov byte [rdi + rcx], al ; rdi[rcx] = al

    inc rcx ; ++rcx
    jmp loop ; loop()

end:
    mov rax, rdi ; rax = rdi
    ret ; return rax
