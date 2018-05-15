#include <iostream>
#include <string>

#include "message/Message.h"
#include "message/MessageParser.h"

void print(std::string msg){
    std::cout << "Received Message '";
    std::cout << msg;
    std::cout << "'.\n";
}

void parseMessage(std::string msg){
    std::cout << "Received Message '";
    std::cout << msg;
    std::cout << "'.\n";
    i3wl::MessageParser*  parser = new i3wl::MessageParser(msg);
    std::cout << "ActionID: '"; 
    std::cout << parser->getActionID();
    std::cout << "'.\n";
    std::cout << "Arguments: '";
    for(unsigned int i = 0; i < parser->getArgs().size(); i++){
        std::cout << parser->getArgs()[i];
        if(i != parser->getArgs().size() - 1) std::cout << ", ";
    }
    std::cout <<"'.\n";
}

int main(int argc, char* argv[]){
    i3wl::Message::listenForMessages(parseMessage);
}
