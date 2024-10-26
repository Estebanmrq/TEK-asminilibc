/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_memset
*/


#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>

Test(memset, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    void *(*_memset)(void *s, int c, size_t n) = dlsym(dll, "memset");

    char str1[10] = "abcdefghij";
    char str2[10] = "abcdefghij";

    _memset(str1, 'x', 5);
    memset(str2, 'x', 5);
    cr_assert(memcmp(str1, str2, 10) == 0);

    _memset(str1, 'y', 0);
    memset(str2, 'y', 0);
    cr_assert(memcmp(str1, str2, 10) == 0);

    _memset(str1, 'z', 15);
    memset(str2, 'z', 15);
    cr_assert(memcmp(str1, str2, 10) == 0);

    dlclose(dll);
}
