/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strcasecmp
*/


#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>

Test(strcasecmp, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    int (*_strcasecmp)(const char *s1, const char *s2) = dlsym(dll, "strcasecmp");

    cr_assert(_strcasecmp("Hello", "hello") == strcasecmp("Hello", "hello"));
    cr_assert(_strcasecmp("world", "WORLD") == strcasecmp("world", "WORLD"));
    cr_assert(_strcasecmp("Programming", "PROGRAMMING") == strcasecmp("Programming", "PROGRAMMING"));
    cr_assert(_strcasecmp("TestingAll", "testingall") == strcasecmp("TestingAll", "testingall"));
    cr_assert(_strcasecmp("Test", "tEsT") == strcasecmp("Test", "tEsT"));
    cr_assert(_strcasecmp("apple", "APPLE") == strcasecmp("apple", "APPLE"));
    cr_assert(_strcasecmp("banana", "Banana") == strcasecmp("banana", "Banana"));
    cr_assert(_strcasecmp("orange", "ORANGE") == strcasecmp("orange", "ORANGE"));
    cr_assert(_strcasecmp("cat", "CAT") == strcasecmp("cat", "CAT"));
    cr_assert(_strcasecmp("", "") == strcasecmp("", ""));
    cr_assert(_strcasecmp("TeSt", "test") == strcasecmp("TeSt", "test"));
    cr_assert(_strcasecmp("Hello", "world") == strcasecmp("Hello", "world"));

    cr_assert(_strcasecmp("Hello!", "hello!") == strcasecmp("Hello!", "hello!"));
    cr_assert(_strcasecmp("world@", "WORLD@") == strcasecmp("world@", "WORLD@"));
    cr_assert(_strcasecmp("Programming#", "PROGRAMMING#") == strcasecmp("Programming#", "PROGRAMMING#"));
    cr_assert(_strcasecmp("testInGAll$", "TeStInGaLl$") == strcasecmp("testInGAll$", "TeStInGaLl$"));
    cr_assert(_strcasecmp("Test%", "tEsT%") == strcasecmp("Test%", "tEsT%"));
    cr_assert(_strcasecmp("apple^", "APPLE^") == strcasecmp("apple^", "APPLE^"));
    cr_assert(_strcasecmp("banana&", "Banana&") == strcasecmp("banana&", "Banana&"));
    cr_assert(_strcasecmp("orange*", "ORANGE*") == strcasecmp("orange*", "ORANGE*"));
    cr_assert(_strcasecmp("cat(", "CAT(") == strcasecmp("cat(", "CAT("));
    cr_assert(_strcasecmp(")", ")") == strcasecmp(")", ")"));
    cr_assert(_strcasecmp("TeSt=", "test=") == strcasecmp("TeSt=", "test="));

    cr_assert(_strcasecmp("Hello!@", "hello!@") == strcasecmp("Hello!@", "hello!@"));
    cr_assert(_strcasecmp("world#$", "WORLD#$") == strcasecmp("world#$", "WORLD#$"));
    cr_assert(_strcasecmp("Programming%^", "PROGRAMMING%^") == strcasecmp("Programming%^", "PROGRAMMING%^"));
    cr_assert(_strcasecmp("TeStInGaLl$&*", "testingall&*") == strcasecmp("TeStInGaLl$&*", "testingall&*"));
    cr_assert(_strcasecmp("Test()$", "tEsT()$") == strcasecmp("Test()$", "tEsT()$"));
    cr_assert(_strcasecmp("apple^&", "APPLE^&") == strcasecmp("apple^&", "APPLE^&"));
    cr_assert(_strcasecmp("banana=@#", "Banana=@#") == strcasecmp("banana=@#", "Banana=@#"));
    cr_assert(_strcasecmp("orange{}[]", "ORANGE{}[]") == strcasecmp("orange{}[]", "ORANGE{}[]"));
    cr_assert(_strcasecmp("cat~", "CAT~") == strcasecmp("cat~", "CAT~"));
    cr_assert(_strcasecmp("*+@", "JK[") == strcasecmp("*+@", "JK["));
    cr_assert(_strcasecmp("`", "`") == strcasecmp("`", "`"));

    dlclose(dll);
}
