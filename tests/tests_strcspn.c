/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strcspn
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>


Test(strcspn, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    size_t (*_strcspn)(const char *s, const char *reject) = dlsym(dll, "strcspn");

    cr_assert(_strcspn("hello world", "aeiou") == strcspn("hello world", "aeiou"));
    cr_assert(_strcspn("programming is fun", "1234567890") == strcspn("programming is fun", "1234567890"));
    cr_assert(_strcspn("This is a test", "abcdefghijklmnopqrstuvwxyz") == strcspn("This is a test", "abcdefghijklmnopqrstuvwxyz"));
    cr_assert(_strcspn("Test test test", "t") == strcspn("Test test test", "t"));
    cr_assert(_strcspn("apple orange banana", "aeiou") == strcspn("apple orange banana", "aeiou"));
    cr_assert(_strcspn("cat dog bird", "aeiou") == strcspn("cat dog bird", "aeiou"));
    cr_assert(_strcspn("computer laptop tablet", "abcdefghijklmnopqrstuvwxyz") == strcspn("computer laptop tablet", "abcdefghijklmnopqrstuvwxyz"));
    cr_assert(_strcspn("house car bike", "abcdefghijklmnopqrstuvwxyz") == strcspn("house car bike", "abcdefghijklmnopqrstuvwxyz"));
    cr_assert(_strcspn("hello", "world") == strcspn("hello", "world"));
    cr_assert(_strcspn("", "") == strcspn("", ""));
    cr_assert(_strcspn("", "abc") == strcspn("", "abc"));
    cr_assert(_strcspn("abc", "") == strcspn("abc", ""));

    dlclose(dll);
}
