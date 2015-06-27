global _ft_swap

section .text

_ft_swap:
	cmp rdi, rsi
	je end
	mov rax, [rsi]
	xor [rdi], rax
	mov rax, [rdi]
	xor [rsi], rax
	mov rax, [rsi]
	xor [rdi], rax
	ret

end:
	ret
