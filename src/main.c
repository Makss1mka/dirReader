#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/types.h>
#include <locale.h>
#include <getopt.h>
#include "./headers/dirReader.h"

int main(int argc, char* argv[]) {
    int opt;
    int opt_l = 0, opt_d = 0, opt_f = 0, opt_s = 0;
    char *dir = ".";

    while((opt = getopt(argc, argv, "ldfs")) != -1) {
        switch (opt) {
            case 'l': 
                opt_l = 1;
                break;
            case 'd': 
                opt_d = 1;
                break;
            case 'f': 
                opt_f = 1;
                break;
            case 's': 
                opt_s = 1;
                break;
            default:
                fprintf(stderr, "Unknown option");
                exit(1);   
        }
    } 

    if (optind < argc) dir = argv[optind];

    if (opt_s) setlocale(LC_COLLATE, "");

    dirReader(dir, opt_l, opt_d, opt_f, opt_s);

    return 0;
}
