1. ����� � ������

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

2. ���������

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

<���>operator <���>


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
			// �������������� ������ � �����
		}
};

String s1("1335");
int b = static_cast<int>(s1);

String s1("first string");
String s2("second string");

String s3 = s1 + s2;
s3 == "first stringsecond string";


<��� ������������� ��������> operator<������>(���������)

������� ��������: ��� ����������

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

�������� ��������: ���� ��������

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

3. �������������� �����

// C
float a = 3.14f;
int b = (int)a; // b == 3

// C++
static_cast � ���������� �������������� ����� � �++

float a = 3.14f;
int b = static_cast<int>(a); // b == 3

reinterpret_cast

type1 a;
type2 b = static_cast<type2>(a);

--

4. ������� � �������� �������

����� ���������


������� ������� ������������ ���� ����� (x,y)

�������� ��� ���������:

* �������� 
	v1(x1,y1), v2(x2,y2)
	v1 + v2 = v3(x1 + x2,y1 + y2)
	
* ���������

* ��������� �� ���������
	v1(x1,y1)
	
	v1 * k = v2(x1 * k,y1 * k)
	
* ����� �������
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

������, ������� ��������� ����� ���������� ���������������.

--

��������� ������������ (dot product)

v1(x1,y1)
v2(x2,y2)

1. dot(v1,v2) � �����
2. dot(v1,v2) = |v1|*|v2|*cos(v1^v2);
3. dot(v1,v2) = x1*x2 + y1*y2;

v1(x1,y1)
v2(x2,y2)

cos(v1^v2) = dot(v1,v2) / (|v1| * |v2|)

���� ��� ������� ���������������, �� ������� ���� ����� ��������� ����� �� ���������� ������������.

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

����

����� ������, �� �� ����� �����

y(x)

position(x_p,y_p,z_p)
direction(x_d,y_d,z_d)

x(t) = x_p + x_d * t
y(t) = y_p + y_d * t
z(t) = z_p + z_d * t

--

���������

|A1x + B1y + C1z + D1 = 0
|A2x + B2y + C2z + D2 = 0

Ax + By + Cz + D = 0;

��� �������
����� � ������


p(x1,y1,z2)
(A,B,C,D)

Ax + By + Cz + D = 0;

Ax1 + By1 + Cz2 + D == �����


��������� � ��� ��������� ����� ������� ����������(x,y,z), ����� ��� ��������� Ax + By + Cz + D == 0. ���� ��������� ������� ����-�� A,B,C,D.

��������� xy

z = 0
(0,0,1,0)

v(285438,-42,0);

A*x + B*y + C*z + D = 0

��������� xy, �������� �� 5 ����� �� z

z = 5
(0,0,1,-5)
(0,0,1)
v(285438,-42,0);

��������� zx, ��������� �� -10 �� y

y = -10
(0,1,0,10)

(A,B,C,D)

A,B,C ���������� ������, ���������������� ��������� (�������)
D ���� ���������� �� ������ ��������� �� ��������� �� �������

--

��������� ������������ (cross product)

v1(x1,y1,z1)
v2(x2,y2,z2)

1. cross(v1,v2) == ������
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
v3 = cross(v1,v2); // �������

(A,B,C) = v3

A*x + B*y + C*z + D = 0

A*x1 + B*y1 + C*z1 = -D

dot(n,p1) = -D

--

��������� � ����

A*x + B*y + C*z + D = 0

p(x_p,y_p,z_p)
d(x_d,y_d,z_p)

r(t) = p + d * t

ip(x_ip,y_ip,z_ip)

1. ip ����� �� ���������
2. ip ����� �� ����

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

������:

1. �������� ���
2. �������������� �������: ���� ������ v1(x,y), ����� ����� ���������������� ��� � �������� ����������
















