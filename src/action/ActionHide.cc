#include "action/ActionHide.h"

#include <iostream>
#include <string>

namespace i3wl {

bool ActionHide::execute(std::string args[]){
    std::cout << "ACTION HIDE RAN\n"; 
    return false;
}

}; // namespace i3wl
