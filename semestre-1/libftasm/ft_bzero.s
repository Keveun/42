global _ft_bzero

section .text

_ft_bzero:
	cmp rsi, 1
	jl end
	mov [rdi], byte 0x0
	dec rsi
	inc rdi
	jmp _ft_bzero

end:
	ret
