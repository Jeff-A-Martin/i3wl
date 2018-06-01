#include "message/MessageParser.h"

#include <string>
#include <vector>
#include <iostream>
#include "message/Message.h"

namespace i3wl {

MessageParser::MessageParser(std::string msg){
    unsigned int count = 0;
    unsigned int i = 0;
    unsigned long pos = -1; 
        
    do{
        pos = msg.find(Message::DELIMINATOR, ++pos);
        if(pos == std::string::npos){
            // If there is only one element
            if(count == 0) this->actionID = msg; 
            // If this is the last element
            else this->args.push_back(msg.substr(i, msg.length()));
        }else{
            if(count == 0) this->actionID = msg.substr(i, pos-i);
            else this->args.push_back(msg.substr(i, pos-i));
        }
        count++;
        i = pos + 1;
    }while(pos != std::string::npos);       
}

}; // namespace i3wl
