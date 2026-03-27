#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/mman.h>

void die(const char *s){
    perror(s);
    exit(errno);
}

int handle_connection(int fd){
    char buf[1024];

    write(fd, "OF Server 1.0\n", 14);
    read(fd, buf, 4*sizeof(buf));
    write(fd, "OK\n", 3);
    return 0;
}

void sigchld(int x){
    while (waitpid(-1, NULL, WNOHANG) != -1)''
}

int main(){
    int sock = -1, afd = -1;
    struct sockaddr_in sin;
    int one = 1;
    printf("&sock= %psystem=%pmmap=%p\n",&sock,system,mmap);
    if ((sock= socket(PF_INET,SOCK_STREAM,0))< 0)
        die("socket");
    memset(&sin,0, sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port= htons(1234);
    sin.sin_addr.s_addr= INADDR_ANY;
    setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&one, sizeof(one));
    if (bind(sock,(structsockaddr*)&sin,sizeof(sin))< 0)
        die("bind");
    if (listen(sock,10) < 0)
        die("listen");
    signal(SIGCHLD,sigchld);
    for (;;){
        if ((afd= accept(sock,NULL,0)) < 0 &&errno !=EINTR)
            die("accept");
        if (afd< 0)
            continue;
        if (fork()==0) {
            handle_connection(afd);
            exit(0);
        }
        close(afd);
    }
    return 0;
 }

