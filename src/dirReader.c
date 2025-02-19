#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <locale.h>

#define MAX_PATH 1024

void dirReader(const char *dir, int opt_l, int opt_d, int opt_f, int opt_s) {
    DIR* dp;
    struct dirent *entry;
    struct stat statbuf;
    char path[MAX_PATH];

    // Opening the direction
    if((dp = opendir(dir)) == NULL) {
        perror("Cannot open dir");
        return;
    }

    // Reading direction
    while((entry = readdir(dp)) != NULL) {
        // Skip . and ..
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get absolute path
        snprintf(path, MAX_PATH, "%s/%s", dir, entry->d_name);

        if(lstat(path, &statbuf) == -1) {
            perror("Cannot access file");
            continue;
        }

        if(S_ISLINK(statbuf.st_mode) && opt_l) {
            printf("%s\n", path);
        } else if(S_ISDIR(statbuf.st_mode) && opt_d) {
            printf("%s\n", path);
        } else if(S_ISREG(statbuf.st_mode) && opt_f) {
            printf("%s\n", path);
        } if(!opt_l && !opt_d && !opt_f) {
            printf("%s\n", path);
        }

        if(S_ISDIR(statbuf.st_mode)) {
            dirReader(path, opt_l, opt_d, opt_f, opt_s);
        }

        closedir(dp);
        free(entry);

        dp = NULL;
        entry = NULL;
    }

}
