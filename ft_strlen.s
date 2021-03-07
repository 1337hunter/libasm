global ft_strlen

section 	.text
ft_strlen:
	xor 	rax, rax
.L1:
	cmp		byte [rdi], 0
	jz		.ret
	inc		rdi
	inc		rax
	jmp		short .L1	

.ret:
	ret	
