#ifndef __PARSER_H__
#define __PARSER_H__

#include <map>
#include <vector>
#include <string>
#include "Vec3.h"
#include "Block.h"
#include "Variable.h"

using namespace Math;

class Parser {
	private:
		std::vector<Block> blocks;
	public:
		void parse(const std::string &name);
		int getNumBlocks();
		Block getBlock(const int &n);
};

#endif