#ifndef __PARSER_H__
#define __PARSER_H__

#include <map>
#include <vector>
#include <string>

class Variable {
	public:
		float floatValue;
		Vec3 vectorValue;
		std::string stringValue;
		int type;
};

class Block {
	public:
		std::map<std::string,Variable> map;
		std::string surface;
};

class Parser {
	public:
		std::vector<Block> blocks;
	
		void parse(const std::string &name);

		int getNumBlocks();
		Block getBlock();
};

#endif