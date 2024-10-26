/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strchr
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>


Test(strchr, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    char *(*_strchr)(const char *s, int c) = dlsym(dll, "strchr");

    cr_assert(_strchr("hello", 'l') == strchr("hello", 'l'));
    cr_assert(_strchr("world", 'd') == strchr("world", 'd'));
    cr_assert(_strchr("programming", 'm') == strchr("programming", 'm'));
    cr_assert(_strchr("testingall", 'a') == strchr("testingall", 'a'));
    cr_assert(_strchr("test", 't') == strchr("test", 't'));
    cr_assert(_strchr("apple", 'p') == strchr("apple", 'p'));
    cr_assert(_strchr("banana", 'n') == strchr("banana", 'n'));
    cr_assert(_strchr("orange", 'r') == strchr("orange", 'r'));
    cr_assert(_strchr("cat", 'z') == strchr("cat", 'z'));
    cr_assert(_strchr("", 'a') == strchr("", 'a'));
    cr_assert(_strchr("apple", 'l') == strchr("apple", 'l'));
    cr_assert(_strchr("banana", 'b') == strchr("banana", 'b'));
    cr_assert(_strchr("orange", 'g') == strchr("orange", 'g'));
    cr_assert(_strchr("cat", 't') == strchr("cat", 't'));
    cr_assert(_strchr("", 'x') == strchr("", 'x'));
    cr_assert(_strchr("apple", 'e') == strchr("apple", 'e'));
    cr_assert(_strchr("banana", 'a') == strchr("banana", 'a'));
    cr_assert(_strchr("orange", 'o') == strchr("orange", 'o'));
    cr_assert(_strchr("cat", 'c') == strchr("cat", 'c'));
    cr_assert(_strchr("apple", 'f') == strchr("apple", 'f'));
    cr_assert(_strchr("hello", 'z') == strchr("hello", 'z'));
    cr_assert(_strchr("hello", '\0') == strchr("hello", '\0'));
    cr_assert(_strchr("hello", 'h') == strchr("hello", 'h'));

    dlclose(dll);
}
