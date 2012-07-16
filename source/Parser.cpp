#include <iostream>
#include <fstream>

#include <map>
#include <vector>
#include <string>

#include "Parser.h"

void Parser::parse(const std::string &name) {
	std::ifstream file(name);
	while(!file.eof()) {
		char buffer[256];
		file.getline(buffer,256);
		std::string str(buffer);
		int n = 0, begin = 0, end = 0, nParameters = 0;
		std::string word, surfaceN;
		std::map<int,float> fValue, vX, vY, vZ;
		std::map<int,std::string> sValue, parameters, type;
		bool firstS = false, firstWord = false;
		for(std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
			if((*it == ' ')&&(firstS == false)) {
				begin = n + 1;
				firstS = true;
			}
			else if(((*it == ' ')||((n + 1) == str.length()))&&(end < begin)) {
				if((n + 1) == str.length()) end = n + 1;
				else end = n;
				word = str.substr(begin,(end - begin));

				if (firstWord == false) {
					surfaceN = word;
					firstWord = true;
				}
				else {
					int n2 = 0, begin2 = 0, nCoord = 0;
					for(std::string::const_iterator it2 = word.begin(); it2 != word.end(); ++it2) {
						if(*it2 == ':') {
							nParameters++;
							parameters[nParameters] = word.substr(0,n2);
							if((*(it2 + 1) != '[')&&(*(it2 + 1) != '"')) {
								fValue[nParameters] = static_cast<float>(atof((word.substr((n2 + 1),(word.length() - n2))).c_str()));
								type[nParameters] = "value";
							}
							else if (*(it2 + 1) == '"') {
								sValue[nParameters] = word.substr((n2 + 2),((word.length() - n2) - 3));
								type[nParameters] = "string";
							}
							else if (*(it2 + 1) == '['){
								begin2 = n2 + 2;
								type[nParameters] = "vector";
							}
						}
						if((*it2 == ';')||(*it2 == ']')) {
							if (nCoord == 0)
								vX[nParameters] = static_cast<float>(atof((word.substr(begin2,(n2 - begin2))).c_str()));
							else if (nCoord == 1)
								vY[nParameters] = static_cast<float>(atof((word.substr(begin2,(n2 - begin2))).c_str()));
							else if (nCoord == 2)
								vZ[nParameters] = static_cast<float>(atof((word.substr(begin2,(n2 - begin2))).c_str()));
							nCoord++;
							begin2 = n2 + 1;
						}
						n2++;
					}
				}
				begin = end + 1;
			}
			n++;
		} 
		Block block;
		block.surface = surfaceN;
		for(int i = 1; i < (nParameters + 1); i++) {
			std::string inMap = parameters[i];
			if (type[i] == "vector") {
				Variable vector;
				vector.vectorValue.x = vX[i];
				vector.vectorValue.y = vY[i];
				vector.vectorValue.z = vZ[i];
				block.map[inMap] = vector;
			}
			else if (type[i] == "value") {
				Variable value;
				value.floatValue = fValue[i];
				block.map[inMap] = value;
			}
			else if (type[i] == "string") {
				Variable string;
				string.stringValue = sValue[i];
				block.map[inMap] = string;
			}
		}
		blocks.push_back(block);

		std::cout << surfaceN;
		for(int i = 1;i<nParameters + 1;i++) {
			std::cout << "|" << parameters[i];
			if (type[i] == "vector") {
				std::cout << "|" << vX[i];
				std::cout << "|" << vY[i];
				std::cout << "|" << vZ[i];
			}
			else if (type[i] == "value")
				std::cout << "|" << fValue[i];
			else if (type[i] == "string")
				std::cout << "|" << sValue[i];
		}
		std::cout << std::endl;
	}
}