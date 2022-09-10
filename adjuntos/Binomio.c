#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void asmBinomio(int x,float primero, float segundo, float *n2);
void cBinomio(int x,float primero, float segundo, float *n2);
float calcRelErr(float ref, float cal);

int main(){

    int x=10000;
    float n2C,n2Asm;
    float primero=0.5;
    float segundo=3.75;

    struct timespec ti,tf;
    double elapsed;

    clock_gettime(CLOCK_REALTIME,&ti);
    cBinomio(x,primero,segundo,&n2C);
    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en C es: %lf \n",elapsed);


    clock_gettime(CLOCK_REALTIME,&ti);

    asmBinomio(x,primero,segundo,&n2Asm);

    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en ASM es: %lf \n",elapsed);


    

    float relerr = calcRelErr(n2C, n2Asm);
    printf("el error relativo es %f\n", relerr);
    
    printf("%f\n%f\n",n2C,n2Asm);
    return 0;
}

void cBinomio(int x,float primero, float segundo, float *n2){

    float sum=0;

    sum=x*x+primero*x-segundo;

    n2[0]=sum;
}

float calcRelErr(float ref, float cal)
{
    return fabsf(ref - cal) / fabsf(ref);
}