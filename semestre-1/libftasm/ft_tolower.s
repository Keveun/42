global _ft_tolower

section .text

_ft_tolower:
	cmp rdi, 65
	jl end
	cmp rdi, 90
	jg end
	mov rax, rdi
	add rax, 32
	ret

end:
	mov rax, rdi
	ret
