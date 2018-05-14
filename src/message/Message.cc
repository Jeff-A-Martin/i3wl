#include "message/Message.h"

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>

namespace i3wl{

const int Message::PORT = 9002;
const unsigned int Message::MAX_MSG_SIZE = 256;
const char Message::DELIMINATOR = ' ';
int Message::createSocket(){
    return socket(AF_INET, SOCK_STREAM, 0);
}

struct sockaddr* Message::getAddress(){
    struct sockaddr_in* addr = (sockaddr_in*) calloc(1, sizeof(struct sockaddr_in));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(PORT);
    addr->sin_addr.s_addr = INADDR_ANY;
    return (struct sockaddr*) addr;
}

void Message::freeAddress(struct sockaddr* addr){
    if(addr != NULL) free(addr); 
}

void Message::listenForMessages(void(*onMsgReceived)(std::string msg)){
    int s_id = createSocket();
    struct sockaddr* addr = getAddress();
    bind(s_id, addr, sizeof(struct sockaddr));
    listen(s_id, 1);
    while(true){
        int client_s_id = accept(s_id, NULL, NULL);
        char msg[MAX_MSG_SIZE];
        recv(client_s_id, &msg, sizeof(msg), 0);
        onMsgReceived(msg);
    }
}

bool Message::sendMessage(std::string msg){
    if(msg.length() >= MAX_MSG_SIZE) return false;
    int s_id = createSocket();
    struct sockaddr* addr = getAddress();
    int status = connect(s_id, addr, sizeof(struct sockaddr));
    free(addr);
    if(status){
        shutdown(s_id, 2);
        return false;
    }
    unsigned int trans_size = send(s_id, msg.c_str(), msg.length() + 1, 0);
    shutdown(s_id, 2);
    return trans_size == msg.length() + 1;
}

}; // namespace i3wl
