#include <stdio.h>
#include <float.h>
#include <math.h>

long double f23(long double x) {
    return (3*x - 4*logl(x) - 5);      //3x - 4ln(x) - 5 = 0              
}
long double f23_der1(long double x) {
    return 3 - 4/x;
}

long double f23_der2(long double x) {
    return 4/pow(x, 2);
}

int IsNewtonConvergent(
        long double (*f)(long double),
        long double (*der1)(long double),
        long double (*der2)(long double),
        long double a,
        long double b) {
    int res = 1;
    long double step = (b - a) / 100;
    for (long double x = a; x <= b; x += step) {
        if (fabsl(f(x) * der2(x)) >= powl(der1(x), 2)) {
            res = 0;
        }
    }
    return res;
}

long double NewtonMethod(
        long double (*f)(long double),
        long double (*der)(long double),
        long double a,
        long double b) {
    long double x0 = (a + b) / 2;
    long double x1 = x0 - f(x0) / der(x0);
    while (fabsl(x1 - x0) >= LDBL_EPSILON) {
        x0 = x1;
        x1 = x0 - f(x0) / der(x0);
    }
    return x1;
}



int main() {

    int a = 2;
    int b = 4;
    printf("Function 23 (Newton Method):\n\t\t3x-4lnx-5 = 0\n");
    if (IsNewtonConvergent(f23, f23_der1, f23_der2, a, b)) {
        printf("Convergence check:\tOK!\n");

        long double root = NewtonMethod(f23, f23_der1, a, b);
        printf("Approximated root:\t%.10Lf\n", root);

        long double result = f23(root);
        printf("Result of inserting root:\t%.10Lf\n", result);
    } else {
        printf("Convergence check:\t FAIL!\n\n");
    }
}