;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; strstr
; 

BITS 64
section .text

; char *strstr(const char *rdi, const char *rsi);
; The strstr() function finds the first occurrence of the substring rsi in the string rdi.
; The terminating null bytes ('\0') are not compared.
global strstr
strstr:
    xor rcx, rcx ; rcx = 0

    cmp byte [rsi], 0
    je find ; if (rsi[0] == '\0'): find()

loop:
    cmp byte [rdi + rcx], 0
    je notin ; if (rdi[rcx] == '\0'): notin()

    mov r8, rcx ; r8 = rcx
    xor r9, r9 ; r9 = 0

whilequal:
    cmp byte [rsi + r9], 0
    je find ; if (rsi[r9] == '\0'): find()

    cmp byte [rdi + r8], 0
    je notin ; if (rdi[r8] == '\0'): notin

    mov dl, byte [rdi + r8] ; dl = rdi[r8]
    cmp dl, byte [rsi + r9]
    jne break_while ; if (rsi[r9] != dl): break_while()

    inc r8 ; ++r8
    inc r9 ; ++r9
    jmp whilequal ; whilequal()

break_while:
    inc rcx ; ++rcx
    jmp loop ; loop()


find:
    lea rax, [rdi + rcx] ; rax = &rdi[rcx]
    jmp end ; end()

notin:
    xor rax, rax ; rax = NULL

end:
    ret ; return rax
