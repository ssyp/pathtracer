#include "Application.h"
#include "Console.h"

int main(int argc, char* argv[]) {
	if(argc > 1) {
		std::string scene, output;
		
		int iterations = 0, samples = 0;
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
				iterations = static_cast<int>(atof(argv[i + 1]));
			else if(argv[i] == samplesC) 
				samples = static_cast<int>(atof(argv[i + 1]));
			else if(argv[i] == outputC) {
				output = argv[i + 1];
				output = output.substr(1, (output.length() - 2));
			}
		}
		Console theCons;
		return theCons.consoleInit(scene, iterations, samples, output);
	}
	else {
		Application theApp;
		return theApp.onExecute();
	}
}
