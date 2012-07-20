#include "Application.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	std::string scene, output;
	float iterations, samples;
	for(int i = 0; i < argc; i++) {
		if(argv[i] == "--scene") {
			scene = argv[i + 1];
			scene = scene.substr(1, (scene.length() - 2));
		}
		if(argv[i] == "--iterations") 
			iterations = static_cast<float>(atof(argv[i + 1]));
		if(argv[i] == "--samples") 
			samples = static_cast<float>(atof(argv[i + 1]));
		if(argv[i] == "--output") {
			output = argv[i + 1];
			output = output.substr(1, (output.length() - 2));
		}
	}

	Application theApp;
 
    return theApp.onExecute();
}
