%define	STDOUT			0x1
%define READ_SYSCALL	0x2000003
%define	WRITE_SYSCALL	0x2000004

global	_ft_cat

;void	ft_cat(int fd)

section .text
_ft_cat:
	push	rdi						;save fd for later
	mov		rax, READ_SYSCALL		;set syscall to read
	lea		rsi, [rel buff.cont]	;load address of buffer
	mov		rdx, buff.len			;set read buffer length
	syscall							;read from file

	mov		rdx, rax				;set write length from read return value
	mov		rax, WRITE_SYSCALL		;set syscall to write
	mov		rdi, STDOUT				;set write stream
	lea		rsi, [rel buff.cont]	;set to write from buffer
	syscall							;print buffer

	pop		rdi						;retrieve fd from stack
	cmp		rax, 0x0				;check if nothing was written
	jne		_ft_cat					;jump back if there is content left
	ret

section .data
buff:
	.cont times 8 db 0x0
	.len equ $ - buff
