global	_ft_strncat

;char	*ft_strncat(char *s1, const char *s2, size_t n)

section .text
_ft_strncat:
	mov			rax, rdi			;set return pointer
	xor			rcx, rcx			;clear counter
	mov			r8, rdx				;save n for later

s1_end:
	mov			dl, [rdi]			;get the value at rdi address
	inc			rdi					;move to next byte in s1
	cmp			dl, 0x0				;compare byte to 0
	jne			s1_end				;jump while byte is not 0
	dec			rdi					;decrement to fix offset

s2_len:
	mov			dl, [rsi + rcx]		;get the value at rsi address
	inc			rcx					;increment counter
	cmp			dl, 0x0				;compare byte to 0
	jne			s2_len				;jump while byte is not 0
	cmp			rcx, r8				;compare s2 lengh with n
	jg			copy_n				;jump if length is greater
	rep movsb						;copy from s2 to s1
	ret

copy_n:
	mov			rcx, r8				;swap s2 length with n
	rep movsb						;copy from s2 to s1
	mov			byte [rdi], 0x0		;set nullterminator
	ret
