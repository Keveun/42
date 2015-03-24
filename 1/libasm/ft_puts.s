extern _ft_strlen
global _ft_puts

section .data
null:
	.string db "(null)", 10
	.len equ $ - null.string

section .text

_ft_puts:
	cmp rdi, 0x0
	je is_null
	mov rsi, rdi
	call _ft_strlen
	mov rdi, 0x1
	mov rdx, rax
	mov rax, 0x2000004
	syscall
	push 0xa
	mov rsi, rsp
	mov rdi, 0x1
	mov rdx, 1
	mov rax, 0x2000004
	syscall
	pop rax
	ret

is_null:
	mov rdi, 0x1
	lea rsi, [rel null.string]
	mov rdx, null.len
	mov rax, 0x2000004
	syscall
	ret
