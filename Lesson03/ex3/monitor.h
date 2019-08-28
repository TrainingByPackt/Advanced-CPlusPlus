#pragma once
#include <cstdio>

void init_monitor();
void dump_monitor();

struct Monitor
{
    Monitor() { 
        init_monitor();
    };
    ~Monitor() { 
        dump_monitor();
    };
};


FILE* myfopen(const char* filename, const char* mode);
int myfclose(FILE* stream);

#define fopen myfopen
#define fclose myfclose
