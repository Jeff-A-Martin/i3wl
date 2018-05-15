#ifndef I3WL_MESSAGE_MESSAGEPARSER
#define I3WL_MESSAGE_MESSAGEPARSER

#include <string>
#include <vector> 

namespace i3wl {

    /**
     * Class: MessageParser
     * This class is used to interface with the action package and determine
     * the appropriate action and arguments for a given message.
     */
    class MessageParser{
    
        private:
            // The actionID from the message; Populated when constructed.
            std::string actionID;
            // The arg vector from the message; Populated when constructed.
            std::vector<std::string> args;
        public:
            /**
             * Constructor Method: 
             * @param msg The message to be parsed by this MessageParser.
             */
            MessageParser(std::string msg);
            /**
             * @return The actionID of the msg.
             */
            std::string getActionID(){ return this->actionID; }
            /**
             * @return The argument vector of the msg.
             */ 
            std::vector<std::string> getArgs(){ return this->args; }

    }; // class MessageParser
    
}; // namespace i3wl

#endif // I3WL_MESSAGE_MESSAGEPARSER
