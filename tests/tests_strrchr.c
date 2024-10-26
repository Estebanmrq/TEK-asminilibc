/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strrchr
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>

Test(strrchr, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    char *(*_strrchr)(const char *s, int c) = dlsym(dll, "strrchr");

    cr_assert(_strrchr("hello", 'l') == strrchr("hello", 'l'));
    cr_assert(_strrchr("world", 'd') == strrchr("world", 'd'));
    cr_assert(_strrchr("programming", 'm') == strrchr("programming", 'm'));
    cr_assert(_strrchr("testingall", 'a') == strrchr("testingall", 'a'));
    cr_assert(_strrchr("test", 't') == strrchr("test", 't'));
    cr_assert(_strrchr("apple", 'p') == strrchr("apple", 'p'));
    cr_assert(_strrchr("banana", 'n') == strrchr("banana", 'n'));
    cr_assert(_strrchr("orange", 'r') == strrchr("orange", 'r'));
    cr_assert(_strrchr("cat", 'z') == strrchr("cat", 'z'));
    cr_assert(_strrchr("", 'a') == strrchr("", 'a'));
    cr_assert(_strrchr("apple", 'l') == strrchr("apple", 'l'));
    cr_assert(_strrchr("banana", 'b') == strrchr("banana", 'b'));
    cr_assert(_strrchr("orange", 'g') == strrchr("orange", 'g'));
    cr_assert(_strrchr("cat", 't') == strrchr("cat", 't'));
    cr_assert(_strrchr("", 'x') == strrchr("", 'x'));
    cr_assert(_strrchr("apple", 'e') == strrchr("apple", 'e'));
    cr_assert(_strrchr("banana", 'a') == strrchr("banana", 'a'));
    cr_assert(_strrchr("orange", 'o') == strrchr("orange", 'o'));
    cr_assert(_strrchr("cat", 'c') == strrchr("cat", 'c'));
    cr_assert(_strrchr("apple", 'f') == strrchr("apple", 'f'));
    cr_assert(_strrchr("hello", 'z') == strrchr("hello", 'z'));
    cr_assert(_strrchr("hello", '\0') == strrchr("hello", '\0'));
    cr_assert(_strrchr("hello", 'h') == strrchr("hello", 'h'));

    dlclose(dll);
}
