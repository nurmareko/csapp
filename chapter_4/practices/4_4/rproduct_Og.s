	.file	"rproduct.c"
	.text
	.globl	rsum
	.def	rsum;	.scl	2;	.type	32;	.endef
	.seh_proc	rsum
rsum:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	testq	%rdx, %rdx
	jle	.L3
	movq	(%rcx), %rbx
	subq	$1, %rdx
	addq	$8, %rcx
	call	rsum
	addq	%rbx, %rax
.L1:
	addq	$32, %rsp
	popq	%rbx
	ret
.L3:
	movl	$0, %eax
	jmp	.L1
	.seh_endproc
	.ident	"GCC: (Rev7, Built by MSYS2 project) 13.1.0"
