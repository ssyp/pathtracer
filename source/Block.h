#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <map>
#include <string>

class Block {
	public:
		std::map<std::string,Variable> map;
		std::string surface;

		Variable getVariable(const std::string & name) {
			return map[name];
		}
};

#endif
