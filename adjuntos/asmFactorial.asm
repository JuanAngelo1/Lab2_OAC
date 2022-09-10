    global asmFactorial
    section .text

asmFactorial:

    xorpd xmm1,xmm1 ; Limpiamos registro xmm1
    xorpd xmm2,xmm2

    cvtss2si eax, xmm0; float en xmm0 a int en eax

next:

    sub eax,1
    cmp eax,0
    jz done

    cvtsi2ss xmm1, eax ; Le paso el numero decrementado en 1 a xmm1

    mulss xmm0,xmm1

    jmp next

done:

    ret
