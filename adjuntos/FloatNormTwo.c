#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void asmFloatNormTwo(float *v1,int N, float *n2);
void cFloatNormTwo(float *v1,int N,float *n2);
float calcRelErr(float ref, float cal);

int main(){

    float *v1,n2C,n2Asm;
    int N=1024;
    v1=malloc(N*sizeof(float));

    int i=0;
    srandom(time(NULL));
    for(i=0;i<N;i++){
        float e=random()%3 + (-1);
        v1[i]=e;

    }

    struct timespec ti,tf;
    double elapsed;

    clock_gettime(CLOCK_REALTIME,&ti);
    cFloatNormTwo(v1,N,&n2C);
    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en C es: %lf \n",elapsed);


    clock_gettime(CLOCK_REALTIME,&ti);

    asmFloatNormTwo(v1,N,&n2Asm);

    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en ASM es: %lf \n",elapsed);


    //printf("%f\n%f\n",n2C,n2Asm);

    float relerr = calcRelErr(n2C, n2Asm);
    printf("el error relativo es %f\n", relerr);

    return 0;
};

void cFloatNormTwo(float *v1, int N, float *n2){

    int i=0;
    float sum=0;

    for(i =0;i<N;i++){
            sum+= v1[i]*v1[i];

    }

    n2[0]=sqrtf(sum);
}

float calcRelErr(float ref, float cal)
{
    return fabsf(ref - cal) / fabsf(ref);
}
