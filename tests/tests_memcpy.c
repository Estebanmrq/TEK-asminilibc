/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_memcpy
*/


#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>

Test(memcpy, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    void *(*_memcpy)(void *restrict dest, const void *restrict src, size_t n) = dlsym(dll, "memcpy");

    char src[20] = "This is a source.";
    char dest1[20];
    char dest2[20];

    _memcpy(dest1, src, 20);
    memcpy(dest2, src, 20);
    cr_assert(memcmp(dest1, dest2, 20) == 0);

    _memcpy(dest1, src + 8, 0);
    memcpy(dest2, src + 8, 0);
    cr_assert(memcmp(dest1, dest2, 20) == 0);


    cr_assert(memcmp(_memcpy(dest1, src, 10), memcpy(dest2, src, 10), 10) == 0);
    cr_assert(memcmp(_memcpy(dest1, src + 8, 0), memcpy(dest2, src + 8, 0), 20) == 0);

    _memcpy(dest1, src + 5, 10);
    memcpy(dest2, src + 5, 10);
    cr_assert(memcmp(dest1, dest2, 10) == 0);

    _memcpy(src + 5, src, 10);
    memcpy(src + 5, src, 10);
    cr_assert(memcmp(src + 5, src, 10) == 0);

    dlclose(dll);
}
