global _ft_isdigit

section .text

_ft_isdigit:
	cmp rdi, 48
	jl not
	cmp rdi, 57
	jg not
	mov rax, 1
	ret

not:
	mov rax, 0
	ret
