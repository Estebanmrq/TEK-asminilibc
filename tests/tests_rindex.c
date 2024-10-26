/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_rindex
*/

#include <criterion/criterion.h>

#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

Test(rindex, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    char *(*_rindex)(const char *s, int c) = dlsym(dll, "rindex");

    cr_assert(_rindex("hello", 'l') == rindex("hello", 'l'));
    cr_assert(_rindex("world", 'd') == rindex("world", 'd'));
    cr_assert(_rindex("programming", 'm') == rindex("programming", 'm'));
    cr_assert(_rindex("testingall", 'a') == rindex("testingall", 'a'));
    cr_assert(_rindex("test", 't') == rindex("test", 't'));
    cr_assert(_rindex("apple", 'p') == rindex("apple", 'p'));
    cr_assert(_rindex("banana", 'n') == rindex("banana", 'n'));
    cr_assert(_rindex("orange", 'r') == rindex("orange", 'r'));
    cr_assert(_rindex("cat", 'z') == rindex("cat", 'z'));
    cr_assert(_rindex("", 'a') == rindex("", 'a'));
    cr_assert(_rindex("apple", 'l') == rindex("apple", 'l'));
    cr_assert(_rindex("banana", 'b') == rindex("banana", 'b'));
    cr_assert(_rindex("orange", 'g') == rindex("orange", 'g'));
    cr_assert(_rindex("cat", 't') == rindex("cat", 't'));
    cr_assert(_rindex("", 'x') == rindex("", 'x'));
    cr_assert(_rindex("apple", 'e') == rindex("apple", 'e'));
    cr_assert(_rindex("banana", 'a') == rindex("banana", 'a'));
    cr_assert(_rindex("orange", 'o') == rindex("orange", 'o'));
    cr_assert(_rindex("cat", 'c') == rindex("cat", 'c'));
    cr_assert(_rindex("apple", 'f') == rindex("apple", 'f'));
    cr_assert(_rindex("hello", 'z') == rindex("hello", 'z'));
    cr_assert(_rindex("hello", '\0') == rindex("hello", '\0'));
    cr_assert(_rindex("hello", 'h') == rindex("hello", 'h'));

    dlclose(dll);
}
