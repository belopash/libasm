section .text
	global _ft_read
	extern ___error

;RDI, RSI, RDX, RCX, R8, R9

_ft_read:
	mov rax, 0x2000003
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
