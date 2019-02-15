global _ft_isalpha

;int		_ft_isalpha(int c)

section .text
_ft_isalpha:
	mov	rax, rdi	;save arg to rax
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
