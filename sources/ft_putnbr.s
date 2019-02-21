%define	STDOUT			0x1
%define	WRITE_SYSCALL	0x2000004

global	_ft_putnbr

;void	ft_putnbr(int n)

section .text
_ft_putnbr:
	xor			rdx, rdx				;clear rdx to avoid div errors
	mov			rax, rdi				;mov n to rax
	cmp			eax, 0					;check if n is negative
	jl			is_neg

check_over_ten:
	mov			rcx, 10					;set divisor to 10
	div			rcx						;divide n by 10
	cmp			rax, 0					;check if n was greater than 10
	jg			recur					;recur with shifted value

pop_back:
	add			rdx, 48					;convert remainder from decimal to ascii
	mov			byte [rel char], dl		;set char to remainder
	call		ft_putchar				;print char
	ret

recur:
	push		rdx						;save remainder of earlier div
	mov			rdi, rax				;set ft_putnbr arg to n / 10
	call		_ft_putnbr				;recursive call
	pop			rdx						;retrieve remainder
	jmp			pop_back				;return to main logic

is_neg:
	push		rax						;save n for later
	mov			byte [rel char], '-'	;set char to '-'
	call		ft_putchar				;print '-'
	pop			rax						;retrieve n
	neg			eax						;convert n to positive
	jmp			check_over_ten			;jump back to main logic

ft_putchar:
	lea			rsi, [rel char]			;set write pointer to char's address
	mov			rdi, STDOUT				;set write stream
	mov			rdx, 1					;set write length
	mov			rax, WRITE_SYSCALL		;set syscall to write
	syscall								;print char
	ret

section .data
char:
	db	0x0
