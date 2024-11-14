#include <stdio.h>

double sqrt_babylonian(double num, double epsilon) {
    double x = num;
    double y = 1;

    while (x - y > epsilon) {
        x = (x + y) / 2;
        y = num / x;
    }

    return x;
}

int main() {
    double num, root;

    printf("Enter a number: ");
    scanf("%lf", &num);

    // Calculate square root using Babylonian method
    root = sqrt_babylonian(num, 0.00001);

    printf("Square root of %.2f = %.2f\n", num, root);

    return 0;
}