#include <iostream>
#include "monitor.h"
#include <cstdio>

class File {
public:
    File(const char* name, const char* access) {
        m_file = fopen(name, access);
        if (m_file == nullptr) {
            throw std::ios_base::failure("failed to open file");
        }
    }

    ~File() {
        fclose(m_file);
    }

    operator FILE*() {
        return m_file;
    }
private:
    FILE* m_file{};
};

class CharPointer
{
public:
    void allocate(size_t size)
    {
        m_memory = new char[size];
    }

    ~CharPointer()
    {
        delete [] m_memory;
    }

    operator char*() { return m_memory;}

private:
    char* m_memory{};
};

void LeakPointers()
{
    CharPointer memory[5];
    for (auto i{0} ; i<5 ; i++)
    {
        memory[i].allocate(20);
        std::cout << "allocated 20 bytes @ " << (void *)memory[i] << "\n";
    }
}

void LeakFiles()
{
    File fh1{"HelloB1.txt", "w"};
    fprintf(fh1, "Hello B2\n");

    File fh2{"HelloB2.txt", "w"};
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
