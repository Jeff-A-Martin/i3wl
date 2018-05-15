#ifndef I3WL_ACTION_ACTION
#define I3WL_ACTION_ACTION

#include <string>
#include <vector> 

namespace i3wl {
    
    /**
     * Virtual Class: Action
     * Used as a template class for an 'action'. An 'action' represents a 
     * discrete functionality of I3WL. 
     */
     class Action{
    
        protected:
            // A unique string used to identify this particular action.
           std::string id;
             
        public: 
            /**
             * @return This Action's 'id' field.
             */
            std::string getID(){ return this->id; }
            /**
             * The virtual method representing the execution of this action.
             * Will be implemented by all child classes. 
             * @param args An array of strings representing the arguments
             * of this action.
             * @return True if the execution of this action was successful, 
             * False otherwise.
             */
            virtual bool execute(std::vector<std::string> args) = 0;

    }; // class Action

}; // namespace i3wl

#endif // I3WL_ACTION_ACTION

