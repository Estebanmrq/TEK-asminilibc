/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_memmove
*/


#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>

Test(memmove, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    void *(*_memmove)(void *restrict dest, const void *restrict src, size_t n) = dlsym(dll, "memmove");

    char str1[] = "Hello, World!";
    char str1r[] = "Hello, World!";

    _memmove(str1, str1 + 7, 7);
    _memmove(str1r, str1r + 7, 7);
    cr_assert(memcmp(str1, str1r, sizeof(str1)) == 0);

    _memmove(str1 + 7, str1 + 2, 7);
    _memmove(str1r + 7, str1r + 2, 7);
    cr_assert(memcmp(str1, str1r, sizeof(str1)) == 0);

    _memmove(str1 + 2, str1 + 7, 7);
    _memmove(str1r + 2, str1r + 7, 7);
    cr_assert(memcmp(str1, str1r, sizeof(str1)) == 0);

    _memmove(str1 + 7, str1, 0);
    _memmove(str1r + 7, str1r, 0);
    cr_assert(memcmp(str1, str1r, sizeof(str1)) == 0);

    dlclose(dll);
}
