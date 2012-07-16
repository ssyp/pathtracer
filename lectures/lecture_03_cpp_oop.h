ООП в С++
----

Класс — это структура данных, описывающая свойства и операции над какой-либо сущностью.

class <имя> {
	public:
		
		int age;
		char name[10];
		
		void veryImportantFunc() {
			
		}
};

----

class Car {
	public:
		
		char number[6];
		char city_code[3];
		char model[10];
		
		int color;
};

class Place {
	public:
		
		bool is_free;
		int park_time_start;
		int money_payed;
		int money_per_hour;
		
		Car * car;
};

class Parking {
	public:
		
		Place * places;
		int place_count;
		int car_count;
		
		void setSize(int size) {
			
		}
		
		void addCar(Car * car) {
			// добавляем машину на первое свободное место
		}
		
		void removeCar(Car * car) {
			// освобождаем занятое машиной место
		}
		
		int query(int color, int park_time_min) {
			int count = 0;
			
			for(int i = 0; i < place_count; ++i) {
				if(places[i].is_free && (places[i].car->color == color) && (places[i].park_time_start > park_time_min)) ++count;
			}
			
			return count;
		}
};

----

Constructor/Destructor

Инкапсуляция — сокрытие данных\реализации
Наследование — передача свойств\полей\методов родительского класса дочернему
Полиморфизм — множественное представление


class Parking {
	public:
		
		Place * places;
		int place_count;
		int car_count;
		
		Parking() {
			place_count = 10;
			car_count = 0;
			places = new Place[place_count];
		}
		
		Parking(int size) {
			place_count = size;
			car_count = 0;
			places = new Place[place_count];
		}
		
		~Parking() {
			delete [] places;
		}
		
		void addCar(Car * car) {
			// добавляем машину на первое свободное место
		}
		
		void removeCar(Car * car) {
			// освобождаем занятое машиной место
		}
		
		int query(int color, int park_time_min) {
			int count = 0;
			
			for(int i = 0; i < place_count; ++i) {
				if(places[i].is_free && (places[i].car->color == color) && (places[i].park_time_start > park_time_min)) ++count;
			}
			
			return count;
		}
};

Parking parking;
Parking * parking_dynamic = new Parking();


Parking parking(10);
Parking * parking_dynamic = new Parking(10);

delete parking_dynamic;

{
	Parking parking;
}

----

Инкапсуляция

private
protected
public


class Parking {
	private:
		
		Place * places;
		int place_count;
		int car_count;
		
	public:
		
		Parking() {
			place_count = 10;
			car_count = 0;
			places = new Place[place_count];
		}
		
		Parking(int size) {
			place_count = size;
			car_count = 0;
			places = new Place[place_count];
		}
		
		~Parking() {
			delete [] places;
		}
		
		void addCar(Car * car) {
			// добавляем машину на первое свободное место
		}
		
		void removeCar(Car * car) {
			// освобождаем занятое машиной место
		}
		
		int query(int color, int park_time_min) {
			int count = 0;
			
			for(int i = 0; i < place_count; ++i) {
				if(places[i].is_free && (places[i].car->color == color) && (places[i].park_time_start > park_time_min)) ++count;
			}
			
			return count;
		}
};

Parking parking;

parking.places[0]; // compiler error 
parking.car_count; // compiler error

----

Наследование

class Parent {
	private:
		
		int private_field;
		
	protected:
		
		int protected_field;
		
	public:
		
		Parent() {
			std::cout << "Parent ctr" << std::endl;
		}
		
		~Parent() {
			std::cout << "Parent dtr" << std::endl;
		}
		
		int public_field;
		
		void print() {
			std::cout << "Parent print" << std::endl;
		}
};


class Child : public Parent {
	private:
		
		int child_private_field;
		
	public:
		
		Child() {
			std::cout << "Child ctr" << std::endl;
		}
		
		~Child() {
			std::cout << "Child dtr" << std::endl;
		}
		
		void print() {
			std::cout << "Child print" << std::endl;
		}
};

{
	Child child;
}

class Person {
	private:
		int field;
		
	public:
		
		void print() {
			
		}
};

Person == |field|

Person::print(Person * person) {
	
}

Person person;
person.print(); == Person::print(&person);

----

Parent ctr
Child ctr
Child dtr
Parent dtr


Child class == |Parent fields|Child fields|
Parent class == |Parent fields|

Child * child = new Child();
Parent * parent = child;

parent->print(); // == Parent::print(parent)

Parent print

----

Child::print(Child * instance) {
	
}

Parent::print(Parent * instance) {
	
}

----

Полиморфизм

Множественное представление

class Parent {
		указатель на функцию * print_ptr;
	private:
		
		int private_field;
		
	protected:
		
		int protected_field;
		
	public:
		
		Parent() {
			std::cout << "Parent ctr" << std::endl;
			print_ptr = &Parent::print;
		}
		
		~Parent() {
			std::cout << "Parent dtr" << std::endl;
		}
		
		int public_field;
		
		void print_impl() {
			print_ptr();
		}
		
		virtual void print() {
			std::cout << "Parent print" << std::endl;
		}
};


class Child : public Parent {
		
	private:
		
		int child_private_field;
		
	public:
		
		Child() {
			std::cout << "Child ctr" << std::endl;
			print_ptr = &Child::print
		}
		
		~Child() {
			std::cout << "Child dtr" << std::endl;
		}
		
		void print() {
			std::cout << "Child print" << std::endl;
		}
};

Child * child = new Child();
Parent * parent = child;


Child print

----

class Shape {
	public:
		virtual void draw() = 0;
		virtual void move(float dx, float dy) = 0;
		
};

class Circle : public Shape {
	private:
		float x, y;
		float r;
		
	public:
		
		void draw() {
			
		}
		
		void move(float dx, float dy) {
			
		}
};

class Rectangle : public Shape {
	private:
		float min_x, min_y;
		float max_x, max_y;
		
	public:
		
		void draw() {
			
		}
		
		void move(float dx, float dy) {
			
		}
};

Shape shape;

----

overriding == virtual
overloading == одно и то же имя, но разные аргументы

int func(int a);
int func(float a);

func(1);
func(1.0f);

----

РПГ с домиками

1. Есть персонаж, у него есть инвентарь и слоты для оружия и брони
2. Инвентарь — это набор предметов, он конечный
3. Предметы бывают четырёх типов
	* Оружие
	* Броня
	* Свитки (добавки к характеристикам на бой, заканчиваются после боя)
	* Бутыльки (восстанавливают здоровье, заканчиваются сразу после применения)
4. Мир представлен 2д картой, там есть несколько видов локаций (одна локация — одна клетка)
	* Магазин (можно покупать/продавать предметы)
	* Подземелье (встречай и бой со случайным монстром)
	* Гостиница (восстанавливает здоровье)
5. Бой идёт пошагово, монстр и игрок бьют одновременно, можно защищаться, атаковать или воспользоваться предметов в инвентаре

(+) Хорошая организация кода (разделение реализации и описания, структура файлов, грамотный code style)
(+) Боссы
(+) A.I. у монстров (не только атаковать, но и защищаться)
(+) Скиллы у персонажа + прокачка