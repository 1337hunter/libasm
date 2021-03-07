global	ft_strdup
extern	malloc
extern	ft_strcpy

section	.text
ft_strdup:
	push	r8
	push	r9
	mov		r9, rdi
	xor		r8, r8

.L1:
	inc		r8
	cmp		byte [r9], 0
	jz		.copy
	inc		r9
	jmp		.L1

.copy:
	mov		r9, rdi
	mov		rdi, r8
	call	malloc wrt ..plt
	mov		rdi, rax
	mov		rsi, r9
	call	ft_strcpy
	pop		r9
	pop		r8
	ret
