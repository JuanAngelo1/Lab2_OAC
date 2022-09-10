    global asmFloatNormTwo
    section .text

asmFloatNormTwo:


    xorpd xmm0, xmm0    ;extern void(float *,int,float *)
                        
    xorpd xmm1, xmm1    ;Limpiar registros

    cmp rsi,0
    je done

next:
    movss xmm0, [rdi] ;Guarda el valor de rdi en xmm0, xmm0 vale lo que lo vale rdi
    mulss xmm0, xmm0
    addss xmm1, xmm0

    add rdi, 4 ;Como es un dato tipo float contiene 4 bytes, por lo que v[2] esta 4 bytes mas adelante. v[0]+4bytes )

    sub   rsi,  1
    jnz next


done:
    sqrtss xmm1, xmm1
    movss [rdx], xmm1 ;Guarda la direccion de xmm1 en el valor de rdx, rdx vale la direccion de xmm1
    ret
