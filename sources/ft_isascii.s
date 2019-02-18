global	_ft_isascii

;int	ft_isascii(int c)

section .text
_ft_isascii:
	mov	rax, rdi	;save arg to rax
	cmp	rax, 127	;compare against 'del' (higest ascii value)
	jg	exit_z		;return 0 if rax is greater than 'del'
	cmp	rax, 0		;compare against 'nul' (lowest ascii value)
	jl	exit_z		;return 0 if rax is less than 'nul'
	mov	rax, 1		;set return value to 1
	ret

exit_z:
	xor	rax, rax	;clear return value to 0
	ret
