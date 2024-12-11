#include <stdio.h>

#define N 5
#define M 6

int main() {
    int array[N][M] = {
        {1, -3, 4, -2, 6, -7},
        {8, -9, 10, -11, 12, -13},
        {14, 15, -16, -17, 18, -19},
        {20, -21, 22, 23, -24, 25},
        {-26, 27, 28, -29, 30, -31}
    };

    int pos_count = 0, neg_count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (array[i][j] > 0)
                pos_count++;
            else if (array[i][j] < 0)
                neg_count++;
        }
    }

    printf("Positive count: %d\n", pos_count);
    printf("Negative count: %d\n", neg_count);

    return 0;
}
