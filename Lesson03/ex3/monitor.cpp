#include <iostream>
#include <cstdlib>
#include <cstdio>
template <typename T> class TD;

namespace {
void *g_pointers[20] = {nullptr};

struct FileData
{
    FILE* m_stream;
    const char* m_name;
};

FileData g_fileData[20] {};

void add_file(FILE* stream, const char* name)
{
    for(auto& data : g_fileData)
    {
        if (data.m_stream == nullptr)
        {
            data.m_stream = stream;
            data.m_name = name;
            break;
        }
    }
}

void remove_file(FILE* stream)
{
    for(auto& data : g_fileData)
    {
        if (data.m_stream == stream )
        {
            data.m_stream = nullptr;
            data.m_name = "Cleared";
            break;
        }
    }
}

void add_pointer(void *p)
{
    for(auto& ptr : g_pointers)
    {
        if (ptr == nullptr)
        {
            ptr = p;
            break;
        }
    }
}

void remove_pointer(void *p)
{
    for(auto& ptr : g_pointers)
    {
        if (ptr == p)
        {
            ptr = nullptr;
        }
    }
}

};

void init_monitor()
{
    for(auto& ptr : g_pointers)
    {
        ptr = nullptr;
    }
    for(auto& data : g_fileData)
    {
        data.m_stream = nullptr;
        data.m_name = "empty";
    }
}

void dump_monitor()
{
    bool first{true};
    int i{0};
    for(auto& ptr : g_pointers)
    {
        if (ptr != nullptr)
        {
            if (first)
            {
                std::cout << "Leaked Memory Pointers...\n";
                first = false;
            }
            std::cout << "    " << i << ": " << ptr << "\n"; 
        }
        ++i;
    }
    if (first)
    {
        std::cout << "No Leaked Memory\n";
    }

    first = true;
    i = 0;
    for(auto& fh : g_fileData)
    {
        if (fh.m_stream != nullptr)
        {
            if (first)
            {
                std::cout << "Leaked Files...\n";
                first = false;
            }
            std::cout << "    " << i << ": " << fh.m_name << "\n"; 
        }
        ++i;
    }
    if (first)
    {
        std::cout << "No Leaked Files\n";
    }
}


void * operator new(decltype(sizeof(0)) n) noexcept(false)
{
    auto p = std::malloc(n);
    add_pointer(p);
    return p;
}

void operator delete(void * p) throw()
{
    remove_pointer(p);
    std::free(p);
}


FILE* myfopen(const char* filename, const char* mode)
{
    FILE* stream = fopen(filename, mode);
    add_file(stream, filename);
    return stream;
}

int myfclose(FILE* stream)
{
    remove_file(stream);
    return fclose(stream);
}
