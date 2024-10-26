/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_index
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>


Test(index, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    char *(*_index)(const char *s, int c) = dlsym(dll, "index");

    cr_assert(_index("hello", 'l') == index("hello", 'l'));
    cr_assert(_index("world", 'd') == index("world", 'd'));
    cr_assert(_index("programming", 'm') == index("programming", 'm'));
    cr_assert(_index("testingall", 'a') == index("testingall", 'a'));
    cr_assert(_index("test", 't') == index("test", 't'));
    cr_assert(_index("apple", 'p') == index("apple", 'p'));
    cr_assert(_index("banana", 'n') == index("banana", 'n'));
    cr_assert(_index("orange", 'r') == index("orange", 'r'));
    cr_assert(_index("cat", 'z') == index("cat", 'z'));
    cr_assert(_index("", 'a') == index("", 'a'));
    cr_assert(_index("apple", 'l') == index("apple", 'l'));
    cr_assert(_index("banana", 'b') == index("banana", 'b'));
    cr_assert(_index("orange", 'g') == index("orange", 'g'));
    cr_assert(_index("cat", 't') == index("cat", 't'));
    cr_assert(_index("", 'x') == index("", 'x'));
    cr_assert(_index("apple", 'e') == index("apple", 'e'));
    cr_assert(_index("banana", 'a') == index("banana", 'a'));
    cr_assert(_index("orange", 'o') == index("orange", 'o'));
    cr_assert(_index("cat", 'c') == index("cat", 'c'));
    cr_assert(_index("apple", 'f') == index("apple", 'f'));
    cr_assert(_index("hello", 'z') == index("hello", 'z'));
    cr_assert(_index("hello", '\0') == index("hello", '\0'));
    cr_assert(_index("hello", 'h') == index("hello", 'h'));

    dlclose(dll);
}
