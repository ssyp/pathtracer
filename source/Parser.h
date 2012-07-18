#ifndef __PARSER_H__
#define __PARSER_H__

#include <map>
#include <vector>
#include <string>
#include "Vec3.h"

using namespace Math;

class Variable {
	public:
		float floatValue;
		Vec3<float> vectorValue;
		std::string stringValue;
		int type;
};

class Block {
	public:
		std::map<std::string,Variable> map;
		std::string surface;
};

class Parser {
	private:
		std::vector<Block> blocks;
	public:
		void parse(const std::string &name);
		int getNumBlocks();
		Block getBlock(const int &n);
};

#endif