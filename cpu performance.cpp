#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPERATIONS 1000000000 

int main() {
    clock_t start_time, end_time;
    double total_time;
    unsigned long i;
    
    start_time = clock(); 

    
    for (i = 0; i < OPERATIONS; i++) {
        
        int a = 5;
        int b = 10;
        int result = a + b;
    }

    end_time = clock(); 

    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; 

    printf("Total time taken: %f seconds\n", total_time);
    printf("CPU performance: %.2f operations per second\n", OPERATIONS / total_time);

    return 0;
}

