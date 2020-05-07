#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#define task "C:\\Users\\bhnza\\Desktop\\code_exp\\default_Task_json\\tasks.json"
#define launch "C:\\Users\\bhnza\\Desktop\\code_exp\\default_Task_json\\launch.json"

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


int main() {
    FILE* org_task,*org_launch,* cop;
    mkdir(".\\.vscode");
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

    return 0;
}
