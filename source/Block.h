#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <map>
#include <string>
#include "Variable.h"

class Block {
	public:
		std::map<std::string,Variable> map;
		std::string surface;

		const Variable& getVariable(const std::string & name) const {
			std::map<std::string,Variable>::const_iterator it = map.find(name);
			if (it == map.end()) {
				Variable var;
				return var; 
			} 
			return it -> second;
		}
};

#endif
