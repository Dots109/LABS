#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char m[2];

int absforchar(char a, char b){
    char p;
    if(a >= b) {  p = a - b; }
    if( a < b ) { p = b - a; }
    return p;
}

char f(){
    char  c, a, b, s, p;
    s = fgetc(stdin);
    a = s;
    s = fgetc(stdin);
    b = s;
    s = fgetc(stdin);
    c = s;
    m[0] = b;
    m[1] = c;
    p = absforchar(a, b);
    if( p == c - 48) { printf("%d ", p); }
}

int main() {
    char s, a, b;
    char c;
    f();
    b = m[0];
    c = m[1];
    while(s != EOF) {
        s = fgetc(stdin);
        a = b;
        b = c;
        c = s;
        char p = absforchar(a, b);
        if( p == c - 48) { printf("%d ", p); }
    }
    return 0;
}