#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// Added "-lwsock32" in GCC compile option. Linking Library.

int main(){
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2),&wsaData);

    //server_socket initiation
    int server_socket;
    server_socket = socket(PF_INET,SOCK_STREAM, 0);
    
    //Addr information initiation
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;//fixed
    server_addr.sin_port = htons(4000);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //binding socket
    if(-1==bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr))){
        printf("Bind() execution Error\n");
        exit(1);
    }

    listen(server_socket,5);

    int client_addr_size, client_socket;
    char message[1024];
    struct sockaddr_in client_addr;
    client_addr_size = sizeof(client_addr);
    client_socket = accept(server_socket,(struct sockaddr*)&client_addr,&client_addr_size);//from connect func from client
    printf("Connection Accepted\n");
    send(client_socket, " ", 1024, 0);
    while(1){
        if(recv(client_socket, message,1024, 0)>0){
            printf("%s\n",message);
        }
        if(strcmp(message,"exit")==0){
            break;
        }
        
    }
    
    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();
    return 0;
}