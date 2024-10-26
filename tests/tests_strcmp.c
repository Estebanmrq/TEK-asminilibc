/*
** EPITECH PROJECT, 2024
** MiniLibC
** File description:
** tests_strcmp
*/

#include <criterion/criterion.h>

#include <string.h>
#include <dlfcn.h>

Test(strcmp, basical) {
    void *dll = dlopen("libasm.so", RTLD_LAZY);
    int (*_strcmp)(const char *s1, const char *s2) = dlsym(dll, "strcmp");

    cr_assert(_strcmp("cat", "cat") == strcmp("cat", "cat"));
    cr_assert(_strcmp("dog", "cat") == strcmp("dog", "cat"));
    cr_assert(_strcmp("tree", "animal") == strcmp("tree", "animal"));
    cr_assert(_strcmp("apple", "apple") == strcmp("apple", "apple"));
    cr_assert(_strcmp("orange", "tangerine") == strcmp("orange", "tangerine"));
    cr_assert(_strcmp("car", "bike") == strcmp("car", "bike"));
    cr_assert(_strcmp("house", "house") == strcmp("house", "house"));
    cr_assert(_strcmp("computer", "laptop") == strcmp("computer", "laptop"));
    cr_assert(_strcmp("book", "newspaper") == strcmp("book", "newspaper"));
    cr_assert(_strcmp("mouse", "mouse") == strcmp("mouse", "mouse"));
    cr_assert(_strcmp("pen", "pencil") == strcmp("pen", "pencil"));
    cr_assert(_strcmp("table", "chair") == strcmp("table", "chair"));
    cr_assert(_strcmp("television", "radio") == strcmp("television", "radio"));
    cr_assert(_strcmp("plane", "boat") == strcmp("plane", "boat"));
    cr_assert(_strcmp("mountain", "beach") == strcmp("mountain", "beach"));
    cr_assert(_strcmp("forest", "jungle") == strcmp("forest", "jungle"));
    cr_assert(_strcmp("summer", "winter") == strcmp("summer", "winter"));
    cr_assert(_strcmp("spring", "autumn") == strcmp("spring", "autumn"));
    cr_assert(_strcmp("sun", "moon") == strcmp("sun", "moon"));
    cr_assert(_strcmp("star", "planet") == strcmp("star", "planet"));
    cr_assert(_strcmp("", "") == strcmp("", ""));
    cr_assert(_strcmp("", "z") == strcmp("", "z"));
    cr_assert(_strcmp("e", "") == strcmp("e", ""));

    dlclose(dll);
}
