#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MSG_SIZE 256
#define SERVER_PORT 9002
#define NUM_SERVER_CONNECTIONS 5

int main(int argc, char* argv[]){
    // Initialize Server 
    int s_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(SERVER_PORT);
    s_addr.sin_addr.s_addr = INADDR_ANY;
    bind(s_socket, (struct sockaddr*) &s_addr, sizeof(s_addr));

    // Wait For Connections
    listen(s_socket, NUM_SERVER_CONNECTIONS);
    while(true){
        int c_socket = accept(s_socket, NULL, NULL);
        char msg[MSG_SIZE];
        recv(c_socket, &msg, sizeof(msg), 0);
        std::clog << "Info: Received Message '";
        std::clog << msg;
        std::clog << "' from client.\n"; 
    }

    // Disconnect Server
    shutdown(s_socket, 2);
    return 0;
}

