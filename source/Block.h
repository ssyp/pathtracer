#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <map>
#include <string>

class Block {
	public:
		std::map<std::string,Variable> map;
		std::string surface;
};

#endif
