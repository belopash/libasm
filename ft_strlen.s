section .text
    global _ft_strlen

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
