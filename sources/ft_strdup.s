extern	_malloc

global	_ft_strdup

;char	*ft_strdup(const char *s1)

section .text
_ft_strdup:
	push	rdi			;save the value for later
	xor		rax, rax	;clear to set scas to search null
	xor		rcx, rcx	;clear count
	not		rcx			;count from max rcx val
	repne	scasb		;iterate until rdi points to null
	not		rcx			;convert using two's compliment
	push	rcx			;save length for later
	mov		rdi, rcx	;set the result as the parameter for malloc
	call	_malloc		;call malloc
	mov		rdi, rax	;set dst to newly allocated space
	pop		rcx			;retrieve length form stack
	pop		rsi			;retrieve s1 from stack
	rep		movsb		;copy rsi to rdi
	ret
