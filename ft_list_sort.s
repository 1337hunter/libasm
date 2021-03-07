global	ft_list_sort

section	.text
ft_list_sort:
	push	r12
	push	r8
	push	r9
	push	r10
	push	r11
	push	rcx
	push	rax
	mov		r10, rdi
	mov		r11, rsi
	xor		rcx, rcx
	mov		r8, [r10]

.loop:
	mov		r9, [r8 + 8]
	cmp		r9, 0
	je		.rep
	mov		rdi, [r8]
	mov		rsi, [r9]
	call	r11
	cmp		rax, 0
	jg		.swap
	mov		r8, r9
	jmp		.loop

.rep:
	cmp		rcx, 0
	je		.exit
	xor		rcx, rcx
	mov		r8, [r10]
	jmp		.loop

.swap:
	mov		rcx, [r8]
	mov		r12, [r9]
	mov		[r9], rcx
	mov		[r8], r12
	mov		rcx, 1
	mov		r8, r9
	jmp		.loop

.exit:
	pop		rax
	pop		rcx
	pop		r11
	pop		r10
	pop		r9
	pop		r8
	pop		r12
	ret
