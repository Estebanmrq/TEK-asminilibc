/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_memfrob
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>

Test(memfrob, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    void *(*_memfrob)(void *str, size_t n) = dlsym(dll, "memfrob");

    char test1[] = "Hello, world!";
    char test1v[] = "Hello, world!";
    _memfrob(test1, sizeof(test1));
    memfrob(test1v, sizeof(test1v));
    cr_assert(memcmp(test1, test1v, sizeof(test1)) == 0);
    
    _memfrob(test1, sizeof(test1));
    memfrob(test1v, sizeof(test1v));
    cr_assert(memcmp(test1, test1v, sizeof(test1)) == 0);

    _memfrob(test1, sizeof(test1));
    memfrob(test1v, sizeof(test1v));
    cr_assert(memcmp(test1, test1v, sizeof(test1)) == 0);

    char test2[] = "1234567890";
    char test2v[] = "1234567890";
    _memfrob(test2, sizeof(test2));
    memfrob(test2v, sizeof(test2v));
    cr_assert(memcmp(test2, test2v, sizeof(test2)) == 0);
    
    int test3[] = {1, 3, 2, 4, 3, 3, 3, 5, 4};
    int test3v[] = {1, 3, 2, 4, 3, 3, 3, 5, 4};
    _memfrob(test3, sizeof(test3));
    memfrob(test3v, sizeof(test3v));
    cr_assert(memcmp(test3, test3v, sizeof(test3)) == 0);

    dlclose(dll);
}
