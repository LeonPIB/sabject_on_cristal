#include <stdio.h>

#define N 5
#define M 6

// Функция для подсчёта положительных чисел
int count_positive(int array[N][M], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] > 0) {
                count++;
            }
        }
    }
    return count;
}

// Функция для подсчёта отрицательных чисел
int count_negative(int array[N][M], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] < 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int array[N][M] = {
        {1, -3, 4, -2, 6, -7},
        {8, -9, 10, -11, 12, -13},
        {14, 15, -16, -17, 18, -19},
        {20, -21, 22, 23, -24, 25},
        {-26, 27, 28, -29, 30, -31}
    };

    int pos_count = count_positive(array, N, M);
    int neg_count = count_negative(array, N, M);

    printf("Positive count: %d\n", pos_count);
    printf("Negative count: %d\n", neg_count);

    return 0;
}
