/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strncmp
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>

Test(strncmp, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    int (*_strncmp)(const char *s1, const char *s2, size_t n) = dlsym(dll, "strncmp");

    cr_assert(_strncmp("cat", "cat", 3) == strncmp("cat", "cat", 3));
    cr_assert(_strncmp("dog", "cat", 3) == strncmp("dog", "cat", 3));
    cr_assert(_strncmp("tree", "animal", 5) == strncmp("tree", "animal", 5));
    cr_assert(_strncmp("apple", "apple", 5) == strncmp("apple", "apple", 5));
    cr_assert(_strncmp("orange", "tangerine", 6) == strncmp("orange", "tangerine", 6));
    cr_assert(_strncmp("car", "bike", 3) == strncmp("car", "bike", 3));
    cr_assert(_strncmp("house", "house", 5) == strncmp("house", "house", 5));
    cr_assert(_strncmp("computer", "laptop", 8) == strncmp("computer", "laptop", 8));
    cr_assert(_strncmp("book", "newspaper", 4) == strncmp("book", "newspaper", 4));
    cr_assert(_strncmp("mouse", "mouse", 5) == strncmp("mouse", "mouse", 5));
    cr_assert(_strncmp("pen", "pencil", 2) == strncmp("pen", "pencil", 2));
    cr_assert(_strncmp("table", "chair", 3) == strncmp("table", "chair", 3));
    cr_assert(_strncmp("television", "radio", 10) == strncmp("television", "radio", 10));
    cr_assert(_strncmp("plane", "boat", 3) == strncmp("plane", "boat", 3));
    cr_assert(_strncmp("mountain", "beach", 5) == strncmp("mountain", "beach", 5));
    cr_assert(_strncmp("forest", "jungle", 5) == strncmp("forest", "jungle", 5));
    cr_assert(_strncmp("summer", "winter", 6) == strncmp("summer", "winter", 6));
    cr_assert(_strncmp("spring", "autumn", 6) == strncmp("spring", "autumn", 6));
    cr_assert(_strncmp("sun", "moon", 0) == strncmp("sun", "moon", 0));
    cr_assert(_strncmp("star", "planet", 0) == strncmp("star", "planet", 0));
    cr_assert(_strncmp("", "test", 0) == strncmp("", "test", 0));
    cr_assert(_strncmp("test", "", 0) == strncmp("test", "", 0));
    cr_assert(_strncmp("", "", 0) == strncmp("", "", 0));

    dlclose(dll);
}
