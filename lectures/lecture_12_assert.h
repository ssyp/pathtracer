assert(���������� ���������);


���� ������� ������, �� ������ �� ����������, ��������� ���������� ��� ������
���� ������� ���������, �� ��������� "������" �� ���� �������

#include <cassert>

void MonteCarloImage::add(int x, int y) {
	assert(x < w);
	assert(y < h);
}

1. �������� ������� �������

����� assert'�� ������ �������/������, ������ ���� ������ ������� � ��������� ��� ������� ������

assert(x < w && "MonteCarloImage::add(): x bounds error");

2. Unit test

����������� �������� �� ������ ����������� ������

Vec3<float>

Vec3<float> v1(1.0f,2.0f,3.0f);
assert(v1.x == 1.0f);
assert(v1.y == 2.0f);
assert(v1.z == 3.0f);

+

-

dot

cross

----

MonteCarloImage

1. �������� ������� ���������� �� ��� ������
2. Unit test �� ���������������� ������� ������

Camera

Ray

getRandomPointOnHemisphere
getRandomPointOnPlane

ISurface

getIntersection

Parser

----

UnitTests.h

namespace UnitTest {
	extern void testCamera();
	extern void testMonteCarloImage();
	extern void testMath();
	extern void testSurfaces();
}
