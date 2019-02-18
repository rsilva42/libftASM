global	_ft_strlen

;size_t	ft_strlen(const char *s)

section .text
_ft_strlen:
	xor		rax, rax	;clear to set scas to search null
	xor		rcx, rcx	;clear count
	not		rcx			;count from max rcx val
	repne	scasb		;iterate until rdi points to null
	not		rcx			;convert using two's compliment
	dec		rcx			;invert bits and subtract one
	mov		rax, rcx	;set the result as the return value
	ret
