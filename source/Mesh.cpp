#include "Mesh.h"
#include "Plane.h"
#include "MathUtils.h"
#include <fstream>
#include <iostream>

Mesh::Mesh() {
    position.x = 0;
    position.y = 0;
    position.z = 0;
}

bool Mesh::belongingTriangle(const Vec3<float> & a, const Vec3<float> & b, const Vec3<float> c, const Vec3<float> p) const {
    // if the triangle is parallel to the coordinate axes
    if((a.x == b.x && a.y == b.y) || (b.x == c.x && b.y == c.y) || (c.x == a.x && c.y == a.y)) return true;
    int intersectionWithSide = 0;

    // if a point belongs to the side
    // side ab
    if(((p.x - b.x) * (a.y - b.y)) == ((p.y - b.y) * (a.x - b.x)))
        if(((a.x < b.x) && (a.x <= p.x) && (p.x <= b.x)) || ((a.x > b.x) && (b.x <= p.x) && (p.x <= a.x)))
            return true;
    // side bc
    if(((p.x - c.x) * (b.y - c.y)) == ((p.y - c.y) * (b.x - c.x)))
        if(((b.x < c.x) && (b.x <= p.x) && (p.x <= c.x)) || ((b.x > c.x) && (c.x <= p.x) && (p.x <= b.x)))
            return true;
    // side ca
    if(((p.x - a.x) * (c.y - a.y)) == ((p.y - a.y) * (c.x - a.x)))
        if(((c.x < a.x) && (c.x <= p.x) && (p.x <= a.x)) || ((c.x > a.x) && (a.x <= p.x) && (p.x <= c.x)))
            return true;

    // side ab
    // if a point doesn't belong to side of the triangle
    if(((p.y - a.y) * (p.y - b.y)) < 0)
        // if point of intersection of the right
        if(p.x > ((p.y - a.y) * (b.x - a.x) / (b.y - a.y) + a.x)) intersectionWithSide++;
    // if that side on aline
    //else if((a.y == b.y) && (p.y == a.y))
    //    intersectionWithSide += 2;
    // if a line intersection the end of side
    //else if(p.y == a.y)
    //    intersectionWithSide += 2;

    // side bc
    if(((p.y - b.y) * (p.y - c.y)) < 0)
        if(p.x > ((p.y - b.y) * (c.x - b.x) / (c.y - b.y) + b.x)) intersectionWithSide++;

    // side bc -> ca
    if(((p.y - c.y) * (p.y - a.y)) < 0)
        if(p.x > ((p.y - c.y) * (a.x - c.x) / (a.y - c.y) + c.x)) intersectionWithSide++;

    if(intersectionWithSide % 2 == 0) return false;
    return true;
}

bool Mesh::getIntersectionTriangle(const Vec3<float> & a, const Vec3<float> & b, const Vec3<float> & c, const Vec3<float> & p) const {
    Vec3<float> prA, prB, prC, prP;

    //plane XY
    prA = a;
    prB = b;
    prC = c;
    prP = p;
    if(!belongingTriangle(prA, prB, prC, prP)) return false;

    //plane XZ
    prA.y = a.z;
    prB.y = b.z;
    prC.y = c.z;
    prP.y = p.z;
    if(!belongingTriangle(prA, prB, prC, prP)) return false;

    //plane YZ
    prA.x = a.y;
    prB.x = b.y;
    prC.x = c.y;
    prP.x = p.y;
    prA.y = a.z;
    prB.y = b.z;
    prC.y = c.z;
    prP.y = p.z;
    if(!belongingTriangle(prA, prB, prC, prP)) return false;

    return true;
}

bool Mesh::getIntersection(const Ray & ray, float & t, Vec3<float> & normal) const{
	Plane plane;
	Vec3<float> normalOutput, vertices4;
	bool colision=false;
	float pointIntersection;
	t=inf;
	
	for(size_t i = 0; i < poligons.size(); i++) {	
		plane.setPlane(poligons[i].vertices1,poligons[i].vertices2,poligons[i].vertices3);
		if(plane.getIntersection(ray,pointIntersection,normal)) {
			vertices4 = ray.eval(pointIntersection);

            if(getIntersectionTriangle(poligons[i].vertices1, poligons[i].vertices2, poligons[i].vertices3, vertices4) && pointIntersection < t) {
                t=pointIntersection;
                normalOutput=normal;
                colision=true;
            }
        }
	}

	if(colision) {
		normal = normalOutput;
		return true;
	}

	return false;
}

void Mesh::load(const std::string & fileName) {
	Poligon poligon;
    //Before there was not c_str
	std::ifstream file(std::string("scenes/" + fileName).c_str(), std::ifstream::in);
	while(!file.eof() && file) {
		file >> poligon.vertices1.x >> poligon.vertices1.y >> poligon.vertices1.z;
		file >> poligon.vertices2.x >> poligon.vertices2.y >> poligon.vertices2.z;
		file >> poligon.vertices3.x >> poligon.vertices3.y >> poligon.vertices3.z;
        std::cout << poligon.vertices1.x << ' ' << poligon.vertices1.y << ' ' << poligon.vertices1.z << " + ";
        std::cout << position.x << ' ' << position.y << ' ' << position.z << " = ";
        poligon.vertices1 += position;
        std::cout << poligon.vertices1.x << ' ' << poligon.vertices1.y << ' ' << poligon.vertices1.z << std::endl;
        std::cout << poligon.vertices2.x << ' ' << poligon.vertices2.y << ' ' << poligon.vertices2.z << " + ";
        std::cout << position.x << ' ' << position.y << ' ' << position.z << " = ";
        poligon.vertices2 += position;
        std::cout << poligon.vertices2.x << ' ' << poligon.vertices2.y << ' ' << poligon.vertices2.z << std::endl;
        std::cout << poligon.vertices3.x << ' ' << poligon.vertices3.y << ' ' << poligon.vertices3.z << " + ";
        std::cout << position.x << ' ' << position.y << ' ' << position.z << " = ";
        poligon.vertices3 += position;
        std::cout << poligon.vertices3.x << ' ' << poligon.vertices3.y << ' ' << poligon.vertices3.z << std::endl;
        std::cout << std::endl;
		poligons.push_back(poligon);
	}
}

void Mesh::init(const Block & block) {
	position = block.getVariable("pos").vectorValue;
    std::cout << "Read position: " << position.x << ' ' << position.y << ' ' << position.z << std::endl;
    load(block.getVariable("file").stringValue);
	material = MaterialManager::getMaterial(block.getVariable("material").stringValue);
}

