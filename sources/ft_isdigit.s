global	_ft_isdigit

;int	ft_isdigit(int c)

section .text
_ft_isdigit:
	mov	rax, rdi	;save arg to rax
	cmp	rax, '9'	;compare against '9'
	jg	exit_z		;return 0 if rax is greater than '9'
	cmp	rax, '0'	;compare against '0'
	jl	exit_z		;return 0 if rax is less than '0'
	mov	rax, 1		;set return value to 1
	ret

exit_z:
	xor	rax, rax	;clear return value to 0
	ret
