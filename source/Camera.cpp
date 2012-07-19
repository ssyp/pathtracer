#include "Camera.h"

Camera::Camera(Vec3<float> & pos, Vec3<float> & d, float angel, int _camDpiX, int _camDpiY, int _realDpiX, int _realDpiY) {
	position = pos;
	direct  = d;
	camDpiX = _camDpiX;
	camDpiY = _camDpiY;
	realDpiX = _realDpiX;
	realDpiY = _realDpiY;
	kX = realDpiX / camDpiX;
	kY = realDpiY / camDpiY;
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
	return camDpiX;
}

int Camera::getDpiY() const {
	return camDpiY;
}

Ray Camera::genRay(int curX, int curY, int distance)
{
	Vec3<float> vert(0,1,0);
	Vec3<float> vecX = direct.cross(vert);
	Vec3<float> vecY = vecX.cross(direct);

	vecX.normalize(); vecY.normalize();

	Vec3<float> newVec = vecX * curX * kX + vecY * curY * kY + direct * distance; //vecX.x * curX + vecY.x * curY, vecX.y * curX + vecY.y * curY, vecX.z * curX + vecY.z * curY);
	newVec.normalize();

	Ray newRay(getPos(), newVec);

	return newRay;
}
