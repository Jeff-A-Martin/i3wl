#include <iostream>
#include <string>

#include "message/Message.h"
#include "message/MessageParser.h"
#include "action/ActionRegistry.h"
#include "action/Action.h"

void parseMessage(std::string msg){
    // Parse Message
    i3wl::MessageParser* parser = new i3wl::MessageParser(msg);
    std::string id = parser->getActionID();
    std::vector<std::string> args = parser->getArgs();
    unsigned int arg_cnt = args.size();
    // Log Parsed Message
    std::clog << "ActionID: '" + id + "'\n";
    std::clog << "Arguments: ";
    for(unsigned int i = 0; i < arg_cnt; i++){
        std::clog << "'" + args[i] + "'";
        if(i != arg_cnt - 1) std::clog << ", ";
    }
    std::clog << "\n";
    
    // Verify Message
    i3wl::ActionRegistry* actions = new i3wl::ActionRegistry();
    if(actions->isValidAction(id)){
        // Pass Control to the Action Handler
        i3wl::Action* actionHandler = actions->getActionHandler(id);
        actionHandler->execute(args);
    }else{
        std::cerr << "'" + id + "' is not a valid action identifier.\n";
    }

}

int main(int argc, char* argv[]){
    i3wl::Message::listenForMessages(parseMessage);
}
