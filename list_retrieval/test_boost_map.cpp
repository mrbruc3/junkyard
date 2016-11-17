#include <map>
#include <vector>

#include <iostream>
#include <string>
#include <sstream>

#include "config.h"
#include "misc.h"

int main(int argc, char *argv[])
{
    long it = getIt(argc, argv);
    int  st = getSt(argc, argv);

    stringmap cache;

    for(int i=0; i<st; i++) 
    {
        std::stringstream key;
        
        key << "SOME_KEY_LONGLONGLONG_" << i;
    
        cache[key.str()] = i;
    }

    std::string findKey = "SOME_KEY_LONGLONGLONG_3";    

    int sum = 0;

    double start = getTime();

    for(int i=0; i<it; ++i) {
        sum += cache[findKey];
    }

    double end  = getTime();

    std::cout << "  sum " << sum << std::endl;

    printTime(start, end);

    return 0;
}
