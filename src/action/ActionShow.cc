#include "action/ActionShow.h"

#include <iostream>
#include <string>

namespace i3wl {

bool ActionShow::execute(std::vector<std::string> args){
    std::cout << "ACTION SHOW RAN\n"; 
    return false;
}

} // namespace i3wl
