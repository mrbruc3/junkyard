cmake_minimum_required (VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)


# Test with regexp loop
add_executable(test_foreach_regex misc.cpp test_foreach_regex.cpp)
target_link_libraries(test_foreach_regex boost_regex)

# Test with strcmp loop
add_executable(test_foreach_strcmp misc.cpp test_foreach_strcmp.cpp)

# Test with map
add_executable(test_boost_map   misc.cpp test_boost_map.cpp)

# Test with unordered map
add_executable(test_boost_unordered_map  misc.cpp test_boost_unordered_map.cpp)

# Test with optimized map
add_executable(test_boost_optimized_map  misc.cpp test_boost_optimized_map.cpp)

