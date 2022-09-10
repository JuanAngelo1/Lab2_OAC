#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern float asmFactorial(float n);
float cFactorial(float n);
float calcRelErr(float ref, float cal);

int main(){

    float N=5;


    struct timespec ti,tf;
    double elapsed;

    clock_gettime(CLOCK_REALTIME,&ti);
    float result1=cFactorial(N);
    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en C es: %lf \n",elapsed);


    clock_gettime(CLOCK_REALTIME,&ti);

    float result2=asmFactorial(N);

    clock_gettime(CLOCK_REALTIME,&tf);

    elapsed=(tf.tv_sec-ti.tv_sec)*1e9 + (tf.tv_nsec-ti.tv_nsec);

    printf("El tiempo en nanosegundos en ASM es: %lf \n",elapsed);


    

    float relerr = calcRelErr(result1, result2);
    printf("el error relativo es %f\n", relerr);
    
    printf("%f\n%f\n",result1,result2);
    return 0;
};

float cFactorial(float n){
    float result=1;
    float producto;

    for(int i=1;i<n;i++){
        
        result+=i*result;
    }
    return result;
}

float calcRelErr(float ref, float cal)
{
    return fabsf(ref - cal) / fabsf(ref);
}