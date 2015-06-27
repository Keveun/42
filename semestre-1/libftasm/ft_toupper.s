global _ft_toupper

section .text

_ft_toupper:
	cmp rdi, 97
	jl end
	cmp rdi, 122
	jg end
	mov rax, rdi
	sub rax, 32
	ret

end:
	mov rax, rdi
	ret
