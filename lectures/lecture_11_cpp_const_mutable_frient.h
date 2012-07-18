Ещё совсем-совсем чуть-чуть ваще немного С++ (const mutable friend)
----

1. const_cast

Снимает действие модификатора const

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

Позволяет менять поля в const методах

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

Позволяет получать доступ до private и protected полей извне

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

1. Сборка сцен из файлов

class Parser;
class Block;

class ISurface {
	virtual void init(const Block & block) = 0; // берём все нужны параметры из мапы и инициализируем внутреннее представление
}

class SurfaceFactory {
	public:
		
		ISurface * createSurface(const Block & block); // смотрим тип блока, создаём нужный instance ISurface и вызываем у него метод init с нужным блоком
};

2. Менеджмент материалов

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

1. Отрефакторить код
 * Оформить по codestyle
 (+) Разбить на функции

2. Добавить поддержку материалов

Materials {
	Material simple name:"material1" параметр:значение параметр:значение
	Material reflective параметр:значение параметр:значение
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

 * Добавить разбор библиотеки материалов

3. Работоспособность path tracer'а

 * Вывод картинки
 * Правильная математика
 * SDL + class Application + вывод изображения

----

inline

void func() {
	std::cout << "hi" << std::endl;
}

func();

/*
запихать все элементы в стек
запихать ещё всякое в стек
вызвать функцию
выполнить код
выпихать всё из стека
*/

inline void func() {
	std::cout << "hi" << std::endl;
}

/*
выполнить код
*/
