#include <iostream>
#include <string>

#include "message/Message.h"

void print(std::string msg){
    std::cout << "Received Message '";
    std::cout << msg;
    std::cout << "'.\n";
}

int main(int argc, char* argv[]){
    i3wl::Message::listenForMessages(print);
}
