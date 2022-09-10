    global asmMediana
    section .text

asmMediana:

    xorpd xmm0,xmm0
    xorpd xmm1,xmm1
    xorpd xmm2,xmm2
   
    cmp rdi,0
    je done
    mov rax,0
    mov rdx,0
   
next:

    mov rbx,rdi
    ;ebx tiene el valor de rbx, rbx tiene el N
    
    mov eax,ebx ; eax funciona como diviendo

    mov ecx,2 ; -> ecx funciona como el divisor

    div ecx ; el resultado se almacena eax<- tiene el cociente
            ; el resiudo lo tiene rdx

    mov r13,rdx; Guardamos el valor del resiudo en r13 porque luego al hace MUL Se pierde

    mov r12,4
    mul r12
    add rsi, rax
    movss xmm0, [rsi]

    addss xmm1,xmm0

    cmp r13,0
    jnz done

par:
    sub rsi,4

    movss xmm0,[rsi]

    addss xmm1,xmm0

    ;Divide el resultado en 2


    mov eax,2
    cvtsi2ss xmm2,eax
    divss xmm1,xmm2


done:
    ;cvtsi2ss xmm0,rax
    movss xmm0,xmm1
    ret