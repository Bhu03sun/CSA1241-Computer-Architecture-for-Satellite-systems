#include <stdio.h>
 

int deviceStatus = 0;
 

void handleDeviceRequest(int request) {
	switch (request) {
    	case 1:
        	
            printf("Handling Request 1: Turning ON the device.\n");
    	    deviceStatus = 1;
        	break;
    	case 2:
        
            printf("Handling Request 2: Turning OFF the device.\n");
            deviceStatus = 0;
        	break;
    	default:
            printf("Unknown request. Ignoring.\n");
	}
}
 
int main() {
	int userRequest;
 
	while (1) {
    	
        printf("Enter device request (1: Turn ON, 2: Turn OFF, 0: Exit): ");
    	scanf("%d", &userRequest);
 
    	if (userRequest == 0) {
            printf("Exiting program.\n");
        	break;
    	}
 
    	
        handleDeviceRequest(userRequest);
 
    	
	    printf("Device Status: %s\n", (deviceStatus == 1) ? "ON" : "OFF");
	}
 
	return 0;
}

