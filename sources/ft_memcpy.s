global	_ft_memcpy

;void	*ft_memcpy(void *dst, const void *src, size_t n)

section .text
_ft_memcpy:
	mov			rax, rdi	;set up return value
	mov			rcx, rdx	;set counter to n
	rep movsb				;copy from src to dst
	ret
