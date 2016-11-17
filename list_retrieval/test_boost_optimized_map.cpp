#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <utility>

#include "misc.h"
#include "config.h"

int main(int argc, char *argv[])
{
    long it = getIt(argc, argv);
    int st  = getSt(argc, argv);

    stringmappair cache;

    for(int i=0; i<st; i++) 
    {
        std::stringstream key;
        
        key << "SOME_KEY_LONGLONGLONG_" << i;
    
        cache[std::make_pair(std::hash<std::string>{}(key.str()), key.str())] = i;
    }

    std::string findKey = "SOME_KEY_LONGLONGLONG_3";    

    int sum = 0;

    double start = getTime();

    for(int i=0; i<it; i++)
    {
        sum += find_in_optimized_map(findKey, cache);
    }

    double end = getTime();

    std::cout << "  sum " << sum << std::endl;

    printTime(start, end);

    return 0;
}
