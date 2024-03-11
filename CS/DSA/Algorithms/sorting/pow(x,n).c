#include <stdio.h>

double pow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }

    double half_power = pow(x, n / 2);
    printf("half power is %f",half_power);

    if (n % 2 == 0) {
        printf("returning with halfpower");
        return half_power * half_power;
    } else {
        return half_power * half_power * x;
    }
}

int main() {
    double x = 2.0;
    int n = 10;

    double result = pow(x, n);
    printf("result %.5f\n",result);

    return 0;
}


