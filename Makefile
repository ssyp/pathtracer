CC=g++
CFLAGS=-g -c -Wall
LIBS=-L /usr/local/lib -lSDL
LDFLAGS=-Wall
SOURCES=source/Application.cpp source/Block.cpp source/Camera.cpp source/Console.cpp source/Cube.cpp source/Factory.cpp source/MaterialManager.cpp source/MathUtils.cpp source/Mesh.cpp source/MirrorMaterial.cpp source/MonteCarloImage.cpp source/Parser.cpp source/PathTracer.cpp source/Plane.cpp source/Ray.cpp source/Renderer.cpp source/Scene.cpp source/SimpleMaterial.cpp source/Sphere.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=pathtracer

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) $(LIBS) 

.cpp.o:
	$(CC) $(CFLAGS) $(LIBS) -o $@ $<

clean :
	rm -rf source/*.o
