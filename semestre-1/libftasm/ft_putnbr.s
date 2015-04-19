global _ft_putnbr

section .data
neg:
	.string db "-"
	.len equ $ - neg.string

section .text

_ft_putnbr:
	cmp rdi, 0
	jge calc
	not rdi
	inc rdi
	push rdi
	mov rax, 0x2000004
	mov rdi, 1
	lea rsi, [rel neg.string]
	mov rdx, neg.len
	syscall
	pop rdi

calc:
	cmp rdi, 10
	jl display
	mov rax, rdi
	mov rbx, 10
	cqo
	idiv rbx
	mov rdi, rax
	push rdx
	call calc
	pop rdi
	call calc
	ret

display:
	mov rax, 0x2000004
	add rdi, 48
	push rdi
	mov rsi, rsp
	mov rdi, 1
	mov rdx, 1
	syscall
	add rsp, 8
	ret
