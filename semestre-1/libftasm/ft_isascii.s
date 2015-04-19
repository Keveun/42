global _ft_isascii

section .text

_ft_isascii:
	cmp rdi, 0
	jl not
	cmp rdi, 127
	jg not
	mov rax, 1
	ret
	
not:
	mov rax, 0
	ret
