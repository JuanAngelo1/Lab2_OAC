    global asmPromedio
    section .text

asmPromedio:
    xorpd xmm0,xmm0
    xorpd xmm1,xmm1
    xorpd xmm2,xmm2
    xorpd xmm3,xmm3

    mov r12,rdi
next:
    
    mov eax,[rsi] 
    cvtsi2ss xmm2,eax

    addss xmm1,xmm2 

    add rsi,4

    
    sub rdi,1
    jnz next

division:

    cvtsi2ss xmm3,r12 
    divss xmm1, xmm3


done:
    movss xmm0,xmm1
    ret