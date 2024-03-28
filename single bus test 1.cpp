#include <iostream>


struct Bus {
    int data;
    int address;
};


struct CPU {
    Bus *bus;
};


struct Memory {
    Bus *bus;
    int data[100]; 
};


int memory_read(Memory *mem, int address) {
    return mem->data[address];
}


void memory_write(Memory *mem, int address, int data) {
    mem->data[address] = data;
}


int cpu_operation(CPU *cpu, int address) {
    
    Memory *mem = reinterpret_cast<Memory*>(cpu->bus);
    return memory_read(mem, address);
}

int main() {
    
    Bus system_bus;
    CPU cpu;
    Memory memory;
    cpu.bus = reinterpret_cast<Bus*>(&memory); 

   
    memory_write(&memory, 0, 10); 

    
    int data_read = cpu_operation(&cpu, 0);
    std::cout << "Data read by CPU: " << data_read << std::endl;

    return 0;
}



