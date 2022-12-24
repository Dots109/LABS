#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int d = 0; d < 2 * n - 1; ++d) {
        if (d < n) {                                    // диагонали до главной включительно
            if (d % 2 == 0) {                           // четная диагональ - идем вверх
                i = n - 1;
                j = d;
                for (; i >= 0 && j >= 0; --i, --j) {
                    printf("%d ", matrix[i][j]);
                }
            }
            else {                                       // нечетная диагональ - идем вниз
                i = n - 1 - d;
                j = 0;
                for (; i < n && j < n; ++i, ++j) {
                    printf("%d ", matrix[i][j]);
                }
            }
        } else {                                         // диагонали после главной
            if (d % 2 == 0) {                            // четная диагональ - идем вверх
                i = 2 * n - d - 2;
                j = n - 1;
                for (; i >= 0 && j >= 0; --i, --j) {
                    printf("%d ", matrix[i][j]);
                }
            }
            else {                                       // нечетная диагональ - идем вниз
                i = 0;
                j = d - n + 1;
                for (; i < n && j < n; ++i, ++j) {
                    printf("%d ", matrix[i][j]);
                }
            }
        }
    }
}