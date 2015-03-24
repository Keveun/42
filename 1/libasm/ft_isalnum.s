global _ft_isalnum

section .text

_ft_isalnum:
	cmp rdi, 48
	jl not
	cmp rdi, 58
	jl is
	cmp rdi, 65
	jl not
	cmp rdi, 91
	jl is
	cmp rdi, 97
	jl not
	cmp rdi, 123
	jl is

not:
	mov rax, 0
	ret

is:
	mov rax, 1
	ret
