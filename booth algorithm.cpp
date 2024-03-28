#include <stdio.h>

#define BITS 8

void booth_algorithm(int multiplier[], int multiplicand[], int product[]) {
    int accumulator[BITS * 2] = {0};
    int neg_multiplicand[BITS + 1];

    for (int i = 0; i < BITS; i++) {
        neg_multiplicand[i] = multiplicand[i];
    }
    neg_multiplicand[BITS] = 0;

    for (int i = 0; i < BITS; i++) {
        if (multiplier[0] == 1) {
            for (int j = 0; j < BITS * 2; j++) {
                accumulator[j] += neg_multiplicand[j];
                if (accumulator[j] > 1) {
                    accumulator[j] -= 2;
                    accumulator[j + 1] -= 1;
                }
            }
        }

        int last_bit = accumulator[BITS * 2 - 1];
        for (int j = BITS * 2 - 1; j > 0; j--) {
            accumulator[j] = accumulator[j - 1];
        }
        accumulator[0] = last_bit;
        last_bit = multiplier[BITS - 1];
        for (int j = BITS - 1; j > 0; j--) {
            multiplier[j] = multiplier[j - 1];
        }
        multiplier[0] = last_bit;
    }

    for (int i = 0; i < BITS; i++) {
        product[i] = accumulator[i];
    }
}

int main() {
    int multiplier[BITS] = {0, 1, 0, 1, 0, 0, 1, 1};
    int multiplicand[BITS] = {1, 1, 0, 0, 1, 0, 0, 1};
    int product[BITS] = {0};

    booth_algorithm(multiplier, multiplicand, product);

    printf("Product: ");
    for (int i = 0; i < BITS; i++) {
        printf("%d", product[i]);
    }
    printf("\n");

    return 0;
}




