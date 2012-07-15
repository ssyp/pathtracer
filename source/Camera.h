#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vec3.h"

class Camera {
	public:
		Camera(Vec3<float>& pos, Vec3<float>& d, int x, int y);
		Vec3<float> getPos() const;
		Vec3<float> getDir() const;
		int getDpiX() const;
		int getDpiY() const;
	private:
		Vec3<float> position;
		Vec3<float> direct;
		int dpiX;
		int dpiY;
		int screenSizeX, screenSizeY;
};

#endif
