/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strstr
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>


Test(strstr, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    char *(*_strstr)(const char *haystack, const char *needle) = dlsym(dll, "strstr");

    cr_assert(_strstr("Hello world", "world") == strstr("Hello world", "world"));
    cr_assert(_strstr("programming is fun", "is") == strstr("programming is fun", "is"));
    cr_assert(_strstr("That computer is awesome", "computer") == strstr("That computer is awesome", "computer"));
    cr_assert(_strstr("Test test test", "test") == strstr("Test test test", "test"));
    cr_assert(_strstr("apple orange banana", "orange") == strstr("apple orange banana", "orange"));
    cr_assert(_strstr("cat dog bird", "dog") == strstr("cat dog bird", "dog"));
    cr_assert(_strstr("computer laptop tablet", "tablet") == strstr("computer laptop tablet", "tablet"));
    cr_assert(_strstr("house car bike", "house") == strstr("house car bike", "house"));
    cr_assert(_strstr("hello", "") == strstr("hello", ""));
    cr_assert(_strstr("", "") == strstr("", ""));
    cr_assert(_strstr("hello", "world") == strstr("hello", "world"));
    cr_assert(_strstr("apple", "pear") == strstr("apple", "pear"));

    dlclose(dll);
}