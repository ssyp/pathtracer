#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Ray.h"
#include "Vec3.h"

using namespace Math;

class Camera {
	public:
		Camera(Vec3<float> & pos, Vec3<float> & d, float angel, int x, int y);

		void setPos(Vec3<float> & vec);
		Vec3<float> getPos() const;

		void setDir(Vec3<float> & vec);
		Vec3<float> getDir() const;

		float getAngel() const;

		int getDpiX() const;
		int getDpiY() const;

		Ray & genRay(int x, int y, int z);

	private:
		Vec3<float> position;
		Vec3<float> direct;

		int dpiX;
		int dpiY;

		int screenSizeX, screenSizeY;
		
		float angel;
};

#endif
