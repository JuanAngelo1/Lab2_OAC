	global asmFloatInnerProd
	section .text

asmFloatInnerProd:
	xorpd	xmm0,	xmm0 ;impia los registros xmm0 xorpd es para float o double
	xorpd	xmm1,	xmm1
	xorpd	xmm2,	xmm2
	cmp	rdx,	0		;Compara el valor de N con 0, si es 0 je se acaba el programa
	je	done
next:
	movss	xmm0,	[rdi]	;Guarda el valor de rdi en xmm0 -> apunta al primer valor del arreglo de V1
	movss	xmm1,	[rsi]	;Guarda el valor de rsi en xmm1 -> apunta al primer valor del arreglo de V2
	mulss	xmm0,	xmm1	;Mutiplica el single-precision xmm0* xmm1 y lo guarda en xmm0
	addss	xmm2,	xmm0	;Suma xmm0 a xmm2 que contiene 0, es para llevar el resultado
	add	rdi,	4			;Añade a rdi 4 bytes, ya que es un float y rdi apunta a la direccion de memoria de V1: V1+4 bytes=>V1[2] 
	add	rsi,	4
	sub	rdx,	1			;Disminuye el contador en 1
	jnz	next	
done:
	movss	[rcx],	xmm2 	;Guarda la direccion de memoria de xmm2, donde se guardo la suma de los productos
	ret						;En rcx y lo devuelve