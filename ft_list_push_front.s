global ft_list_push_front

section	.text
ft_list_push_front:
	push	r8
	mov		r8, [rdi]
	cmp		rdi, rsi
	je		.exit
	mov		[rsi + 8], r8
	mov		[rdi], rsi
	jmp		.exit

.exit:
	pop		r8
	ret	
