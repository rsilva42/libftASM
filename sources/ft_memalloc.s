extern	_malloc

global	_ft_memalloc

;void	*ft_memalloc(size_t size)

section .text
_ft_memalloc:
	push	rdi
	call	_malloc
	mov		rdi, rax
	mov		rdx, rax
	pop		rcx
	xor		rax, rax
	rep		stosb
	mov		rax, rdx
	ret
