#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
 

void handle_interrupt(int signum) {
    printf("PCI Interrupt Received! Signal Number: %d\n", signum);
}
 
int main() {
    
    if (signal(SIGINT, handle_interrupt) == SIG_ERR) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
    }
 
    
    while (1) {
        printf("Main Loop: Working...\n");
        sleep(1);
    }
 
    return 0;
}



