global	ft_list_remove_if
extern	free

section	.text
ft_list_remove_if:
	push	r12
	push	r8
	push	r9
	push	r10
	push	r11
	push	rax
	push	r13
	mov		r13, rdx
	mov		r8, [rdi]
	mov		r11, rdi
	mov		r10, rsi
	xor		rax, rax

.delfirst:
	cmp		r8, 0
	je		.exit
	mov		rdi, [r8]
	call	r13
	cmp		rax, 0
	je		.del1
	jmp		.delmid


.delmid:
	mov		r9, [r8 + 8]
	cmp		r9, 0
	je		.exit
	mov		rdi, [r9]
	call	r13
	cmp		rax, 0
	je		.del2
	mov		r8, r9
	jmp		.delmid

.del1:
	mov		r12, [r8 + 8]
	mov		[r11], r12
	mov		rdi, r8
	call	free wrt ..plt
	mov		r8, [r11]
	inc		rcx
	jmp		.delfirst

.del2:
	mov		r12, [r9 + 8]
	mov		[r8 + 8], r12
	mov		rdi, r9
	call	free wrt ..plt
	cmp		r8, 0
	je		.exit
	jmp		.delmid

.exit:
	pop		r13
	pop		rax
	pop		r11
	pop		r10
	pop		r9
	pop		r8
	pop		r12
	ret
