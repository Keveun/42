global _ft_cat

section .bss

buff:	resb 513

section .text

_ft_cat:
	push rdi

while:
	mov rdi, [rsp]
	mov rax, 0x2000003
	lea rsi, [rel buff]
	mov rdx, 513
	syscall
	jc end
	cmp rax, 0
	jle end
	mov rdx, rax
	mov rax, 0x2000004
	mov rdi, 1
	lea rsi, [rel buff]
	syscall
	jmp while

end:
	add rsp, 8
	ret
