#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector.h";

class Camera {
	public:
		Camera(Vector& pos, Vector& d, int x, int y);
		Vector& getPos() const;
		Vector& getDir() const;
		int getDpiX() const;
		int getDpiY() const;
	private:
		Vector position;
		Vector direct;
		int dpiX;
		int dpiY;
};

#endif