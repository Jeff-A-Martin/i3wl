#ifndef I3WL_ACTION_ACTIONREGISTRY
#define I3WL_ACTION_ACTIONREGISTRY

#include <string>
#include <vector>

#include "action/Action.h"

namespace i3wl {

/**
 * Class: ActionRegistry
 * Used as a registry of all actions, or sub-classes of the 'Action' 
 * virtual class. 
 */
class ActionRegistry {
      
    private:
        // A vector of all actions registered under I3WL. 
        std::vector<i3wl::Action*> actions;

    public:
        /*
         * The default constructor method. This should be modified to
         * register an action.
         */
        ActionRegistry();
        /*
         * This function determines if the given action ID corresponds to
         * a valid action.
         * @param actionID The string used to identify a particular action.
         * @return True if actionID is the ID of a registered action, False
         * otherwise. 
         */
        bool isValidAction(std::string actionID);
        /*
         * This function retrieves the Action object for a particular
         * action ID.
         * @param actionID The string used to identify a particular action.
         * @return A pointer to the Action object for the given action ID,
         * NULL if the action ID does not correspond to a registered
         * action.
         */
        i3wl::Action* getActionHandler(std::string actionID);
}; // class ActionRegistry

}; // namespace i3wl

#endif // I3WL_ACTION_ACTIONREGISTRY

