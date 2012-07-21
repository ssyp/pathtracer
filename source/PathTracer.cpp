#include "Application.h"
#include "Console.h"

int main(int argc, char* argv[])
{
	if(argc > 1) {
		std::string sceneN, output;
		float iterations, samples;
		char* sceneC = "--scene";
		char* iterationsC = "--iterations";
		char* samplesC = "--samples";
		char* outputC = "--output";
		for(int i = 0; i < argc; i++) {
			if(argv[i] == sceneC) {
				sceneN = argv[i + 1];
				sceneN = sceneN.substr(1, (sceneN.length() - 2));
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
		Console theCons;
		return theCons.consoleInit();
	}
	//Console theCons;
	//return theCons.consoleInit();

	Application theApp;
 
    return theApp.onExecute();
}
