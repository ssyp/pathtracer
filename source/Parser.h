#ifndef __PARSER_H__
#define __PARSER_H__

#include <vector>
#include "Block.h"
#include "Variable.h"

using namespace Math;

class Parser {
	private:
		std::vector<Block> surfaceBlocks;
		std::vector<Block> materialBlocks;
		std::vector<Block> settingBlocks;

	public:
		void parse(const std::string & name);

		inline int getNumSurfaceBlocks() {
			return surfaceBlocks.size();
		}

		inline int getNumMaterialBlocks() {
			return materialBlocks.size();
		}

		inline int getNumSettingBlocks() {
			return settingBlocks.size();
		}

		inline Block getSurfaceBlock(const int & n) {
			return surfaceBlocks[n];
		}

		inline Block getMaterialBlock(const int & n) {
			return materialBlocks[n];
		}

		inline Block getSettingBlock(const int & n) {
			return settingBlocks[n];
		}
};

#endif
