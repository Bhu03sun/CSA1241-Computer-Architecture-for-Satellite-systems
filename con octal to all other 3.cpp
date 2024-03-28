#include <stdio.h>

int octalToDecimal(int octal) {
    int decimal = 0, i = 0;
    
    while (octal != 0) {
        decimal += (octal % 10) * pow(8, i);
        ++i;
        octal /= 10;
    }
    
    return decimal;
}


void octalToHexadecimal(int octal) {
    int decimal = octalToDecimal(octal);
    printf("Hexadecimal: %X\n", decimal);
}

void octalToBinary(int octal) {
    int decimal = octalToDecimal(octal);
    int j;
    printf("Binary: ");
   
    int binary[32],i= 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int octal;

   
    printf("Enter an octal number: ");
    scanf("%o", &octal);

    
    printf("Decimal: %d\n", octalToDecimal(octal));
    octalToHexadecimal(octal);
    octalToBinary(octal);

    return 0;
}

