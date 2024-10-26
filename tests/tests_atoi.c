/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_atoi
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>


Test(atoi, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    int (*_atoi)(const char *nptr) = dlsym(dll, "atoi");

    cr_assert(_atoi("123") == atoi("123"));
    cr_assert(_atoi("0") == atoi("0"));
    cr_assert(_atoi("-456") == atoi("-456"));
    cr_assert(_atoi("987654") == atoi("987654"));
    cr_assert(_atoi("-789") == atoi("-789"));
    cr_assert(_atoi("42") == atoi("42"));
    cr_assert(_atoi("999") == atoi("999"));
    cr_assert(_atoi("2147483647") == atoi("2147483647"));
    cr_assert(_atoi("-2147483648") == atoi("-2147483648"));
    cr_assert(_atoi("abc123") == atoi("abc123"));

    dlclose(dll);
}
