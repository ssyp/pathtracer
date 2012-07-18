��� ������-������ ����-���� ���� ������� �++ (const mutable friend)
----

1. const_cast

������� �������� ������������ const

class Foo {
	public:
		
		void foo() const {
			std::cout << "Foo::foo()" << std::endl;
		}
		
		void bar() {
			value++;
		}
		
	private:
		
		int value;
};

Foo f;

void func(const Foo & link) {
	Foo & unsafe_link = const_cast<Foo>(link);
	
	unsafe_link.bar();
}

2. mutable

��������� ������ ���� � const �������

class Foo {
	public:
		
		void foo() const {
			value = 5; // error
			unsafe_value++; // ok
		}
		
	private:
		
		int value;
		mutable int unsafe_value;
};

3. friend

��������� �������� ������ �� private � protected ����� �����

class Foo {
	private:
		
		int value;
		mutable int unsafe_value;
		
};

friend class Foo;

Foo f;
f.value++;

----
Scene

1. ������ ���� �� ������

class Parser;
class Block;

class ISurface {
	virtual void init(const Block & block) = 0; // ���� ��� ����� ��������� �� ���� � �������������� ���������� �������������
}

class SurfaceFactory {
	public:
		
		ISurface * createSurface(const Block & block); // ������� ��� �����, ������ ������ instance ISurface � �������� � ���� ����� init � ������ ������
};

2. ���������� ����������

class MaterialManager {
	public:
		
		static IMaterial * getMaterial(const std::string & string);
		static addMaterial
		static deleteMaterial
		
	private:
		
		static std::map<std::string,IMaterial *> materials;
		
		
};

class IMaterial {
	public:
		virtual void init(const Block & block) = 0;
};

Parser

1. ������������� ���
 * �������� �� codestyle
 (+) ������� �� �������

2. �������� ��������� ����������

Materials {
	Material simple name:"material1" ��������:�������� ��������:��������
	Material reflective ��������:�������� ��������:��������
}

Scene "name" {
	Surface sphere material:"material1" ...
	Surface ...
}

class Parser {
	private:
		std::vector<Block> surface_blocks;
		std::vector<Block> material_blocks;
};

 * �������� ������ ���������� ����������

3. ����������������� path tracer'�

 * ����� ��������
 * ���������� ����������
 * SDL + class Application + ����� �����������

----

inline

void func() {
	std::cout << "hi" << std::endl;
}

func();

/*
�������� ��� �������� � ����
�������� ��� ������ � ����
������� �������
��������� ���
�������� �� �� �����
*/

inline void func() {
	std::cout << "hi" << std::endl;
}

/*
��������� ���
*/
