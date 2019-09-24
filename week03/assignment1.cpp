#include <iostream>

int data = 0;
int bss;
void code();

int main(){
        static const int rodata = 1;
	int* heap = new int[3];
	int stack[0];

        std::cout << "code\t" << (void*) code << std::endl;
        std::cout << "Rodata\t" << (void*) &rodata << std::endl;
        std::cout << "data\t" << &data << std::endl;
        std::cout << "BSS\t" << &bss << std::endl;
        std::cout << "HEAP\t" << heap << std::endl;
        std::cout << "Stack\t" << &stack << std::endl;
}

void code(){
}

