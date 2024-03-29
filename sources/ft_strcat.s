global	_ft_strcat

;char	*ft_strcat(char *s1, const char *s2)

section .text
_ft_strcat:
	mov			rax, rdi			;set return pointer
	xor			rcx, rcx			;clear counter

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
	rep movsb						;copy from s2 to s1
	ret
