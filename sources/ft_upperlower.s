global	_ft_upperlower

;int	ft_upperlower(int c)

section .text
_ft_upperlower:
	mov	rax, rdi	;save arg to rax
	cmp	rax, 'z'	;compare against z
	jg	check_upper	;jump to return without change to c
	cmp	rax, 'a'	;compare against a
	jl	check_upper	;jump to return without change to c
	sub	rax, 32		;set 6th bit to 0
	ret

check_upper:
	cmp	rax, 'Z'	;compare against Z
	jg	exit_same	;jump to return without change to c
	cmp	rax, 'A'	;compare against A
	jl	exit_same	;jump to return without change to c
	add	rax, 32		;set 6th bit to 1

exit_same:
	ret

