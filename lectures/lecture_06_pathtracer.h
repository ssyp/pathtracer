Raytracing
----

1. Path — полный путь луча до затухания
2. Monte Carlo — способ численно получить значение интеграла от функции
3. Алгоритм итеративный

пока(не клёво) {
	пустить лучи по всем пикселям
	посчитать интеграл (усреднить все цвета, выпущенные из этой точки)
	вывести картинку
}

----

namespace PathTracer

1. Scene
2. Renderer
3. Math + Utils
4. Parser
(Потом) 5. App + Graphics

----

1. Scene

class Scene {
	std::vector<ISurface> nodes;
	
	addSurface
	deleteSurface
	
	getNumSurfaces
	getSurface
};

class ISurface {
	
	// возвращает нормаль в точке пересечения луча и поверхности (передаётся как аргумент)
	virtual vec3 getNormal(vec3 ip) = 0;
	
	// возвращает true, если есть пересечение луча и поверхности и пишет результат пересечения в точку ip
	// иначе возвращает false
	virtual bool getIntersection(ray r, vec3 &ip) = 0; 
	
};

class Sphere : ISurface {
	
};

class Plane : ISurface {
	
};

class Mesh : ISurface {
	
};

2. Renderer

class Renderer {
	setBackgroundColor;
	setPathDepth;
	
	void render(Camera & camera, Scene & scene) {
		// пускаем лучи из камеры на сцену
		// сложили всё в MonteCarloImage
		// ++кол-во семплов
	}
	
	void pathTrace(Ray & ray, Scene & scene) {
		// ищем пересечение луча
		
		// если пересечение есть,
		// 1. Пускаем рандомный луч по полусфере от нормали
		// 2. Умножаем энергию луча на BRDF(входящего луча,исходящего луча)
		// 3. Складываем цвета рандомного луча и материала в точке пересечения
		
		// если пересечения нет, то цвет луча == цвет фона
		
		// если отражений слишком много или энергия мала, то возвращаем чёрный цвет
	}
};

class Color {
};

class Camera {
	// позиция
	// направление
	// разрешение сетки
};

class MonteCarloImage {
	
	// запоминать цвета и количество просчитанных путей для каждого пикселя
	
	
};

3. Math + Utils

class Ray {
	Vec3<float> position;
	Vec3<float> direction;
};

template Vec2
template Vec3

4. Parser

Формат файлов сцены:

vec3 [%f; %f; %f]
float 45.5
string "...dsfsdfsdfsdf"

Scene "Main scene" {
	Surface sphere pos:[123;123;123] radius:15.0
	
	Surface plane pos:[134;13;5] normal:[34;45;65]
	Surface plane pos1:... pos2:... pos3:...
	
	Surface box pos:[5;6;7] size:[34;4;6]
	
	Surface mesh file:""
}


Block[0] = { тип сурфейса == "sphere", параметр["pos"] == vec3(123,123,123), параметр["radius"] == 15 };
Block[1] = { };


class Variable {
	float floatValue;
	Vec3<float> vectorValue;
	std::string stringValue;
	int type;
};

class Block {
	тип сурфейса // -> int
	набор параметров // -> std::map<std::string,Variable>
};

class Parser {
	std::vector<Block> blocks;
	
	parse(const std::string &name) {
		
	};
	
	int getNumBlocks();
	Block getBlock();
};

