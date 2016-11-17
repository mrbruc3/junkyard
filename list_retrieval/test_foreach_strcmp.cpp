#include <boost/unordered_map.hpp>

#include <iostream>
#include <string>
#include <sstream>

#include "config.h"
#include "misc.h"

int main(int argc, char *argv[])
{
    long it = getIt(argc, argv);
    int st  = getSt(argc, argv);

    stringmapunordered cache;

    for(int i=0; i<st; i++) 
    {
        std::stringstream key;
        
        key << "SOME_KEY_LONGLONGLONG_" << i;
    
        cache[key.str()] = i;
    }

    std::string findKey = "SOME_KEY_LONGLONGLONG_3";

    int matches = 0;

    double start = getTime();

    for(int i=0; i<it; ++i) {
        std::unordered_map<std::string,int>::iterator it;
        for (it=cache.begin(); it != cache.end(); ++it) {
            if (it->first == findKey) {
                matches++;
            }
        }
    }

    double end = getTime();

    std::cout << "  matches: " << matches << std::endl;

    printTime(start, end);

    return 0;
}
