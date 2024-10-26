;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; atoi
; 

BITS 64
extern strlen
section .text

; int atoi(const char *rdi);
; The atoi() function converts the initial portion of the string pointed to by nptr to int.
; Return the converted value or 0 on error.
global atoi
atoi:
    xor r8, r8

lenloop:
    cmp byte [rdi + r8], 0
    je init ; if (rdi[rax] == '\0'): end()

    inc r8 ; ++rax
    jmp lenloop ; loop()

init:
    push 1 ; stack.push(1)
    dec r8 ; --r8
    xor rax, rax ; rax = 0
    xor rcx, rcx ; rax = 0

loop:
    mov sil, byte[rdi + rcx] ; sil = rdi[rcx]

    cmp sil, 0
    je end ; if (sil == 0): end()
    
    cmp sil, '-'
    je neg ; if (sil == '-'): neg()

    cmp sil, '0'
    jl err ; if (sil < '0'): err()
    
    cmp sil, '9'
    jg err ; if (sil > '9'): err()


    push r8 ; stack.push(r8)
    mov rdx, 1 ; rdx = 1
pow:
    cmp r8, 0
    je setres ; if (r8 == 0): setres()

    dec r8 ; --r8
    imul rdx, 10 ; rdx *= 10
    jmp pow ; pow()

setres:
    pop r8 ; r8 = stack.pop()

    sub sil, '0' ; sil -= '0'
    movsx r9, sil ; r9 = resize(sil, 64bits)
    imul r9, rdx ; r9 *= rdx
    add rax, r9 ; rax += r9

    inc rcx ; ++rcx
    dec r8 ; --r8
    jmp loop ; loop()

neg:
    cmp rcx, 0
    jne err ; if (rcx != 0): err()

    pop rdx ; rdx = stack.pop()
    imul rdx, -1 ; rdx *= -1
    push rdx ; stack.push(rdx)

    inc rcx ; ++rcx
    dec r8 ; --r8
    jmp loop ; loop()

end:
    pop rdx ; rdx = stack.pop()
    imul rax, rdx ; rax *= rdx
    ret ; return rax

err:
    pop rdx ; rdx = stack.pop()
    xor rax, rax ; rax = 0
    ret ; return rax
