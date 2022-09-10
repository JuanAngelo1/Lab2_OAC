#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern float asmMediana(int N ,float *v1);
void cMediana(int N ,float *v1, float *n2);;
float calcRelErr(float ref, float cal);

int main(){

    float *v1,n2C,n2Asm;
    int N=2048;
    v1=malloc(N*sizeof(float));

    int i=0;
    srandom(time(NULL));
    for(i=0;i<N;i++){
        float e=random()%256;
        v1[i]=e;

    }

    struct timespec ti,tf;
    double elapsed;

    clock_gettime(CLOCK_REALTIME,&ti);
    cMediana(N,v1,&n2C);
    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en C es: %lf \n",elapsed);


    clock_gettime(CLOCK_REALTIME,&ti);

    n2Asm=asmMediana(N,v1);

    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en ASM es: %lf \n",elapsed);


    printf("%f\n%f\n",n2C,n2Asm);

    float relerr = calcRelErr(n2C, n2Asm);
    printf("el error relativo es %f\n", relerr);

    return 0;
};

void cMediana(int N ,float *v1, float *n2){

    float mediana;
    int mitad=N/2;

    if(N%2==0){   
        mediana=(v1[mitad-1]+v1[mitad])/2;

    }else{
        mediana=v1[mitad];
    }

    n2[0]=mediana;
}

float calcRelErr(float ref, float cal)
{
    return fabsf(ref - cal) / fabsf(ref);
}