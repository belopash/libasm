section .text
	global _ft_write
	extern ___error

;RDI, RSI, RDX, RCX, R8, R9

_ft_write:
	mov rax, 0x2000004
	syscall
	jc error
	ret

error:
	mov rdi, rax
	push rdi
	call ___error
	pop rdi
	mov [rax], rdi
	mov rax, -1
	ret
