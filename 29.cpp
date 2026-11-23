#include <stdio.h>

int main() {
    int state = 1600;
    int rate, capacity, lanes;

    printf("Enter rate in bits: ");
    scanf("%d", &rate);

    if (rate <= 0 || rate >= state || rate % 64 != 0) {
        printf("Invalid rate.\n");
        return 0;
    }

    capacity = state - rate;
    lanes = capacity / 64;

    printf("State size: %d bits\n", state);
    printf("Rate: %d bits\n", rate);
    printf("Capacity: %d bits\n", capacity);
    printf("Capacity lanes: %d\n", lanes);

    printf("Without permutation, capacity lanes remain zero.\n");

    return 0;
}