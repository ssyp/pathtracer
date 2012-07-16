Raytracing
----

1. Path � ������ ���� ���� �� ���������
2. Monte Carlo � ������ �������� �������� �������� ��������� �� �������
3. �������� �����������

����(�� ����) {
	������� ���� �� ���� ��������
	��������� �������� (��������� ��� �����, ���������� �� ���� �����)
	������� ��������
}

----

namespace PathTracer

1. Scene
2. Renderer
3. Math + Utils
4. Parser
(�����) 5. App + Graphics

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
	
	// ���������� ������� � ����� ����������� ���� � ����������� (��������� ��� ��������)
	virtual vec3 getNormal(vec3 ip) = 0;
	
	// ���������� true, ���� ���� ����������� ���� � ����������� � ����� ��������� ����������� � ����� ip
	// ����� ���������� false
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
		// ������� ���� �� ������ �� �����
		// ������� �� � MonteCarloImage
		// ++���-�� �������
	}
	
	void pathTrace(Ray & ray, Scene & scene) {
		// ���� ����������� ����
		
		// ���� ����������� ����,
		// 1. ������� ��������� ��� �� ��������� �� �������
		// 2. �������� ������� ���� �� BRDF(��������� ����,���������� ����)
		// 3. ���������� ����� ���������� ���� � ��������� � ����� �����������
		
		// ���� ����������� ���, �� ���� ���� == ���� ����
		
		// ���� ��������� ������� ����� ��� ������� ����, �� ���������� ������ ����
	}
};

class Color {
};

class Camera {
	// �������
	// �����������
	// ���������� �����
};

class MonteCarloImage {
	
	// ���������� ����� � ���������� ������������ ����� ��� ������� �������
	
	
};

3. Math + Utils

class Ray {
	Vec3<float> position;
	Vec3<float> direction;
};

template Vec2
template Vec3

4. Parser

������ ������ �����:

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


Block[0] = { ��� �������� == "sphere", ��������["pos"] == vec3(123,123,123), ��������["radius"] == 15 };
Block[1] = { };


class Variable {
	float floatValue;
	Vec3<float> vectorValue;
	std::string stringValue;
	int type;
};

class Block {
	��� �������� // -> int
	����� ���������� // -> std::map<std::string,Variable>
};

class Parser {
	std::vector<Block> blocks;
	
	parse(const std::string &name) {
		
	};
	
	int getNumBlocks();
	Block getBlock();
};

