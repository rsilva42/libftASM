global	_ft_isalnum

;int	ft_isalnum(int c)

section .text
_ft_isalnum:

	mov	rax, rdi	;save arg to rax
	cmp	rax, '9'	;compare against '9'
	jg	is_alpha		;return 0 if rax is greater than '9'
	cmp	rax, '0'	;compare against '0'
	jl	is_alpha		;return 0 if rax is less than '0'
	mov	rax, 1		;set return value to 1
	ret

is_alpha:
	or	rax, 0x20	;set 6th bit to 1 (is 0 for uppercase, 1 for lowercase)
	cmp	rax, 'z'	;compare against z
	jg	exit_z		;return 0 if rax is greater than z
	cmp	rax, 'a'	;compare against a
	jl	exit_z		;return 0 if rax is less than a
	mov	rax, 1		;set return value to 1
	ret

exit_z:
	xor	rax, rax	;clear return value to 0
	ret
