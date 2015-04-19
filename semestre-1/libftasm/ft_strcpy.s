extern _ft_strlen
global _ft_strcpy

section .text

_ft_strcpy:
	push rdi
	mov rdi, rsi
	call _ft_strlen
	mov rdi, [rsp]
	mov rcx, rax
	cld
	xor al, al
	repne movsb
	mov [rdi], byte 0
	pop rax
	ret
