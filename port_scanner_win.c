#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>


// gcc port_scanner_win.c -o port_scanner -lws2_32
void scan_port(const char *IP, int port) {

    // initialize Socket
    WSADATA wsaData;
    SOCKET sockfd;
    struct sockaddr_in target;

    // Inisialisasi Winsock
    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        printf("Failed to initialize Winsock\n");
        return;
    }

    // inisialisasi socket
    sockfd = socket(AF_INET, SOCK_STREAM,0);
    if(sockfd == INVALID_SOCKET) {
        printf("Socket creation failed\n");
        WSACleanup();
        return;
    }

    // set target port
    target.sin_family = AF_INET;
    target.sin_port = htons(port);

    // jika IP bermasalah, sudah ada ditangani
    if(inet_addr(IP) == INADDR_NONE) {
        printf("Invalid IP Address\n");
        closesocket(sockfd);
        WSACleanup();
        return;
    }   

    // set target address
    target.sin_addr.s_addr = inet_addr(IP);

    // cek OPEN/CLOSE PORT
    if(connect(sockfd, (struct sockaddr*)&target, sizeof(target)) == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is Closed\n",port);
    }
    WSACleanup();
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage THIS : IP TARGET_IP MAX_PORT");
        return 1;
    }

    const char *target_ip = argv[1];
    int max_port = atoi(argv[2]);

    for(int port = 1; port <= max_port; ++port) {
        scan_port(target_ip,port);
    }
}