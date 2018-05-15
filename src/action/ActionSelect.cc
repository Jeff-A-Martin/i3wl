#include "action/ActionSelect.h"

#include <iostream>
#include <string>

namespace i3wl {

bool ActionSelect::execute(std::vector<std::string> args){
    std::cout << "ACTION SELECT RAN\n"; 
    return false;
}

} // namespace i3wl
