#ifndef I3WL_ACTION_ACTIONSELECT
#define I3WL_ACTION_ACTIONSELECT

#include <string>

#include "action/Action.h"

namespace i3wl {
    /**
     * Class: ActionSelect
     * The class used to represent the 'select' action. This action selects 
     * a workspace to be previewed by the user. This function accepts the
     * following arguments:
     *   - 'left'  : select the workspace to the left of the current selection. 
     *   - 'right' : select the workspace to the right of the current selection.
     *   - <index> : select the workspace specified by the number <index>. 
     */
    class ActionSelect: public Action {

        public:
            ActionSelect(){ this->id = "select"; }
            bool execute(std::vector<std::string> args);

    }; // class ActionSelect

}; // namespace i3wl

#endif // I3WL_ACTION_ACTIONSELECT
