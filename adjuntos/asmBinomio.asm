    global asmBinomio
    section .text

asmBinomio:

    xorpd xmm2,xmm2 
    xorpd xmm3,xmm3 
    xorpd xmm4,xmm4

next:
    mov rax,rdi ; movemos el valor de N (rdi) a rax

    cvtsi2ss xmm2, rax ; Convertimos el valor entero de rax a float en xmm2

    movss xmm3, xmm2

    mulss xmm2,xmm2

    addss xmm4, xmm2; Llevamos la cuenta

    mulss xmm0, xmm3 ; 0.5* X

    addss xmm4, xmm0

    subss xmm4, xmm1 ; resultado-3.75


done:

    movss [rsi],xmm4
    ret
