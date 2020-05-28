	.text
	.file	"Factorial.ll"
	.globl	factorial_int           # -- Begin function factorial_int
	.p2align	4, 0x90
	.type	factorial_int,@function
factorial_int:                          # @factorial_int
	.cfi_startproc
# %bb.0:
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movl	%edi, 12(%rsp)
	testl	%edi, %edi
	jne	.LBB0_3
# %bb.1:                                # %then0
	movl	$1, %eax
	jmp	.LBB0_2
.LBB0_3:                                # %ifCont0
	movl	12(%rsp), %ebx
	leal	-1(%rbx), %edi
	callq	factorial_int
	imull	%ebx, %eax
.LBB0_2:                                # %then0
	addq	$16, %rsp
	popq	%rbx
	retq
.Lfunc_end0:
	.size	factorial_int, .Lfunc_end0-factorial_int
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	%rsi, 16(%rsp)
	movl	$7, 12(%rsp)
	movl	$7, %edi
	callq	factorial_int
	movl	%eax, %ecx
	movl	$.str.int, %edi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	printf
	addq	$24, %rsp
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.str.true,@object       # @.str.true
	.section	.rodata,"a",@progbits
	.globl	.str.true
.str.true:
	.asciz	"true"
	.size	.str.true, 5

	.type	.str.false,@object      # @.str.false
	.globl	.str.false
.str.false:
	.asciz	"false"
	.size	.str.false, 6

	.type	.str.int,@object        # @.str.int
	.globl	.str.int
.str.int:
	.asciz	"%d"
	.size	.str.int, 3

	.type	.str.double,@object     # @.str.double
	.globl	.str.double
.str.double:
	.asciz	"%.16e"
	.size	.str.double, 6


	.section	".note.GNU-stack","",@progbits
