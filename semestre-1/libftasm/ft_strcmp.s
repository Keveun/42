global _ft_strcmp
extern _ft_strlen

section .text

_ft_strcmp:
	cmp byte[rdi], 0
	je end
	cmp byte[rsi], 0
	je end
	movzx rax, byte[rdi]
	movzx rbx, byte[rsi]
	cmp rax, rbx
	jne end
	inc rdi
	inc rsi
	jmp _ft_strcmp

end:
	movzx rax, byte[rdi]
	movzx rbx, byte[rsi]
	sub rax, rbx
	ret
