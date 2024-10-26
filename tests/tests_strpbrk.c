/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strpbrk
*/


#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>


Test(strpbrk, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    char *(*_strpbrk)(const char *s, const char *accept) = dlsym(dll, "strpbrk");

    cr_assert(_strpbrk("hello world", "aeiou") == strpbrk("hello world", "aeiou"));
    cr_assert(_strpbrk("programming is fun", "1234567890") == strpbrk("programming is fun", "1234567890"));
    cr_assert(_strpbrk("This is a test", "abcdefghijklmnopqrstuvwxyz") == strpbrk("This is a test", "abcdefghijklmnopqrstuvwxyz"));
    cr_assert(_strpbrk("Test test test", "t") == strpbrk("Test test test", "t"));
    cr_assert(_strpbrk("apple orange banana", "aeiou") == strpbrk("apple orange banana", "aeiou"));
    cr_assert(_strpbrk("cat dog bird", "aeiou") == strpbrk("cat dog bird", "aeiou"));
    cr_assert(_strpbrk("computer laptop tablet", "abcdefghijklmnopqrstuvwxyz") == strpbrk("computer laptop tablet", "abcdefghijklmnopqrstuvwxyz"));
    cr_assert(_strpbrk("house car bike", "abcdefghijklmnopqrstuvwxyz") == strpbrk("house car bike", "abcdefghijklmnopqrstuvwxyz"));
    cr_assert(_strpbrk("hello", "world") == strpbrk("hello", "world"));
    cr_assert(_strpbrk("", "") == strpbrk("", ""));
    cr_assert(_strpbrk("", "abc") == strpbrk("", "abc"));
    cr_assert(_strpbrk("abc", "") == strpbrk("abc", ""));

    dlclose(dll);
}
