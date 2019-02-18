global	_ft_memset

;void	*ft_memset(void *b, int c, size_t len)

section .text
_ft_memset:
	mov			rcx, rdx	;set counter register to len
	mov			rdx, rdi	;save original address for return
	mov			rax, rsi	;make stos set byte to c
	rep stosb				;set bit to c (stosb looks at rdi for address)
	mov			rax, rdx	;set return value
	ret
