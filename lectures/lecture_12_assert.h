assert(логическое выражение);


Если условие верное, то ничего не происходит, программа выпоняется как обычно
Если условие провалено, то программа "падает" на этой строчке

#include <cassert>

void MonteCarloImage::add(int x, int y) {
	assert(x < w);
	assert(y < h);
}

1. Проверка входных условий

Набор assert'ов внутри функции/метода, обычно идут самыми первыми и проверяют все краевые случаи

assert(x < w && "MonteCarloImage::add(): x bounds error");

2. Unit test

Примитивная проверка на работу функционала класса

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

1. Проверку входных параметров на все методы
2. Unit test на функциональность каждого метода

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
