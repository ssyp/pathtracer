#include "Camera.h"
#include <cmath>
Camera::Camera(const Vec3<float> & pos, const Vec3<float> & point, const float angle, const int _camDpiX, const int _camDpiY, const int _realDpiX, const int _realDpiY) {
	position = pos;
	direct  = point-pos;
	direct.normalize();
	camDpiX = _camDpiX;
	camDpiY = _camDpiY;
	realDpiX = _realDpiX;
	realDpiY = _realDpiY;
	kX = realDpiX / static_cast<float>(camDpiX);
	kY = realDpiY / static_cast<float>(camDpiY);
	this->angle = angle;
}

void Camera::setPos(const Vec3<float> & vec) {
	position = vec;
}

Vec3<float> Camera::getPos() const {
	return position;
}

void Camera::setDir(const Vec3<float> & vec) {
	direct = vec;
}

Vec3<float> Camera::getDir() const {
	return direct;
}

float Camera::getAngle() const {
	return angle;
}

int Camera::getDpiX() const {
	return camDpiX;
}

int Camera::getDpiY() const {
	return camDpiY;
}

Ray Camera::genRay(int curX, int curY, int distance)
{
	float dist = (realDpiX / 2.0 * tan(angle));
	Vec3<float> vert(0,0,1);
	Vec3<float> vecX = cross(direct, vert);
	Vec3<float> vecY = cross(vecX, direct);

	vecX.normalize(); vecY.normalize();

	Vec3<float> newVec = vecX * static_cast<float>(curX) * kX + vecY * static_cast<float>(curY) * kY  + direct * static_cast<float>(dist); //vecX.x * curX + vecY.x * curY, vecX.y * curX + vecY.y * curY, vecX.z * curX + vecY.z * curY);
	newVec.normalize();

	Ray newRay(getPos(), newVec);

	return newRay;
}
