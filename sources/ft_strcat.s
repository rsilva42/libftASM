global	_ft_strcat

;char	*ft_strcat(char *s1, const char *s2)

section .text
_ft_strcat:
	mov			rax, rdi			;set return pointer
	xor			rcx, rcx			;clear counter

s1_end:
	inc			rdi					;move to next byte in s1
	mov			dx, [rdi]			;get the value at rdi address
	cmp			dx, 0				;compare byte to 0
	jne			s1_end				;jump while byte is not 0

s2_len:
	inc			rcx					;increment counter
	mov			dx, [rsi + rcx]		;get the value at rsi address
	cmp			dx, 0				;compare byte to 0
	jne			s2_len				;jump while byte is not 0
	rep movsb						;copy from s2 to s1
	ret
