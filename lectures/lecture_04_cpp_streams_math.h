1. Файлы и потоки

std::cout
std::cin

std::istream
std::ostream

<iostream>

std::ostream cout;
std::istream cin;

--

std::ifstream
std::ofstream

--

ifstream file("test.txt");

if(file) {

}

std::ifstream file;
file.open("test.txt");

--

2. Операторы

operator +
operator -
operator *
operator ==
operator !=
operator <=
operator >=
operator <
operator >

+ - * / ~ = == != <= >= < >

<тип>operator <тип>


class String {
	public:
		char str[255];
		int length;
		
		String operator+(String s) {
			for(int i = length; i < min(s.length,255); ++i) {
				str[i] = s.str[i - length];
			}
		}
		
		int operator int() {
			// преобразование строки в число
		}
};

String s1("1335");
int b = static_cast<int>(s1);

String s1("first string");
String s2("second string");

String s3 = s1 + s2;
s3 == "first stringsecond string";


<тип возвращаемого значения> operator<символ>(параметры)

Унарный оператор: без аргументов

class Digit {
	public:
		int value;
		
		Digit& operator-() {
			value = -value;
			return *this;
		}
};

Digit d;
-d;

Digit e = -d; // d.operator-();

class Vector {
	public:
		float x, y;
		
		Vector(float x_,float y_) { x = x_; y = y_; }
		
		Vector& operator-() {
			x = -x;
			y = -y;
			return *this;
		}
};


Vector vec(1,2);

-vec;

Бинарный оператор: один аргумент

class Vector {
	public:
		float x, y;
		
		Vector(float x_,float y_) { x = x_; y = y_; }
		
		Vector operator-(Vector vector) {
			Vector result(x + vector.x, y + vector.y);
			return result;
		}
};

Vector v1(1,0);
Vector v2(0,1);
Vector v3 = v1 + v2; // (1, 1)

--

3. Преобразование типов

// C
float a = 3.14f;
int b = (int)a; // b == 3

// C++
static_cast — безопасное преобразование типов в С++

float a = 3.14f;
int b = static_cast<int>(a); // b == 3

reinterpret_cast

type1 a;
type2 b = static_cast<type2>(a);

--

4. Вектора и линейная алгебра

Метод координат


Каждому вектору сопоставлена пара чисел (x,y)

Операции над векторами:

* Сложение 
	v1(x1,y1), v2(x2,y2)
	v1 + v2 = v3(x1 + x2,y1 + y2)
	
* Вычитание

* Умножение на константу
	v1(x1,y1)
	
	v1 * k = v2(x1 * k,y1 * k)
	
* Длина вектора
	v(x,y)
	|v| = sqrt(x^2 + y^2);

v(x,y)

v_n(x`,y`) == (x / l, y / l);

1 == sqrt(x`^2 + y`^2);
1 == x`^2 + y`^2


l == 5

5 0
1 0


x` = x / l == x / sqrt(x^2 + y^2);
y` = y / l == y / sqrt(x^2 + y^2);

l == sqrt(x^2 + y^2);
l^2 == x^2 + y^2

Вектор, имеющий единичную длину называется нормализованным.

--

Скалярное произведение (dot product)

v1(x1,y1)
v2(x2,y2)

1. dot(v1,v2) — число
2. dot(v1,v2) = |v1|*|v2|*cos(v1^v2);
3. dot(v1,v2) = x1*x2 + y1*y2;

v1(x1,y1)
v2(x2,y2)

cos(v1^v2) = dot(v1,v2) / (|v1| * |v2|)

Если оба вектора нормализованные, то косинус угла между векторами равен их скалярному произведению.

--

3D

v(x,y,z)

l = |v| = sqrt(x^2 + y^2 + z^2);

v1(x1,y1,z1)
v2(x2,y2,z2)

v1 + v2 = v3(x1 + x2, y1 + y2, z1 + z2);

v(x,y,z)
v_n(x / l, y / l, z / l)

dot(v1,v2) = |v1|*|v2|*cos(v1^v2) = x1*x2 + y1*y2 + z1*z2

--

Луча

Имеет начало, но не имеет конца

y(x)

position(x_p,y_p,z_p)
direction(x_d,y_d,z_d)

x(t) = x_p + x_d * t
y(t) = y_p + y_d * t
z(t) = z_p + z_d * t

--

Плоскость

|A1x + B1y + C1z + D1 = 0
|A2x + B2y + C2z + D2 = 0

Ax + By + Cz + D = 0;

Два вектора
Точка и вектор


p(x1,y1,z2)
(A,B,C,D)

Ax + By + Cz + D = 0;

Ax1 + By1 + Cz2 + D == число


Плоскость — это множество точек имеющих координаты(x,y,z), такие что уравнение Ax + By + Cz + D == 0. Сама плоскость задаётся коэф-ми A,B,C,D.

Плоскость xy

z = 0
(0,0,1,0)

v(285438,-42,0);

A*x + B*y + C*z + D = 0

Плоскость xy, поднятая на 5 вверх по z

z = 5
(0,0,1,-5)
(0,0,1)
v(285438,-42,0);

Плоскость zx, опущенная на -10 по y

y = -10
(0,1,0,10)

(A,B,C,D)

A,B,C составляют вектор, перпендикулярный плоскости (нормаль)
D есть расстояние от начала координат до плоскости по нормали

--

Векторное произведение (cross product)

v1(x1,y1,z1)
v2(x2,y2,z2)

1. cross(v1,v2) == вектор
2. |cross(v1,v2)| == |v1|*|v2|*sin(v1^v2);
3. v3 = cross(v1,v2);

dot(v3,v1) = 0
dot(v3,v2) = 0

--

p1(x1,y1,z1);
p2(x2,y2,z2);
p3(x3,y3,z3);

(A,B,C,D)

v1 = p1 - p2;
v2 = p2 - p3;
v3 = cross(v1,v2); // нормаль

(A,B,C) = v3

A*x + B*y + C*z + D = 0

A*x1 + B*y1 + C*z1 = -D

dot(n,p1) = -D

--

Плоскость и луча

A*x + B*y + C*z + D = 0

p(x_p,y_p,z_p)
d(x_d,y_d,z_p)

r(t) = p + d * t

ip(x_ip,y_ip,z_ip)

1. ip лежит на плоскости
2. ip лежит на луче

A*x_ip + B*y_ip + C*z_ip + D = 0;
x_ip = x_p + t * x_d;
y_ip = y_p + t * y_d;
z_ip = z_p + t * z_d;

A*x_p + B*y_p + C*z_p + t * (A*x_d + B*y_d + C*z_d) + D = 0;
t = -(A*x_p + B*y_p + C*z_p + D) / (A*x_d + B*y_d + C*z_d);


(A,B,C,D)
n(A,B,C)
t = -(dot(n,p) + D) / (dot(n,d));
r(t) = p + t * d;

dot(n,d) != 0

--

Задача:

1. Доделать РПГ
2. Математическая задачка: есть вектор v1(x,y), нужно найти перпендикулярный ему и выписать координаты
















