;
; EPITECH PROJECT, 2024
; MiniLibC
; File description:
; memmove
; 

BITS 64
section .text

; void *memmove(void *rdi, const void *rsi, size_t rdx);
; The  memmove()  function copies rdx bytes from memory area rsi to memory area rdi.
; The memory areas may overlap: copying takes place as though the bytes in rsi are first copied into a temporary array
; that does not overlap rsi or rdi, and the bytes are then copied from the temporary array to rdi.
global memmove
memmove:
    xor rcx, rcx ; rcx = 0

cpystr:
    cmp rcx, rdx
    jge move ; if (rcx >= rdx): move()

    movsx rax, byte [rsi + rcx] ; rax = resize(rsi[rcx], 64bits)
    push rax ; stack.push(rax)

    inc rcx ; ++rcx
    jmp cpystr ; cpystr()

move:
    mov r8, rcx ; r8 = rcx
    dec r8 ; --r8
    xor rcx, rcx ; rcx = 0

loop:
    cmp rcx, rdx
    jge end ; if (rcx >= rdx): end()

    pop rax ; rax = stack.pop()
    mov byte [rdi + r8], al ; rdi[r8] = al

    dec r8 ; --r8
    inc rcx ; ++rcx
    jmp loop ; loop()

end:
    mov rax, rdi ; rax = rdi
    ret ; return rax
