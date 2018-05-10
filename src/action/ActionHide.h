#ifndef I3WL_ACTION_ACTIONHIDE
#define I3WL_ACTION_ACTIONHIDE

#include <string>

#include "action/Action.h"

namespace i3wl {
    /**
     * Class: ActionHide
     * The class used to represent the 'hide' action. This action toggles the
     * I3WL display off for the user.
     */
    class ActionHide: public Action {

        public:
            ActionHide(){ this->id = "hide"; }
            bool execute(std::string args[]);

    }; // class ActionHide

}; // namespace i3wl

#endif // I3WL_HIDE_ACTIONHIDE
