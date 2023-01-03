#include <stdio.h> 
#include <math.h> 
#include <float.h>
 
long double taylor(int n, long double x){     
    long double result = 0;    
    for (int i = 0; i <= n; ++i){ 
        result -= powl(2, (n - 1)) * powl(x, (n - 1)) / powl(5, n); 
    } 
    return result; 
} 
 
long double function(long double x){ 
    return (1 / (2*x - 5)); 
} 
 
int main(){ 
    long double a = 0.0;   
    long double b = 2.0; 
 
    int n = 100; 
 
    printf("Machine epsilon is equal to: %Lg\n\n", LDBL_EPSILON); 
 
    printf("        Table of values of Taylor series and standard function\n");     
printf("_______________________________________________________________________________\n"); 
    printf("|   x   |  sum of Taylor series  |  f(x) function value  |number of iterations|\n"); 
    
printf("_______________________________________________________________________________\n"); 
 
    long double x = 0; 
    long double step = (b - a) / n; 
    long double func = 1;   
    int i = 0; 
    while (fabsl(func) > LDBL_EPSILON && (i < 100) && (i < n)){    
        i += 1;    
        x += step; 
         func = function(x); 
 
         printf("| %.3Lf | %.20Lf | %.19Lf |         %d          |\n", x, taylor(i, x), func, i); 
    } 
 
    
printf("_______________________________________________________________________________\n"); 
 
    return 0; 
} 