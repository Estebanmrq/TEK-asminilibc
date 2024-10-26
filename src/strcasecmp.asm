;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; strcasecmp
; 

BITS 64
section .text

; int strcasecmp(const char *rdi, const char *rsi);
; The strcasecmp() function performs a byte-by-byte comparison of the strings rdi and rsi, ignoring the case of the characters.
; It returns an integer less than, equal to, or greater than zero if rdi is found, respectively, to be less than, to match, or be greater than rsi.
global strcasecmp
strcasecmp:
    xor rcx, rcx ; rcx = 0
    
initparams:
    mov al, byte [rdi + rcx] ; al = rdi[rcx]
    mov dl, byte [rsi + rcx] ; dl = rsi[rcx]

convertcase:
    cmp al, 65
    jl convertcase2 ; if (al < 65): convertcase2()

    cmp al, 90
    jg convertcase2 ; if (al > 90): convertcase2()

    add al, 32 ; al += 32

convertcase2:
    cmp dl, 65
    jl loop ; if (dl < 65): loop()

    cmp dl, 90
    jg loop ; if (dl > 90): loop()

    add dl, 32 ; dl += 32

loop:
    cmp al, dl
    je checkstr ; if (al == dl): checkstrt()
    jmp diff ; else: diff()


checkstr:
    cmp byte [rdi + rcx], 0
    je equal ; if (rdi[rcx] == '\0'): equal()

    inc rcx ; ++rcx
    jmp initparams ; initparams()

diff:    
    sub al, dl ; al -= dl
    movsx rax, al ; rax = resize(al, 64bits)
    jmp end ; end()

equal:
    xor rax, rax ; rax = 0

end:
    ret ; return rax