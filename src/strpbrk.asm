;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; strpbrk
; 

BITS 64
section .text

; char *strpbrk(const char *rdi, const char *rsi);
; The strpbrk() function locates the first occurrence in the string rdi of any of the bytes in the string rsi.
global strpbrk
strpbrk:
    xor rax, rax ; rax = 0
    xor rcx, rcx ; rcx = 0

loop:
    cmp byte [rdi + rcx], 0
    je end ; if (rdi[rcx] == '\0'): end()

    mov dl, byte [rdi + rcx] ; dl = rdi[rcx]
    xor r8, r8 ; r8 = 0

check_in:
    cmp byte [rsi + r8], 0
    je notin ; if (rsi[r8] == '\0'): notin()

    cmp dl, byte [rsi + r8]
    je findin ; if (rsi[r8] == dl): findin

    inc r8 ; ++r8
    jmp check_in ; check_in()

notin:
    inc rcx ; ++rcx
    jmp loop ; loop()

findin:
    lea rax, [rdi + rcx] ; rax = &rdi[rcx]

end:
    ret ; return rax
