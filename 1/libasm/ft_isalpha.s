global _ft_isalpha

section .text

_ft_isalpha:
	cmp rdi, 65
	jl not
	cmp rdi, 122
	jg not
	cmp rdi, 91
	jl is
	cmp rdi, 96
	jg is
	jmp not
	
is:
	mov rax, 1
	ret

not:
	mov rax, 0
	ret
