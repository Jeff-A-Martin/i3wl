#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MSG_SIZE 256
#define DELIM_CHAR ' '
#define SERVER_PORT 9002

int main(int argc, char* argv[]){
   
    // Validate that a message was provided (Argument other than program name)
    if(argc < 2){
        std::cerr << "Error: No message was provided.\n";
        return 1;;
    }
    
    // Format the message
    std::string msg;
    for(int i = 1; i < argc; i++){
        std::string arg = (std::string) argv[i]; // Convert argument to string
        if (msg.size() + arg.size() > MSG_SIZE){ // Validate message size
            std::cerr << "Error: Message must be fewer than ";
            std::cerr << MSG_SIZE;
            std::cerr << " characters.\n";
            return 1;
        }
        msg += (std::string) argv[i];
        if(i + 1 < argc){ // Separate arguments with spaces.
            msg += DELIM_CHAR;
        }
    }
    std::clog << "Info: Client parsed message '";
    std::clog << msg;
    std::clog << "'.\n";

    // Connect To Server
    int c_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in s_addr;
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(SERVER_PORT);
    s_addr.sin_addr.s_addr = INADDR_ANY;
    int connection_status = connect(c_socket, (struct sockaddr*) &s_addr, sizeof(s_addr));
    if(connection_status){
        std::cerr << "Error: Could not connect to server.\n";
        shutdown(c_socket, 2);
        return 1;
    }else{
        std::clog << "Info: Successfully connected to server.\n";
    }
   
    // Send the Message to the Server
    int size = send(c_socket, msg.c_str(), msg.length() + 1, 0);
    std::clog << "Info: Transmitted ";
    std::clog << size;
    std::clog << " bytes to server.";

    // Disconnect
    shutdown(c_socket, 2);
    return 0;

}

