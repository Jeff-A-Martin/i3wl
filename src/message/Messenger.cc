#include <iostream>

#include "message/Message.h"

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
        if (msg.size() + arg.size() > i3wl::Message::MAX_MSG_SIZE){ // Validate message size
            std::cerr << "Error: Message must be fewer than ";
            std::cerr << i3wl::Message::MAX_MSG_SIZE;
            std::cerr << " characters.\n";
            return 1;
        }
        msg += (std::string) argv[i];
        if(i + 1 < argc){ // Separate arguments with spaces.
            msg += i3wl::Message::DELIMINATOR;
        }
    }
    std::clog << "Info: Client parsed message '";
    std::clog << msg;
    std::clog << "'.\n";

    bool result = i3wl::Message::sendMessage(msg);
    if(result) std::clog << "Successfully Transmitted Message\n";
    else std::cerr << "Failed to Transmit Message\n";
}
