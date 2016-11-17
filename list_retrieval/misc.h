
#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

typedef std::map<std::string, int>                 stringmap;
typedef std::unordered_map<std::string, int>       stringmapunordered;
typedef std::map<std::pair<int, std::string>, int> stringmappair;

int find_in_optimized_map(std::string& key, stringmappair& cache);

double getTime();
void   printTime(double start, double end);

int getIt(int argc, char *argv[]);
int getSt(int argc, char *argv[]);

