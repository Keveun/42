global _ft_strcat

_ft_strcat:
	push rdi

loop:
	cmp byte[rdi], 0x0
	je cpy
	inc rdi
	jmp loop

cpy:
	cmp byte[rsi], 0x0
	je end
	movsb
	jmp cpy

end:
	mov [rdi], byte 0x0
	pop rax
	ret
