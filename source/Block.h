#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <map>
#include <string>
#include "Variable.h"

class Block {
	public:
		std::string surface;
		const Variable& getVariable(const std::string & name) const;
		std::map<std::string,Variable> map;
};

#endif
