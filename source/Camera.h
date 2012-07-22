#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Ray.h"
#include "Vec3.h"
#include "MathUtils.h"

using namespace Math;

class Camera {
	public:
		Camera(const Vec3<float> & pos, const Vec3<float> & d, const float angle, const int camDpiX, const int camDpiY, const int realDpiX, const int realDpiY);

		void setPos(const Vec3<float> & vec);
		Vec3<float> getPos() const;

		void setDir(const Vec3<float> & vec);
		Vec3<float> getDir() const;

		float getAngle() const;

		int getDpiX() const;
		int getDpiY() const;

		Ray genRay(int x, int y);

	private:
		Vec3<float> position;
		Vec3<float> direct;

		int camDpiX, realDpiX;
		int camDpiY, realDpiY;

		float kX, kY;
		
		float angle;
};

#endif
