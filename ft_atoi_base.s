global	ft_atoi_base

section	.text
ft_atoi_base:
	push	r8
	push	r9
	xor		r9, r9
	xor 	rax, rax
.L1:
	cmp		byte [rdi], 0
	je		.exit
	cmp		byte [rdi], 32
	jg		.minusplus
	inc		rdi
	jmp		.L1

.minusplus:
	mov		r9, 1
	cmp		byte [rdi], 45
	je		.minus
	cmp		byte [rdi], 43
	je		.plus
	jmp		.getdig

.minus:
	mov		r9, -1
	inc		rdi
	jmp		.getdig

.plus:
	mov		r9, 1
	inc		rdi
	jmp		.getdig

.detsn:
	mul		r9
	jmp		.exit

.dig:
	mov		byte r8b, [rdi]
	sub		r8b, 48
	cmp		r8b, sil
	jge		.detsn
	mul		rsi
	add		rax, r8
	inc		rdi
	jmp		.getdig

.lol:
	mov		byte r8b, [rdi]
	sub		r8b, 87
	cmp		r8b, sil
	jge		.detsn
	mul		rsi
	add		rax, r8
	inc		rdi
	jmp		.getdig

.upl:
	mov		byte r8b, [rdi]
	sub		r8b, 55
	cmp		r8b, sil
	jge		.detsn
	mul		rsi
	add		rax, r8
	inc		rdi
	jmp		.getdig

.getdig:
	cmp		byte [rdi], 48
	jl		.detsn
	cmp		byte [rdi], 58
	jl		.dig
	cmp		byte [rdi], 102
	jg		.detsn
	cmp		byte [rdi], 96
	jg		.lol
	cmp		byte [rdi], 65
	jl		.detsn
	cmp		byte [rdi], 70
	jg		.detsn
	jmp		.upl

.exit:
	pop		r9
	pop		r8
	ret
