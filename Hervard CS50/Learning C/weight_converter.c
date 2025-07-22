#include <stdio.h>

int main() {
    int choice = 0;
    double kg = 0.0;
    double pound = 0.0;

    printf("Weight Converter\n");
    printf("1. KG to Pound\n");
    printf("2. Pound to KG\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter weight in KG: ");
        scanf("%lf", &kg);
        pound = kg * 2.20462;
        printf("Weight in Pounds: %.2lf\n", pound);
    } else if (choice == 2) {
        printf("Enter weight in Pounds: ");
        scanf("%lf", &pound);
        kg = pound / 2.20462;
        printf("Weight in KG: %.2lf\n", kg);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
