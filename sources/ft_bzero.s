global	_ft_bzero

;void	ft_bzero(void *s, size_t n)

section .text
_ft_bzero:
	mov			rcx, rsi	;set counter register to n
	mov			rax, 0		;make stos set byte to 0
	rep stosb				;set bit to zero (stosb looks at rdi for address)
	ret
