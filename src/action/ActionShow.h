#ifndef I3WL_ACTION_ACTIONSHOW
#define I3WL_ACTION_ACTIONSHOW

#include <string>

#include "action/Action.h"

namespace i3wl {

/**
 * Class: ActionShow
 * The class used to represent the 'show' action. This action toggles the
 * I3WL display on for the user.
 */
class ActionShow: public Action {

    public:
        ActionShow(){ this->id = "show"; }
        bool execute(std::vector<std::string> args);

}; // class ActionShow

}; // namespace i3wl

#endif // I3WL_ACTION_ACTIONSHOW
