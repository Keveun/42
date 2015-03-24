global _ft_isspace

section .text

_ft_isspace:
	xor rax, rax
	cmp rdi, 32
	je is
	cmp rdi, 9
	je is
	cmp rdi, 10
	je is
	cmp rdi, 11
	je is
	cmp rdi, 12
	je is
	ret

is:
	inc rax
	ret
