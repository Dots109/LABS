#include <stdio.h>
int m[1000][1000];
int fchange(int max, int min, int n, int st) {
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (m[i][j] >= max) { m[i][j] = st; }
        }
    }
}

int fst(int min, int n){
    int st = 0;
    for(int j = 0 ; j != n ; ++j){
        for(int i = 0 ; i !=n ; i++){
            if(m[i][j] == min) { st++; break;}
        }

    }
    return st;
}

int findmax(int max, int n){
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (m[i][j] >= max) { max = m[i][j]; }
        }
    }
    return max;
}

int findmin(int min, int n){
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (m[i][j] <= min) { min = m[i][j]; }
        }
    }
    return min;
}

int main(void)
{
    int i;
    int min = 9999;
    int max = -9999;
    int max_i;
    int min_i;
    int sym = 0;
    int st = 0;
//считываем матрицу
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            scanf("%d", &m[i][j]);
        }
    }
    if ( n == 1){
        printf("Менять нечего(\n %d ", m[0][0]);}
    if( n != 1){
        //найдем значение максимального элемента матрицы
        max = findmax(max, n);
        //найдем значение минимального элемента матрицы
        min = findmin(min, n);
        //найдем количество столбцов с минимальным элементом
        st = fst(min, n);
        //замена всех максимальных элементов матрицы на st
        fchange(max, min, n, st);
        //выведем на экран получившуюся матрицу
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}