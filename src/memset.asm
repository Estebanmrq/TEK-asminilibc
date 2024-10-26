;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; memset
; 

BITS 64
section .text

; void *memset(void *rdi, int rsi, size_t rdx);
; The memset() function fills the first rdx bytes of the memory area pointed to by rdi with the constant byte rsi.
global memset
memset:
    xor rcx, rcx ; rcx = 0

loop:
    cmp rcx, rdx
    jge end ; if (rcx >= rdx): end()
 
    mov byte [rdi + rcx], sil ; rdi[rcx] = sil

    inc rcx ; ++rcx
    jmp loop ; loop()

end:
    mov rax, rdi ; rax = rdi
    ret ; return rax
