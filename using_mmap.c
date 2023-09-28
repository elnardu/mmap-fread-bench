#include <stdio.h>
#include <sys/mman.h>


int main() {
    char *filename = "test.txt";
    FILE *fp = fopen(filename, "r");

    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);

    void * ptr = mmap(NULL, len, PROT_READ, MAP_PRIVATE | MAP_NOCACHE, fileno(fp), 0);

    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (((char *)ptr)[i] == 'a') {
            counter++;
        }
    }

    printf("count = %d\n", counter);
    return 0;
}