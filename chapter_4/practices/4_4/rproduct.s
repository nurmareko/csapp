	.file	"rproduct.c"
	.text
	.globl	rsum
	.def	rsum;	.scl	2;	.type	32;	.endef
	.seh_proc	rsum
rsum:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	cmpq	$0, 40(%rbp)
	jg	.L2
	movl	$0, %eax
	jmp	.L3
.L2:
	movq	32(%rbp), %rax
	movq	(%rax), %rbx
	movq	40(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	32(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rcx
	call	rsum
	addq	%rbx, %rax
.L3:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev7, Built by MSYS2 project) 13.1.0"
