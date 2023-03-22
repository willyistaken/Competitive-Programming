	.file	"2292.cpp"
	.text
	.p2align 4
	.globl	_Z3minRiS_
	.type	_Z3minRiS_, @function
_Z3minRiS_:
.LFB0:
	.cfi_startproc
	endbr64
	movl	(%rdi), %eax
	movl	(%rsi), %edx
	cmpl	%edx, %eax
	cmovg	%edx, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3minRiS_, .-_Z3minRiS_
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	xorl	%ebp, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	xorl	%ebx, %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	.p2align 4,,10
	.p2align 3
.L4:
	call	getchar_unlocked@PLT
	cmpb	$47, %al
	jle	.L11
.L9:
	testb	$1, %al
	leal	1(%rbx), %edx
	leal	1(%rbp), %eax
	je	.L5
	cmpl	%ebp, %ebx
	cmovle	%edx, %eax
	movl	%eax, %ebx
	call	getchar_unlocked@PLT
	cmpb	$47, %al
	jg	.L9
.L11:
	movl	%ebp, %esi
	leaq	.LC0(%rip), %rdi
	xorl	%eax, %eax
	call	printf@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L5:
	.cfi_restore_state
	cmpl	%ebp, %ebx
	cmovle	%edx, %eax
	movl	%eax, %ebp
	jmp	.L4
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
