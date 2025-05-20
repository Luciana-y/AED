cmake_minimum_required(VERSION 3.26)
project(AED_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(AED_1 main.cpp)
add_executable(Simply likedList/Simply.cpp)
add_executable(Doubly likedList/Doubly.cpp)
add_executable(Stack StackQueue/Stack.cpp)
add_executable(CircularQueue StackQueue/CircularQueue.cpp)
add_executable(HashTable HashMap/HashTable_.cpp)
