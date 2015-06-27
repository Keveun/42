global _ft_isprint

_ft_isprint:
	cmp rdi, 32
	jl not
	cmp rdi, 126
	jg not
	mov rax, 1
	ret

not:
	mov rax, 0
	ret
