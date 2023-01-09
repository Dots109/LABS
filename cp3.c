#include <stdio.h> 
#include <math.h> 
#include <float.h>
 
long double function(long double x){ 
    return (1 / (2*x - 5)); 
} 
 
int main(){ 
    long double a = 0.0;   
    long double b = 2.0; 
    int n;
    printf("Input n please : \n");
    scanf("%d", &n);
    printf("Machine epsilon is equal to: %Lg\n\n", LDBL_EPSILON); 
 
    printf("        Table of values of Taylor series and standard function\n");     
printf("_______________________________________________________________________________\n"); 
    printf("|   x   |  sum of Taylor series  |  f(x) function value  |number of iterations|\n"); 
    
printf("_______________________________________________________________________________\n"); 
 
    long double x = 0; 
    long double step = (b - a) / n; 
    long double taylor, sum;
    int i = 0;
   for (long double x = a + step ; x < b + step ; x += step){
        for (int n = 1; n < 100; n++) {
            taylor = powl(2, (n - 1)) * powl(x, (n - 1)) / powl(5, n);
            sum += taylor;
            if (fabsl(sum - function(x)) < LDBL_EPSILON || i > 100) {
                break;
            }
        }
        i += 1;
        printf("|%.3Lf|%.20Lf|%.19Lf|           %d          |\n", x, sum, function(x), i - 1);
        sum = 0;
    }

 
    
printf("_______________________________________________________________________________\n"); 
 
    return 0; 
} 
