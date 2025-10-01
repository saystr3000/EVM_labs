#include <stdio.h>
#include <math.h>
#include <time.h>

double ln_1_plus_x(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            sum += pow(x, i) / i;
        } else {
            sum -= pow(x, i) / i;
        }
    }
    return sum;
}

int main() {
    struct timespec start, end;
    double result;
    double time_taken;

    // Массив значений n для тестирования
    int test_n[] = {300000000, 400000000, 550000000};
    int num_tests = 3;

    printf("Testing ln(1 + 0.5) for different n values:\n");
    printf("===========================================\n");

    for (int i = 0; i < num_tests; i++) {
        int n = test_n[i];

        // Замер времени начала
        clock_gettime(CLOCK_MONOTONIC_RAW, &start);

        // Вычисление результата
        result = ln_1_plus_x(0.5, n);

        // Замер времени окончания
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);

        // Вычисление времени выполнения
        time_taken = (end.tv_sec - start.tv_sec) +
                     0.000000001 * (end.tv_nsec - start.tv_nsec);

        // Вывод результатов
        printf("n = %d\n", n);
        printf("Result: %.15f\n", result);
        printf("Time taken: %.6f sec.\n", time_taken);
        printf("---\n");
    }

    return 0;
}


