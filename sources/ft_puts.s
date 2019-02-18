%define	STDOUT			0x1
%define	WRITE_SYSCALL	0x2000004

global	_ft_puts

;int	ft_puts(const char *s)

section .text
_ft_puts:
	cmp		rdi, 0x0
	jz		print_null
	mov		rsi, rdi				;set source register to s
	xor		rcx, rcx				;clear counter

s_len:
	inc			rcx					;increment counter
	mov			dl, [rsi + rcx]		;get the value at rdi address
	cmp			dl, 0x0				;compare byte to 0x0
	jne			s_len				;jump while byte is not 0x0
	mov			rdi, STDOUT			;set write stream
	mov			rdx, rcx			;set write length
	mov			rax, WRITE_SYSCALL	;set syscall to write
	syscall							;print s

print_nl:
	mov			rdi, STDOUT			;set write stream
	lea			rsi, [rel nl]		;load address of nl to write pointer
	mov			rdx, 1				;set write len
	mov			rax, WRITE_SYSCALL	;set syscall to write
	syscall							;print newline
	mov			rax, [rel nl]		;set return value
	ret

print_null:
	mov			rdi, STDOUT			;set write stream
	lea			rsi, [rel null]		;load address of nl to write pointer
	mov			rdx, 6				;set write len
	mov			rax, WRITE_SYSCALL	;set syscall to write
	syscall							;print newline
	jmp			print_nl

section .data
null:
	db	"(null)"

nl:
	db	10
