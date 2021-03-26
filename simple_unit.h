/**
 * Simple Unit
 * A simple header only library that enables fast unit testing in C projects.
 *
 * @author Marlon Chatman <mcchatman8009@gmail.com>
 *
 * @copyright Copyright (C) 2021 by Marlon Chatman <mcchatman8009@gmail.com>
 */
#ifndef HEADER_ONLY_SIMPLE_UNIT_H
#define HEADER_ONLY_SIMPLE_UNIT_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define describe_suite(text, code_block) \
    { \
        clock_t clock_before = clock(); \
        printf("%s\n", text); \
        code_block \
        double last_cock  = (double)clock(); \
        double clock_secs = ((last_cock - clock_before) / CLOCKS_PER_SEC); \
        clock_t clock_ms = (clock_t) (clock_secs * 1000); \
        printf("took %ldms %fsecs\n\n", clock_ms, clock_secs); \
    } \
    NULL

#define unit_test(text, code_block) \
    { \
        printf("   %s ", text); \
        code_block \
        printf("%s", "[PASSED]\n"); \
    } \
    NULL


#define test_assert(val) \
    if (!(val)) { \
        fprintf(stdout, "file:%s function:%s line:%d", __FILE__, __FUNCTION__, __LINE__); \
        fflush(stdout); \
        exit(1); \
    } \
    NULL


#define assert_true(val) \
    { \
    if(!(val)) { \
        printf("[FAILED]\n");  \
        fprintf(stdout,"assert_true(%s);\n", #val);  \
    } else { printf(""); } \
    test_assert(val); \
    } \
    NULL


#define assert_str_not_eq(lhs, rhs) \
    { \
        if(strcmp(lhs, rhs) == 0) { \
            printf("[FAILED]\n");  \
            fprintf(stdout,"assert_str_not_eq(%s, %s);\n", #lhs, #rhs);  \
        } else { printf(""); } \
        test_assert(strcmp(lhs, rhs) != 0); \
    } \
    NULL


#define assert_str_eq(lhs, rhs) \
    { \
        if(strcmp(lhs, rhs) != 0) { \
            printf("[FAILED]\n");  \
            fprintf(stdout,"assert_str_eq(%s, %s);\n", #lhs, #rhs);  \
        } else { printf(""); } \
        test_assert(strcmp(lhs, rhs) == 0); \
    } \
    NULL

#define assert_float_not_eq(lhs, rhs) \
    { \
        const double __eps = 0.00001f; \
        double __d = lhs - rhs; \
        int __res = fabs(__d) < __eps; \
        if((__res)) { \
            printf("[FAILED]\n");  \
            fprintf(stdout,"assert_float_not_eq(%s, %s);\n", #lhs, #rhs);  \
        } else { printf(""); } \
        test_assert(!__res); \
    } \
    NULL

#define assert_float_eq(lhs, rhs) \
    { \
        const double __eps = 0.00001f; \
        double __d = lhs - rhs; \
        int __res = fabs(__d) < __eps; \
        if(!(__res)) { \
            printf("[FAILED]\n");  \
            fprintf(stdout,"assert_float_eq(%s, %s);\n", #lhs, #rhs);  \
        } else { printf(""); } \
        test_assert(__res); \
    } \
    NULL

#define assert_not_eq(lhs, rhs) \
    { \
        if((lhs == rhs) ) { \
            printf("[FAILED]\n"); \
            fprintf(stdout," assert_not_eq(%s, %s);\n", #lhs, #rhs); \
        } else { printf(""); } \
        test_assert(lhs != rhs); \
    } \
    NULL

#define assert_eq(lhs, rhs) \
    { \
        if((lhs != rhs) ) { \
            printf("[FAILED]\n"); \
            fprintf(stdout," assert_eq(%s, %s);\n", #lhs, #rhs); \
        } else { printf(""); } \
        test_assert(lhs == rhs); \
    } \
    NULL

#endif

