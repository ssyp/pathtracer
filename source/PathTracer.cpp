#include "Application.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	std::string scene, output;
	float iterations, samples;
	char* sceneC = "--scene";
	char* iterationsC = "--iterations";
	char* samplesC = "--samples";
	char* outputC = "--output";
	for(int i = 0; i < argc; i++) {
		if(argv[i] == sceneC) {
			scene = argv[i + 1];
			scene = scene.substr(1, (scene.length() - 2));
		}
		else if(argv[i] == iterationsC) 
			iterations = static_cast<float>(atof(argv[i + 1]));
		else if(argv[i] == samplesC) 
			samples = static_cast<float>(atof(argv[i + 1]));
		else if(argv[i] == outputC) {
			output = argv[i + 1];
			output = output.substr(1, (output.length() - 2));
		}
	}

	Application theApp;
 
    return theApp.onExecute();
}
