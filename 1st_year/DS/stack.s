	.file	"stack.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rcx
	movq	32(%rbp), %rax
	movq	%rbx, %r8
	movq	%rax, %rdx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	stack
	.bss
	.align 16
stack:
	.space 20
	.globl	top
	.data
	.align 4
top:
	.long	-1
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Data:%d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$1, %ecx
	call	push
	movl	$2, %ecx
	call	push
	movl	$3, %ecx
	call	push
	movl	$4, %ecx
	call	push
	movl	$5, %ecx
	call	push
	movl	$6, %ecx
	call	push
	call	pop
	call	pop
	call	pop
	call	pop
	movl	top(%rip), %eax
	movl	%eax, -4(%rbp)
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	stack(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	subl	$1, -4(%rbp)
.L4:
	cmpl	$0, -4(%rbp)
	jns	.L5
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	isFULL
	.def	isFULL;	.scl	2;	.type	32;	.endef
	.seh_proc	isFULL
isFULL:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	top(%rip), %eax
	cmpl	$4, %eax
	jne	.L8
	movl	$1, %eax
	jmp	.L9
.L8:
	movl	$0, %eax
.L9:
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC1:
	.ascii "Stack overflow to add Data:%d\12\0"
	.text
	.globl	push
	.def	push;	.scl	2;	.type	32;	.endef
	.seh_proc	push
push:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	call	isFULL
	testl	%eax, %eax
	je	.L11
	movl	16(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L10
.L11:
	movl	top(%rip), %eax
	addl	$1, %eax
	movl	%eax, top(%rip)
	movl	top(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	stack(%rip), %rdx
	movl	16(%rbp), %eax
	movl	%eax, (%rcx,%rdx)
.L10:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC2:
	.ascii "Stack Underflow to remove Data\0"
	.text
	.globl	pop
	.def	pop;	.scl	2;	.type	32;	.endef
	.seh_proc	pop
pop:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	isEmpty
	testl	%eax, %eax
	je	.L14
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L13
.L14:
	movl	top(%rip), %eax
	subl	$1, %eax
	movl	%eax, top(%rip)
	nop
.L13:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	isEmpty
	.def	isEmpty;	.scl	2;	.type	32;	.endef
	.seh_proc	isEmpty
isEmpty:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	top(%rip), %eax
	cmpl	$-1, %eax
	jne	.L17
	movl	$1, %eax
	jmp	.L18
.L17:
	movl	$0, %eax
.L18:
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
