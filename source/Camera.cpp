#include "Camera.h"

Camera::Camera(const Vec3<float> & pos, const Vec3<float> & d, float angel, int _camDpiX, int _camDpiY, int _realDpiX, int _realDpiY) {
	position = pos;
	direct  = d;
	camDpiX = _camDpiX;
	camDpiY = _camDpiY;
	realDpiX = _realDpiX;
	realDpiY = _realDpiY;
	kX = realDpiX / static_cast<float>(camDpiX);
	kY = realDpiY / static_cast<float>(camDpiY);
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
	Vec3<float> vert(0,0,1);
	Vec3<float> vecX = direct.cross(vert);
	Vec3<float> vecY = vecX.cross(direct);

	vecX.normalize(); vecY.normalize();

	Vec3<float> newVec = vecX * static_cast<float>(curX) * kX + vecY * static_cast<float>(curY) * kY + direct * static_cast<float>(distance); //vecX.x * curX + vecY.x * curY, vecX.y * curX + vecY.y * curY, vecX.z * curX + vecY.z * curY);
	newVec.normalize();

	Ray newRay(getPos(), newVec);

	return newRay;
}
