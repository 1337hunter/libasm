global	ft_list_size

section	.text
ft_list_size:
	xor		rax, rax

.L1:
	inc		rax
	cmp		qword [rdi + 8], 0
	je		.exit
	mov		rdi, [rdi + 8]
	jmp		.L1

.exit:
	ret
