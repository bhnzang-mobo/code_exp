#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#define MYPATH "C:\\Users\\bhnza\\Desktop\\code_exp\\default_Task_json"

int main(void) {
    DIR *d;
    struct dirent *dir;
    d = opendir(MYPATH);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return(0);
}