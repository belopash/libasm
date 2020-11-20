section .text
    global _ft_strlen

;RDI, RSI, RDX, RCX, R8, R9

_ft_strlen:
    xor rcx, rcx

loop:
    cmp byte [rdi + rcx], 0
    je exit
    inc rcx
    jmp loop

exit:
    mov rax, rcx
    ret
