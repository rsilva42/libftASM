global	_ft_tolower

;int	ft_tolower(int c)

section .text
_ft_tolower:
	mov	rax, rdi	;save arg to rax
	cmp	rax, 'Z'	;compare against Z
	jg	exit_same	;jump to return without change to c
	cmp	rax, 'A'	;compare against A
	jl	exit_same	;jump to return without change to c
	add	rax, 32		;set 6th bit to 1
exit_same:
	ret
