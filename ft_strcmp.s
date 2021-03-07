
global	ft_strcmp

section	.text
ft_strcmp:
	push	r8
	push	r9
	xor		r8, r8
	xor		r9, r9

.L1:
	mov	byte r8b, [rdi]
	mov	byte r9b, [rsi]
	;cmp	r8b, 0
	;jz	.ret
	cmp	r9b, 0
	jz	.ret
	cmp	r8b, r9b
	jnz	.ret
	inc	rdi
	inc	rsi
	jmp	.L1

.ret:
	sub	r8, r9
	mov	rax, r8
	pop	r9
	pop	r8
	ret
