;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; strcspn
; 

BITS 64
section .text

; size_t strspn(const char *rdi, const char *rsi);
; The strspn() function calculates the length (in bytes) of the initial segment of rdi which consists entirely of bytes in rsi.
global strcspn
strcspn:
    xor rax, rax ; rax = 0

loop:
    cmp byte [rdi + rax], 0
    je end ; if (rdi[rax] == '\0'): end()

    mov dl, byte [rdi + rax] ; dl = rdi[rax]
    xor rcx, rcx ; rcx = 0

check_in:
    cmp byte [rsi + rcx], 0
    je notin ; if (rsi[rcx] == '\0'): notin()

    cmp dl, byte [rsi + rcx]
    je end ; if (rsi[rcx] == dl): end()

    inc rcx ; ++rcx
    jmp check_in ; check_in()

notin:
    inc rax ; ++rax
    jmp loop ; loop()

end:
    ret ; return rax
