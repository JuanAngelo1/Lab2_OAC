#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern float asmPromedio(int N, int *v1);
float cPromedio(int N, int *v1);
float calcRelErr(float ref, float cal);

int main(){

    int N=2048;

    int *v1;

    v1=malloc(N*sizeof(int));

    struct timespec ti,tf;
    double elapsed;

    int i;
    srandom(time(NULL));
  
    for(i=0;i<N;i++){
        int e=random()%256;
        v1[i]=e;

    }

    clock_gettime(CLOCK_REALTIME,&ti);
    float result1=cPromedio(N,v1);
    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en C es: %lf \n",elapsed);


    clock_gettime(CLOCK_REALTIME,&ti);

    float result2=asmPromedio(N,v1);

    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en ASM es: %lf \n",elapsed);


    float relerr = calcRelErr(result1, result2);
    printf("el error relativo es %f\n", relerr);
    
    printf("%f\n%f\n",result1,result2);
    return 0;
};

float cPromedio(int N, int *v1){
    int result=0;
    float divison;

    for(int i=0;i<N;i++){
        
        result+=v1[i];
    }

    divison=(float)result/N;

    return divison;
}

float calcRelErr(float ref, float cal)
{
    return fabsf(ref - cal) / fabsf(ref);
}