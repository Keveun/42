global _ft_memcpy

section .text

_ft_memcpy:
	push rdi
	mov rcx, rdx
	rep movsb
	pop rax
	ret
