#include "action/ActionRegistry.h"

#include "string"

#include "action/Action.h"
#include "action/ActionShow.h"
#include "action/ActionHide.h"
#include "action/ActionSelect.h"

namespace i3wl {

ActionRegistry::ActionRegistry(){
    this->actions.push_back(new ActionShow());
    this->actions.push_back(new ActionHide());
    this->actions.push_back(new ActionSelect());
}

bool ActionRegistry::isValidAction(std::string actionID){
    for(unsigned int i = 0; i < this->actions.size(); i++){
        std::string registeredActionID = this->actions[i]->getID();
        if(registeredActionID.compare(actionID) == 0) return true;
    }
    return false;
}

i3wl::Action* ActionRegistry::getActionHandler(std::string actionID){
    for(unsigned int i = 0; i < this->actions.size(); i++){
        i3wl::Action* registeredAction = this->actions[i];
        std::string registeredActionID = registeredAction->getID();
        if(registeredActionID.compare(actionID) == 0) return registeredAction;
    }
    return NULL;
}

}; // namespace i3wl
