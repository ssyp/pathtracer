#include "Camera.h"

Camera::Camera(Vec3<float> & pos, Vec3<float> & d, float angel, int x, int y) {
	position = pos;
	direct  = d;
	dpiX = x;
	dpiY = y;
	screenSizeX = 1024 / dpiX;
	screenSizeY = 600 / dpiY;
	this->angel = angel;
}

void Camera::setPos(Vec3<float> & vec) {
	position = vec;
}

Vec3<float> Camera::getPos() const {
	return position;
}

void Camera::setDir(Vec3<float> & vec) {
	direct = vec;
}

Vec3<float> Camera::getDir() const {
	return direct;
}

float Camera::getAngel() const {
	return angel;
}

int Camera::getDpiX() const {
	return dpiX;
}

int Camera::getDpiY() const {
	return dpiY;
}

Ray & Camera::genRay(int curX, int curY, int distance)
{
	Vec3<float> vert(0,1,0);
	Vec3<float> vecX = direct.cross(vert);
	Vec3<float> vecY = vecX.cross(direct);

	vecX.normalize(); vecY.normalize();

	Vec3<float> newVec = vecX * curX + vecY * curY; //vecX.x * curX + vecY.x * curY, vecX.y * curX + vecY.y * curY, vecX.z * curX + vecY.z * curY);

	Ray newRay(getPos(), newVec);

	return newRay;
}
