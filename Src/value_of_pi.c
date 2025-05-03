#include <stdio.h>

int main() {
    long long int terms, i;
    double pi = 0.0;

    printf("Enter the number of terms for approximation: ");
    scanf("%lld", &terms);

    for (i = 0; i < terms; i++) {
        // Alternate sign: + for even i, - for odd i
        if (i % 2 == 0) {
            pi += 1.0 / (2 * i + 1);
        } else {
            pi -= 1.0 / (2 * i + 1);
        }
    }

    pi *= 4; // Multiply the sum by 4 to get π

    printf("Estimated value of Pi using %lld terms: %.15f\n", terms, pi);

    return 0;
}
