#ifndef I3WL_MESSAGE_MESSAGE
#define I3WL_MESSAGE_MESSAGE

#include <netinet/in.h>
#include <string>

namespace i3wl {

    /**
     * Static Class: Message
     * This class is used send messages to i3wl. It establishes the interface
     * used to both send and receive the messages.
     */
    class Message{

        private:
           /**
             * Private Constructor to make the class static.
             */
            Message(){}
            /** 
             * This function creates a network socket to be used for the 
             * communication/
             * @return The int reference for the socket.
             */
            static int createSocket();
            /**
             * This function allocates and creates an address to be used for
             * the communication. When no longer needed, this address must be
             * freed with the 'freeAddress(...)' function.
             * @return A pointer to a sockaddr struct containing the address.
             */
            static struct sockaddr* getAddress();
            /**
             * This function is used to free a 'sockaddr' struct.
             * @param sockaddr A pointer to the sockaddr to be freed.
             */
            static void freeAddress(struct sockaddr* addr);

        public: 
            // The port to be used for the communication
            static const int PORT;
            // The maximum message size
            static const unsigned int MAX_MSG_SIZE;
            // The deliminator character between message arguments
            static const char DELIMINATOR;
            /**
             * This function continually listens for  messages. Each time a
             * message is received, the given callback function is called with
             * the message as a parameter.
             * @param onMsgReceived The callback function for receiving a 
             * message. It must take an 'std::string' as a parameter.
             */
            static void listenForMessages(void(*onMsgReceived)(std::string msg));
            /**
             * This function sends the given message.
             * @param msg The message to be sent.
             * @return True if the message was sent successfully, False
             * otherwise.
             */
            static bool sendMessage(std::string msg);

    }; // class Message

}; // namespace i3wl 

#endif // I3WL_MESSAGE_MESSAGE
