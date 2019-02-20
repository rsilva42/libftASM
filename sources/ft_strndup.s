extern	_malloc

global	_ft_strndup

;char	*ft_strndup(const char *s1, size_t n)

section .text
_ft_strndup:
	push	rbp					;save stack base
	mov		rbp, rsp			;set a new base at current pointer
	sub		rsp, 16				;align the stack pointer
	push	rdi					;save the value for later
	xor		rax, rax			;clear to set scas to search null
	xor		rcx, rcx			;clear count
	not		rcx					;count from max rcx val
	repne	scasb				;iterate until rdi points to null
	not		rcx					;convert using two's compliment
	cmp		rcx, rsi			;check if s1 length is greater than n
	jg		swap_n

post_swap:
	push	rcx					;save length for later
	mov		rdi, rcx			;set the result as the parameter for malloc
	call	_malloc				;call malloc
	mov		rdi, rax			;set dst to newly allocated space
	pop		rcx					;retrieve length form stack
	pop		rsi					;retrieve s1 from stack
	rep		movsb				;copy rsi to rdi
	cmp		byte [rsi], 0x0		;check if s1 pointer is null
	jne		null_terminate		;if not set terminator

return:
	add		rsp, 16				;undo the changes to stack pointer
	pop		rbp					;undo changes to stack base
	ret

swap_n:
	mov		rcx, rsi			;use n instead of s1's length
	inc		rcx					;extra space for null terminator
	jmp		post_swap

null_terminate:
	dec rdi					;replace last character with null
	mov	byte [rdi], 0x0		;set null terminator
	jmp	return
