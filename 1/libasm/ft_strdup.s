extern _malloc, _ft_strlen
global _ft_strdup

section .text

_ft_strdup:
	push rdi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	call _malloc
	cmp rax, 0
	je fail
	pop rsi
	push rax
	mov rdi, rsi
	call _ft_strlen
	mov rcx, rax
	pop rdi
	push rdi
	cld
	rep movsb
	mov [rdi], byte 0
	pop rax
	ret

fail:
	xor rax, rax
	leave
	ret
