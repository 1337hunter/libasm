global	ft_strcpy

section	.text
ft_strcpy:
	push	r8
	push	rdi
.L1:
	mov byte r8b, [rsi]
	mov	byte [rdi], r8b
	cmp	byte [rsi], 0
	jz	.exit
	inc	rdi
	inc	rsi
	jmp	.L1

.exit:
	pop	rax
	pop	r8
	ret
