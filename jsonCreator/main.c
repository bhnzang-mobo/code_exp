#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define task "C:\\Users\\bhnza\\Desktop\\code_exp\\default_Task_json\\tasks.json"
#define launch "C:\\Users\\bhnza\\Desktop\\code_exp\\default_Task_json\\launch.json"
#define MYPATH "C:\\Users\\bhnza\\Desktop\\code_exp\\default_Task_json\\"

int copy_file(FILE* org, FILE* cop){
    void* buf;
    buf=malloc(1030);
    size_t read_length;
    while( 1 ) {
        read_length=fread(buf,1,1024,org);
        if(read_length==1024){
        fwrite(buf, 1, 1024, cop);
        }
        else{
            fwrite(buf,1,read_length,cop);
            break;
        }
    }
    fclose(org);
    fclose(cop);
    free(buf);
    return 1;
}

char* concat(char* s1, char* s2){
    char* ret = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(ret,s1);
    strcat(ret,s2);
    return ret;
}


int main() {
    FILE* org,*det;
    char* path;
    char* path2;
    mkdir(".\\.vscode");
    DIR *d;
    struct dirent *dir;
    d = opendir(MYPATH);
    dir = readdir(d);
    dir = readdir(d);
    
    while((dir=readdir(d))!=NULL){
        path = concat(MYPATH,dir->d_name);
        path2 = concat(".vscode\\",dir->d_name);
        org=fopen(path,"rb");
        det=fopen(path2,"wb");
        if(org==NULL || det==NULL){
            printf("Opening directory failed.\n");
            system("pause");
        }
        copy_file(org,det);
    }
    /*
    org_task=fopen(task,"rb");
    org_launch=fopen(launch,"rb");
    if(org_launch==NULL || org_task ==NULL){
        printf("There is No such files.");
        system("pause");
    }
    cop=fopen(".vscode\\tasks.json","wb");
    copy_file(org_task,cop);
    cop=fopen(".vscode\\launch.json","wb");
    copy_file(org_launch,cop);
    */
    closedir(d);
    return 0;
}
