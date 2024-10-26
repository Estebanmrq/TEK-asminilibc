;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; memfrob
; 

BITS 64
section .text

; void *memfrob(void *rdi, size_t rsi);
; The memfrob() function encrypts the first rsi bytes of the memory area rdi by exclusive-ORing each character with the number 42.
; The effect can be reversed by using memfrob() on the encrypted memory area.
global memfrob
memfrob:
    xor rcx, rcx ; rcx = 0

loop:
    cmp rcx, rsi
    je end ; if (rcx == rsi): end()

    mov rdx, 42 ; rdx = 42
    xor dl, byte [rdi + rcx] ; dl = XOR(dl, rdi[rcx])
    mov byte [rdi + rcx], dl ; rdi[rcx] = dl

    inc rcx ; ++rcx
    jmp loop ; loop()

end:
    mov rax, rdi ; rax = rdi
    ret ; return rax
