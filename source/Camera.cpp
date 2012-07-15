#include "Camera.h"

Camera::Camera(Vec3<float>& pos, Vec3<float>& d, int x, int y)
{
	position = pos;
	direct  = d;
	dpiX = x;
	dpiY = y;
}

Vec3<float>& getPos() const
{
	return position;
}
Vec3<float>& getDir() const
{
	return direct;
}
int getDpiX() const
{
	return dpiX;
}
int getDpiY() const
{
	return dpiY;
}
