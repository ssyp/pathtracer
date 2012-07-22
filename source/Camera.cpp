#include "Camera.h"
#include <cmath>

Camera::Camera(const Vec3<float> & pos, const Vec3<float> & point, const float angle, const int camDpiX1, const int camDpiY1, const int realDpiX1, const int realDpiY1) {
	position = pos;
	direct  = point - pos;
	direct.normalize();
	camDpiX = camDpiX1;
	camDpiY = camDpiY1;
	realDpiX = realDpiX1;
	realDpiY = realDpiY1;
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

Ray Camera::genRay(int curX, int curY)
{
	float dist = static_cast<float>(realDpiX / 2.0 * tan(angle));
	Vec3<float> vert(0, 0, 1);
	Vec3<float> vecX = cross(direct, vert);
	Vec3<float> vecY = cross(vecX, direct);

	vecX.normalize(); vecY.normalize();

	Vec3<float> newVec = vecX * static_cast<float>(curX) * kX + vecY * static_cast<float>(curY) * kY  + direct * static_cast<float>(dist); //vecX.x * curX + vecY.x * curY, vecX.y * curX + vecY.y * curY, vecX.z * curX + vecY.z * curY);
	newVec.normalize();

	Ray newRay(getPos(), newVec);

	return newRay;
}
