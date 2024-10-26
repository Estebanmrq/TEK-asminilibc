/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strlen
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>

Test(strlen, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    size_t (*_strlen)(const char *str) = dlsym(dll, "strlen");

    cr_assert(_strlen("cat") == strlen("cat"));
    cr_assert(_strlen("dog") == strlen("dog"));
    cr_assert(_strlen("tree") == strlen("tree"));
    cr_assert(_strlen("apple") == strlen("apple"));
    cr_assert(_strlen("orange") == strlen("orange"));
    cr_assert(_strlen("car") == strlen("car"));
    cr_assert(_strlen("house") == strlen("house"));
    cr_assert(_strlen("computer") == strlen("computer"));
    cr_assert(_strlen("book") == strlen("book"));
    cr_assert(_strlen("mouse") == strlen("mouse"));
    cr_assert(_strlen("pen") == strlen("pen"));
    cr_assert(_strlen("table") == strlen("table"));
    cr_assert(_strlen("television") == strlen("television"));
    cr_assert(_strlen("plane") == strlen("plane"));
    cr_assert(_strlen("mountain") == strlen("mountain"));
    cr_assert(_strlen("forest") == strlen("forest"));
    cr_assert(_strlen("summer") == strlen("summer"));
    cr_assert(_strlen("spring") == strlen("spring"));
    cr_assert(_strlen("sun") == strlen("sun"));
    cr_assert(_strlen("star") == strlen("star"));
    cr_assert(_strlen("") == strlen(""));
    
    dlclose(dll);
}
