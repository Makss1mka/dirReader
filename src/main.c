#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/dirReader.h"

int main(int argc, char* argv[]) {
    int opt;
    int opt_l = 0, opt_d = 0, opt_f = 0, opt_s = 0;
    char *dir = "."

    while((opt = getopt(argc, argv, "ldfs")) != -1) {
        if (opt = 'l') {
            opt_l = 1;
        } else if (opt = 'd') {
            opt_d = 1;
        } else if (opt = 'f') {
            opt_f = 1;
        } else if (opt = 's') {
            opt_s = 1;
        } else {
            fprintf(stderr, "Unknown option");
            exit(1);
        }
    } 

    if (optint < argc) dir = argv[optind];

    if (opt_s) setlocale(LC_COLLATE, "");

    dirReader(dir, opt_l, opt_d, opt_f, opt_s);

    return 0;
}
