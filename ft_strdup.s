
section .text
    global _ft_strdup
    extern _malloc
    extern _ft_strlen
    extern _ft_strcpy
	extern ___error

;RDI, RSI, RDX, RCX, R8, R9

_ft_strdup:
    cmp rdi, 0
    jz error
    push rdi
    call _ft_strlen
    add rax, 1
    mov rdi, rax
    call _malloc
    cmp rax, 0
    je error
    pop rsi
    mov rdi, rax
    call _ft_strcpy
    ret

error:
	call ___error
    mov dl, 12
	mov [rax], dl
	mov rax, 0
	ret

exit:
	ret

