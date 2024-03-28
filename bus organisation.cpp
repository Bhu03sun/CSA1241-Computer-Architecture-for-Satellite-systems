#include <stdio.h>

typedef struct {
    int registers[4];
} CPU;

typedef struct {
    int data[100];
} Memory;

typedef struct {
    int data;
} IODevice;

typedef struct {
    int data;
} SingleBus;

int readFromMemory(CPU *cpu, Memory *memory, int address) {
    return memory->data[address];
}

void writeToMemory(CPU *cpu, Memory *memory, int address, int value) {
    memory->data[address] = value;
}

int readFromIODevice(CPU *cpu, IODevice *device) {
    return device->data;
}

void writeToIODevice(CPU *cpu, IODevice *device, int value) {
    device->data = value;
}

int main() {
    CPU cpu;
    Memory memory;
    IODevice ioDevice;
    SingleBus bus;

    int dataFromMemory = readFromMemory(&cpu, &memory, 0);
    writeToIODevice(&cpu, &ioDevice, dataFromMemory);

    int dataFromIODevice = readFromIODevice(&cpu, &ioDevice);
    writeToMemory(&cpu, &memory, 1, dataFromIODevice);

    printf("Simulation complete.\n");

    return 0;
}


