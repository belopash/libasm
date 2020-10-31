section .text
    global _ft_strcmp

;RDI, RSI, RDX, RCX, R8, R9

_ft_strcmp:
    jmp loop

loop:
    mov dl, byte [rsi]
    cmp byte [rdi], dl 
    ja high
    jb low
    cmp byte [rdi], 0
    jz equal
    inc rsi
    inc rdi
    jmp loop 

low: 
    mov rax, -1
    ret

high:
    mov rax, 1
    ret

equal:
    mov rax, 0
    ret