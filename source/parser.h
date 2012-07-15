#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <fstream>

#include <map>
#include <vector>
#include <string>

class Vec3 {
	public:
		float x;
		float y;
		float z;
};

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
		int surface;
};

class Parser {
	public:
		std::vector<Block> blocks;
	
		void parse(const std::string &name) {
			std::ifstream file(name);
			int nSurface = 0;

			while(!file.eof()) {
				char buffer[256];
				file.getline(buffer,256);

				std::string str(buffer);

				int n = 0, begin = 0, end = 0;
				std::string word;
				std::string pos, radius, normal, size, fileNm, meshFile, point1, point2, point3;
				int surfaceN;
				float posX = 0, posY = 0, posZ = 0, otherX = 0, otherY = 0, otherZ = 0, fRadius = 0;
				float posX1 = 0, posY1 = 0, posZ1 = 0, posX2 = 0, posY2 = 0, posZ2 = 0, posX3 = 0, posY3 = 0, posZ3 = 0;
				bool first = false, plane = false;
				for(std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
					if((*it == ' ')&&(first == false)) {
						begin = n + 1;
						first = true;
					}
					else if((*it == ' ')&&(end < begin)) {
						end = n;
						word = str.substr(begin,(end - begin));
						if (word == "sphere") surfaceN = 1;
						else if (word == "plane") surfaceN = 2;
						else if (word == "box") surfaceN = 3;
						else if (word == "mesh") surfaceN = 4;
						else if ((word == "file:")&&(surfaceN == 4)) {
							fileNm = word.substr(0,4);
							meshFile = str.substr((end + 1),(str.npos - end + 1));
						}
						else if ((word.substr(0,4) == "pos:")&&((surfaceN == 1)||(surfaceN == 2)||(surfaceN == 3))) {
							if(surfaceN == 2) plane = true;
							pos = word.substr(0,3);
							int n1 = 0, begin1 = 0, end1 = 0, nCoordinate = 0;
							for(std::string::iterator it = word.begin(); it != word.end(); ++it) {
								if (*it == '[') begin1 = n1 + 1;
								else if(((*it == ';')||(*it == ']'))&&(end1 < begin1)) {
									end1 = n1;
									nCoordinate++;
									if(nCoordinate == 1) {
										std::string StrBox = word.substr(begin1,(end1 - begin1));
										posX = static_cast<float>(atof(StrBox.c_str()));
									}
									else if(nCoordinate == 2) {
										std::string StrBox = word.substr(begin1,(end1 - begin1));
										posY = static_cast<float>(atof(StrBox.c_str()));
									}
									else if(nCoordinate == 3) {
										std::string StrBox = word.substr(begin1,(end1 - begin1));
										posZ = static_cast<float>(atof(StrBox.c_str()));
									}
									begin1 = end1 + 1;
								}
								n1++;
							}
						}
						else if ((((word.substr(0,6) == "normal")||(word.substr(0,4) == "pos1")||(word.substr(0,4) == "pos2")||(word.substr(0,4) == "pos3"))&&(surfaceN == 2))||((word.substr(0,4) == "size")&&(surfaceN == 3))) {
							if ((surfaceN == 2)&&(word.substr(0,6) == "normal")) normal = word.substr(0,6);
							else if ((surfaceN == 2)&&(word.substr(0,4) == "pos1")) point1 = word.substr(0,4);
							else if ((surfaceN == 2)&&(word.substr(0,4) == "pos2")) point2 = word.substr(0,4);
							else if ((surfaceN == 2)&&(word.substr(0,4) == "pos3")) point3 = word.substr(0,4);
							else if (surfaceN == 3) size = word.substr(0,4);
							int n1 = 0, begin1 = 0, end1 = 0, nCoordinate = 0;
							for(std::string::iterator it = word.begin(); it != word.end(); ++it) {
								if (*it == '[') begin1 = n1 + 1;
								else if(((*it == ';')||(*it == ']'))&&(end1 < begin1)) {
									end1 = n1;
									nCoordinate++;
									if(nCoordinate == 1) {
										std::string StrBox = word.substr(begin1,(end1 - begin1));
										otherX = static_cast<float>(atof(StrBox.c_str()));
										if ((surfaceN == 2)&&(word.substr(0,4) == "pos1")) posX1 = otherX;
										else if ((surfaceN == 2)&&(word.substr(0,4) == "pos2")) posX2 = otherX;
										else if ((surfaceN == 2)&&(word.substr(0,4) == "pos3")) posX3 = otherX;
									}
									else if(nCoordinate == 2) {
										std::string StrBox = word.substr(begin1,(end1 - begin1));
										otherY = static_cast<float>(atof(StrBox.c_str()));
										if ((surfaceN == 2)&&(word.substr(0,4) == "pos1")) posY1 = otherY;
										else if ((surfaceN == 2)&&(word.substr(0,4) == "pos2")) posY2 = otherY;
										else if ((surfaceN == 2)&&(word.substr(0,4) == "pos3")) posY3 = otherY;
									}
									else if(nCoordinate == 3) {
										std::string StrBox = word.substr(begin1,(end1 - begin1));
										otherZ = static_cast<float>(atof(StrBox.c_str()));
										if ((surfaceN == 2)&&(word.substr(0,4) == "pos1")) posZ1 = otherZ;
										else if ((surfaceN == 2)&&(word.substr(0,4) == "pos2")) posZ2 = otherZ;
										else if ((surfaceN == 2)&&(word.substr(0,4) == "pos3")) posZ3 = otherZ;
									}
									begin1 = end1 + 1;
								}
								n1++;
							}
						}
						else if ((word.substr(0,6) == "radius")&&(surfaceN == 1)) {
							radius = word.substr(0,6);
							std::string vs = word.substr(7,(word.npos - 7));
							fRadius = static_cast<float>(atof(vs.c_str()));
						}
						begin = end + 1;
					}
					n++;
				}
				if(surfaceN == 1) {
					Variable vPos;
					vPos.vectorValue.x = posX;
					vPos.vectorValue.y = posY;
					vPos.vectorValue.z = posZ;
					Variable vRadius;
					vRadius.floatValue = fRadius;

					Block block;
					block.surface = surfaceN;
					block.map[pos] = vPos;
					block.map[radius] = vRadius;
					blocks.push_back(block);

					std::cout << surfaceN << "|" << pos << "|" << posX << "|" << posY << "|" << posZ << "|";
					std::cout << radius << "|" << fRadius << std::endl;
				}
				else if (surfaceN == 2) {
					if(plane == true) {
						Variable vPos;
						vPos.vectorValue.x = posX;
						vPos.vectorValue.y = posY;
						vPos.vectorValue.z = posZ;
						Variable vNormal;
						vNormal.vectorValue.x = otherX;
						vNormal.vectorValue.y = otherY;
						vNormal.vectorValue.z = otherZ;

						Block block;
						block.surface = surfaceN;
						block.map[pos] = vPos;
						block.map[normal] = vNormal;
						blocks.push_back(block);

						std::cout << surfaceN << "|" << pos << "|" << posX << "|" << posY << "|" << posZ << "|";
						std::cout << normal << "|" << otherX << "|" << otherY << "|" << otherZ << std::endl;
					}
					else {
						Variable point1C;
						point1C.vectorValue.x = posX1;
						point1C.vectorValue.y = posY1;
						point1C.vectorValue.z = posZ1;

						Variable point2C;
						point2C.vectorValue.x = posX2;
						point2C.vectorValue.y = posY2;
						point2C.vectorValue.z = posZ2;

						Variable point3C;
						point3C.vectorValue.x = posX3;
						point3C.vectorValue.y = posY3;
						point3C.vectorValue.z = posZ3;

						Block block;
						block.surface = surfaceN;
						block.map[point1] = point1C;
						block.map[point2] = point2C;
						block.map[point3] = point3C;

						std::cout << surfaceN << "|" << point1 << "|" << posX1 << "|" << posY1 << "|" << posZ1 << "|";
						std::cout << point2 << "|" << posX2 << "|" << posY2 << "|" << posZ2 << "|";
						std::cout << point3 << "|" << posX3 << "|" << posY3 << "|" << posZ3 << std::endl;
					}
				}
				else if (surfaceN == 3) {
					Variable vPos;
					vPos.vectorValue.x = posX;
					vPos.vectorValue.y = posY;
					vPos.vectorValue.z = posZ;
					Variable vSize;
					vSize.vectorValue.x = otherX;
					vSize.vectorValue.y = otherY;
					vSize.vectorValue.z = otherZ;

					Block block;
					block.surface = surfaceN;
					block.map[pos] = vPos;
					block.map[size] = vSize;
					blocks.push_back(block);

					std::cout << surfaceN << "|" << pos << "|" << posX << "|" << posY << "|" << posZ << "|";
					std::cout << size << "|" << otherX << "|" << otherY << "|" << otherZ << std::endl;
				}
				else if (surfaceN == 4) {
					Variable fileName;
					fileName.stringValue = meshFile;

					Block block;
					block.surface = surfaceN;
					block.map[fileNm] = fileName;

					std::cout << surfaceN << "|" << meshFile << std::endl;
				}
				nSurface++;
			}
		}
	
		/*int getNumBlocks();
		Block getBlock();*/
};

#endif