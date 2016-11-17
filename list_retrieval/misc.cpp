#include <iostream>

#include "misc.h"
#include "time.h"
#include "config.h"

int find_in_optimized_map(std::string& key, stringmappair& cache)
{
    std::pair<int, std::string> theKey;
    theKey.first  = std::hash<std::string>{}(key);
    theKey.second = key;
    
    return cache[theKey];
}

double getTime()
{
    struct timespec tp;

    clock_gettime(CLOCK_MONOTONIC, &tp);

    return tp.tv_sec + (tp.tv_nsec / 1000000000.0);
}


void printTime(double start, double end)
{
    std::cout << "  real " << (end - start) << " s" <<  std::endl << std::endl;
}



int getIt(int argc, char *argv[])
{
    long it = IT;

    if (argc > 1) 
    {
        it = atoi(argv[1]);
    }

    std::cout << argv[0] << std::endl;
    std::cout << "  iterations " << it << std::endl;

    return it;
}


int getSt(int argc, char *argv[])
{
    long st = ST;

    if (argc > 2) 
    {
        st = atoi(argv[2]);
    }

    std::cout << "  map size " << st << std::endl;

    return st;
}



