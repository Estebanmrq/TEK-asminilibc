;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; strlen
; 

BITS 64
section .text

; size_t strlen(const char *rdi);
; The strlen() function calculates the length of the string pointed to by rdi, excluding the terminating null byte ('\0').
global strlen
strlen:
    xor rax, rax ; rax = 0

loop:
    cmp byte [rdi + rax], 0
    je end ; if (rdi[rax] == '\0'): end()

    inc rax ; ++rax
    jmp loop ; loop()

end:
    ret ; return rax
