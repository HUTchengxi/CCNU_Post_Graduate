# cmake_minimum_required(VERSION <specify CMake version here>)
project(CCNU_Post_Graduate C)

set(CMAKE_C_STANDARD 11)

add_executable(CCNU_Post_Graduate
        "算法/算法分析与设计教程/1. 递归/Coding/CommonDivisor/recursion.c"
        "算法/算法分析与设计教程/1. 递归/Coding/Fibonacci/non_recursion.c"
        "算法/算法分析与设计教程/1. 递归/Coding/Fibonacci/recursion.c"
        "算法/算法分析与设计教程/1. 递归/Coding/Hanoi/non_recursion.c"
        "算法/算法分析与设计教程/1. 递归/Coding/Hanoi/recursion.c"
        "算法/算法分析与设计教程/2. 分治/Coding/BigNumMultiply/bigNumMultiply.c"
        "算法/算法分析与设计教程/2. 分治/Coding/BigNumMultiply/divideAndConquer.c"
        "算法/算法分析与设计教程/2. 分治/Coding/BinarySearch/divideAndConquer.c"
        "算法/算法分析与设计教程/2. 分治/Coding/QuickSort/divideAndConquer.c"
        "算法/算法分析与设计教程/3. 贪心/Coding/DecimalPackage/greedy.c"
        "算法/算法分析与设计教程/3. 贪心/Coding/UniSourceMinLen/greedy.c")

add_executable(Temp 临时文件/Temp.c)