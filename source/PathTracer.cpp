#include "Application.h"
#include "Console.h"

#include <iostream>

int main(int argc, char* argv[]) {
	if(argc > 1) {
		std::string scene, output;

		int iterations = 3, samples = 0;
		std::string sceneC = "--scene";
		std::string iterationsC = "--iterations";
		std::string samplesC = "--samples";
		std::string outputC = "--output";
		std::string helpC = "--help";
		
		for(int i = 0; i < argc; i++) {
			if(strcmp(argv[i], sceneC.c_str()) == 0) {
				scene = argv[i + 1];
				scene = scene.substr(0, scene.length());
			}
			else if(strcmp(argv[i], iterationsC.c_str()) == 0) 
				iterations = static_cast<int>(atof(argv[i + 1]));
			else if(strcmp(argv[i], samplesC.c_str()) == 0) 
				samples = static_cast<int>(atof(argv[i + 1]));
			else if(strcmp(argv[i], outputC.c_str()) == 0) {
				output = argv[i + 1];
				output = output.substr(0, output.length());
			}
            else if(strcmp(argv[i], helpC.c_str()) == 0) {
                std::cout << "--scene \"path\" - The path to the scene file" << std::endl;
                std::cout << "--iterations \"number\" - Number of iterations" << std::endl;
                std::cout << "--samples \"number\" - Number of samples" << std::endl;
                std::cout << "--output \"path\" - Path where to save" << std::endl;
                std::cout << "--help - Show this help" << std::endl;
                return 0;
            }
		}
		Console theCons;
		return theCons.execute(scene, iterations, samples, output);
	}
	else {
		Application theApp;
		return theApp.onExecute();
	}
}
