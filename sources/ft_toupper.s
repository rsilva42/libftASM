global	_ft_toupper

;int	ft_toupper(int c)

section .text
_ft_toupper:
	mov	rax, rdi	;save arg to rax
	cmp	rax, 'z'	;compare against z
	jg	exit_same	;jump to return without change to c
	cmp	rax, 'a'	;compare against a
	jl	exit_same	;jump to return without change to c
	sub	rax, 32		;set 6th bit to 0
exit_same:
	ret
