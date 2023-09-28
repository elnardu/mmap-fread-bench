#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <stdlib.h>


int main() {
    char *filename = "test.txt";
    FILE *fp = fopen(filename, "r");

    size_t bufsize = getpagesize() * 10;
    printf("bufsize = %zu\n", bufsize);
    void * buf = malloc(bufsize);

    size_t counter = 0;

    while (true) {
        size_t len = fread(buf, 1, bufsize, fp);
        if (len == 0) break;

        for (size_t i = 0; i < len; i++) {
            if (((char *)buf)[i] == 'a') {
                counter++;
            }
        }
    }

    printf("count = %zu\n", counter);
    return 0;
}