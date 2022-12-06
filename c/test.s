	.file	"test.c"
	.text
	.section	.rodata
	.align 8
.LC1:
	.string	"Convert from float my_float=%f to my_int=%d and my_ch=%c\r"
	.align 8
.LC2:
	.string	"Convert from int my_int=%d to my_float=%f and my_ch=%c\r"
	.align 8
.LC3:
	.string	"Convert from int my_ch=%c to my_int=%d and my_float=%f"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movl	%eax, -8(%rbp)
	movss	-12(%rbp), %xmm0
	cvttss2sil	%xmm0, %eax
	movl	%eax, -4(%rbp)
	pxor	%xmm1, %xmm1
	cvtss2sd	-12(%rbp), %xmm1
	movq	%xmm1, %rax
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %ecx
	movl	%ecx, %esi
	movq	%rax, %xmm0
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$69, -8(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-8(%rbp), %xmm0
	movss	%xmm0, -12(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	pxor	%xmm2, %xmm2
	cvtss2sd	-12(%rbp), %xmm2
	movq	%xmm2, %rcx
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	movq	%rcx, %xmm0
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$42, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ssl	-4(%rbp), %xmm0
	movss	%xmm0, -12(%rbp)
	pxor	%xmm3, %xmm3
	cvtss2sd	-12(%rbp), %xmm3
	movq	%xmm3, %rcx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movq	%rcx, %xmm0
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1117171876
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
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
