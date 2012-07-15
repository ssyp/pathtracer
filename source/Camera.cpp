#include "Camera.h"

Camera::Camera(Vector& pos, Vector& d, int x, int y)
{
	position = pos;
	direct  = d;
	dpiX = x;
	dpiY = y;
}

Vector& getPos() const
{
	return position;
}
Vector& getDir() const
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
