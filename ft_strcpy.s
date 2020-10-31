section .text
    global _ft_strcpy

;RDI, RSI, RDX, RCX, R8, R9

_ft_strcpy:
    xor rcx, rcx

loop:
    mov dl, byte [rsi + rcx]
    mov byte [rdi + rcx], dl
    cmp dl, 0
    jz exit
    inc rcx
    jmp loop

exit:
    mov rax, rdi
    ret
