#include <stdio.h>
#include <math.h>

double ln_1_plus_x(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1){
            sum += pow(x, i) / i;
        }
        else {
            sum -= pow(x, i) / i;
        }
    }
    return sum;
}

int main() {
    double result = ln_1_plus_x(0.5, 150000000 );
    printf("%6f\n", result);
}
