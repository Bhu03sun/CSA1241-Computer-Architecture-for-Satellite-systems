#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
 

void handle_segfault(int signum) {
    printf("Segmentation Fault (Signal %d) - Exiting program\n", signum);
	exit(signum);
}
 
int main() {
	
	if (signal(SIGSEGV, handle_segfault) == SIG_ERR) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
	}
 
	
	int *ptr = NULL;
	*ptr = 10;  
 
	
	printf("This line will not be executed due to the segmentation fault.\n");
 
    return 0;
}

