#include "Block.h"

const Variable Block::getVariable(const std::string & name) const {
	std::map<std::string, Variable>::const_iterator it = map.find(name);
	
	if (it == map.end()) {
		Variable var;
		return var; 
	} 
	return it->second;
}
