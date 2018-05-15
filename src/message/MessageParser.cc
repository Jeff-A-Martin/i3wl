#include "message/MessageParser.h"

#include <string>
#include <vector>
#include <iostream>
#include "message/Message.h"

namespace i3wl {

    MessageParser::MessageParser(std::string msg){
        unsigned int count = 0;
        unsigned int i = 0;
        unsigned long pos = msg.find(Message::DELIMINATOR);
        while (pos != std::string::npos) {
            std::string element = msg.substr(i, pos-i);
            if(count == 0) this->actionID = element;
            else this->args.push_back(element);
            count++;
            i = ++pos;
            pos = msg.find(Message::DELIMINATOR, pos);
            if (pos == std::string::npos)
                this->args.push_back(msg.substr(i, msg.length()));
            }
        }

}; // namespace i3wl
