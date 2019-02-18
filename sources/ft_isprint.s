global	_ft_isprint

;int	ft_isprint(int c)

section .text
_ft_isprint:
	mov	rax, rdi	;save arg to rax
	cmp	rax, '~'	;compare against '~' (higest printable value)
	jg	exit_z		;return 0 if rax is greater than '~'
	cmp	rax, ' '	;compare against ' ' (lowest printable value)
	jl	exit_z		;return 0 if rax is less than ' '
	mov	rax, 1		;set return value to 1
	ret

exit_z:
	xor	rax, rax	;clear return value to 0
	ret
