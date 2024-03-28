#include <stdio.h>
#include <math.h>

int binaryToDecimal(int binary) {
    int decimal = 0, base = 0, rem;
    while (binary > 0) {
        rem = binary % 10;
        decimal += rem * pow(2, base);
        binary /= 10;
        base++;
    }
    return decimal;
}

int binaryToOctal(int binary) {
    int octal = 0, decimal = 0, base = 1;
    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    base = 1;
    while (decimal > 0) {
        octal += (decimal % 8) * base;
        decimal /= 8;
        base *= 10;
    }
    return octal;
}

// Function to convert binary to hexadecimal
void binaryToHexadecimal(int binary) {
    int decimal = binaryToDecimal(binary);
    char hexadecimal[100];
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[i] = remainder + 48;
        } else {
            hexadecimal[i] = remainder + 55;
        }
        i++;
        decimal /= 16;
    }
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

int main() {
    int binary;
    printf("Enter a binary number: ");
    scanf("%d", &binary);

    int decimal = binaryToDecimal(binary);
    int octal = binaryToOctal(binary);

    printf("Decimal: %d\n", decimal);
    printf("Octal: %d\n", octal);
    binaryToHexadecimal(binary);

    return 0;
}


