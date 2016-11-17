#!/bin/bash


./test_foreach_regex $1 $2
./test_foreach_strcmp $1 $2
./test_boost_map $1 $2
./test_boost_unordered_map $1 $2
./test_boost_optimized_map $1 $2


