global	_ft_memchr

;void	*ft_memchr(void *s, int c, size_t n)

section .text
_ft_memchr:
	mov			rax, rsi	;set scas to search for c
	mov			rcx, rdx	;set count to only go up to n
	repne scasb				;search for c in s
	cmp			rcx, 0x0	;check if counter is done (c not found)
	je			return_null
	mov			rax, rdi	;set return value
	dec			rax			;fix offset
	ret

return_null:
	xor			rax, rax
	ret
