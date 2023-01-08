#include <stdio.h>
#include <math.h>
#include <float.h>

//Метод дихотомии
long double func24(long double x){
    return ( cos(2/x) - 2*sin(1/x) + 1/x );
}

long double dixit(long double (*f)(long double), long double a, long double b){
    long double c;
    long double ans;
    while (fabsl(a - b) > LDBL_EPSILON) {
        c = (a + b) / 2.0;
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    ans = c;
    return ans;
}


int main() {
    //24 var function
    long double a = 1.0, 
                b = 2.0;
    printf("Func24 : cos(2/x) - 2*sin(1/x) + 1/x = 0 Method: dixit.\n%.19Lf", dixit(func24, a, b));
    
    printf("\n\n");
    
   
    return 0;
}