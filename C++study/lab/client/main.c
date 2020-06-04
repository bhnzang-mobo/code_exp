#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <malloc.h>

int main(){
    
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2),&wsaData);
    
    int client_socket;
    client_socket = socket(PF_INET,SOCK_STREAM,0);
    char message[1024]="Hi Mobo!";


    struct sockaddr_in server_addr;
    memset(&server_addr, 0,sizeof(server_addr));
    server_addr.sin_family = AF_INET; //fixed
    server_addr.sin_port = htons(4000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(-1 == connect ( client_socket,(struct sockaddr*)&server_addr,sizeof(server_addr))){
            printf("Connection Failed\n");
            exit(1);
    }
    while(1){
        scanf(" %[^\n]",message);
        int nRcv = send(client_socket,message,1024,0);
        if(strcmp(message,"exit")==0){
            break;
        }
    }
    closesocket(client_socket);
    return 0;
}