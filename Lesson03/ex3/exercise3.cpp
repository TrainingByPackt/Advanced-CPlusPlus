#include <iostream>
#include "monitor.h"
#include <cstdio>

void LeakPointers()
{
    char* memory[5] {};
    for (auto i{0} ; i<5 ; i++)
    {
        memory[i] = new char[20];
        std::cout << "allocated 20 bytes @ " << (void *)memory[i] << "\n";
    }
}

void LeakFiles()
{
    FILE* fh1{fopen("HelloB1.txt", "w")};
    fprintf(fh1, "Hello B2\n");

    FILE* fh2{fopen("HelloB2.txt", "w")};
    fprintf(fh2, "Hello B1\n");
}

int main()
{
    std::cout << "\n\n------ Exercise 3 ------\n";
    Monitor monitor;
    LeakPointers();
    LeakFiles();
    std::cout << "------ Complete. -------\n";
    return 0;
}
