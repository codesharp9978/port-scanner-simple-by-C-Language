#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void port_scan(const char *TARGET_IP, int PORT) {
        int sock;
        struct sockaddr_in target;

        //Initialize socket
        sock = socket(AF_INET,SOCK_STREAM,0);
        if(sock == -1) {
                perror("SOCKET Failed Created");
                exit(EXIT_FAILURE);
        }

        // setting target scanning
        target.sin_family = AF_INET;
        target.sin_addr.s_addr = inet_addr(TARGET_IP);
        target.sin_port = htons(PORT);


        if(connect(sock,(struct sockaddr *)&target,sizeof(target)) == 0) {
                printf("PORT %d Is Running\n",PORT);
        }

        close(sock);
}


int main(int argc, char *argv[]) {

        if(argc != 3) {
                printf("USAGE THIS : %s <IP> <MAX_PORT ",argv[0]);
                exit(EXIT_FAILURE);
        }

        const char *TARGET = argv[1];
        int MAX_PORT = atoi(argv[2]);
        for(int i = 1; i <= MAX_PORT; i++) {
                port_scan(TARGET,i);
        }
        return 0;
}