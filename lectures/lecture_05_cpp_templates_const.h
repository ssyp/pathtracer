Advanced C++
----

1. —сылки


int a = 5;
int & b = a;

b = 3;
// a == ?




int a = 5;
int * b = &a;

*b = 3;
// a == ?


void func(int & a) {
	a = 4;
}

int b = 5;
func(b);


----

class Foo {
	public:
		Foo() {
			// много кода
		}
		
		Foo(Foo & f) {
			// много кода
		}
};


class Weapon;
class Hero;

class Field;

fight(Field & field,Hero & hero);

field.

Foo f;
Foo f2 = f;

Foo &f3 = f;


----

const


int a = 5;
const int b = 6;

b = 10; // error

fight(const Field & field,Hero & hero) {
	
}

class Field {
	public:
		
		void generate() {
			// генерируем поле
		}
		
		int getSize() const {
			return 10;
		}
};


Field f;
const Field &f_link = f;

f_link.generate(); // error
f.generate(); // ok

f_link.getSize(); // ok
f.getSize(); // ok

----

Ўаблоны

template<class им€1,...>
class »м€ ласса {
};

template<class T>
class Foo {
	public:
		T value;
};

Foo<int> foo; //

/*
class Foo_int {
	public:
		int value;
};
 */

template<class T>
class Digit {
	private:
		T value;
		
	public:
		
		Digit<T> operator+(const Digit<T> &digit) const { 
			Digit result;
			result.value = value + digit.value;
			
			return result;
		}
};

Digit<float> d1;
Digit<float> d2;
Digit<float> d3 = d1 + d2;

Digit<int>
Digit<bool>
Digit<char *>

template<class T>
class Digit {
	public:
		
		Digit<T> operator+(const Digit<T> &digit) const;
};

template<class T>
Digit<T> Digit<T>::operator+(const Digit<T> &digit) const {
	
}

ѕисать реализацию шаблонов можно только в .h файлах.

----

STL (Standart Template Library)

vector
list
map
string

1. vector Ч это обЄртка над массивом (данные расположены линейно в пам€ти)

std::vector<int> array;

array.push_back(5);
array.push_front(3);

// array == 3 5

array.size();
array[1] = 1;
array.sort(); // operator <
array.clear();

2. list Ч это обЄртка над списком (данные расположены как угодно в пам€ти)

std::list<int> list;

list.push_back(5);
list.push_front(5);

list.size();
list.clear();

3. map Ч это обЄртка над ассоциативным массивом

std::map<int,char> map;

map[58] = 'c';
map[3] = 'a';

{(58,'c'),(3,'a')}

char result = map[58];

std::map<char,int> map2;

map2['g'] = 4;
map2['a'] = 48;

int result2 = map2['g'];

≈сли в ассоциативном массиве обратитьс€ по несущесвующему ключу, то будет краш.

4. string Ч это обЄртка над строками

std::string str;
std::string str2 = "1a24bcabc";
std::string str3("-erabcabc");

str = str2 + str3; // 1a23bcabc-erabcabc

str.size();

const char * p = str.c_str();

std::map<std::string,int> map;

map["Test str"] = 5;
map["Abc"] = 6;

----

STL + »тераторы

std::list<int> list;

list.begin();
list.end();

for(std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
	std::cout << *it;
}

----

std::vector<int> vector;

for(int i = 0; i < vector.size(); ++i) {
	std::cout << vector[i];
}

for(std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
	std::cout << *it;
}

int array[10];

for(int * p = array; p != &array[10]; ++p) {
	std::cout << *p;
}

----

std::map<int,char> map;

for(std::map<int,char>::iterator it = map.begin(); it != map.end(); ++it) {
	std::cout << "Key: " << it->first << "; Value: " << it->second << std::endl;
}

----

erase(итератор);


std::list<char> list;

list.push_back(5);
list.push_back(6);
list.push_back(-1);
list.push_back(52);
list.push_back(100);
list.push_back(3);
list.push_back(52);

for(std::list<char>::iterator it = list.begin(); it != list.end(); ++it) {
	if(*it == 52) {
		list.erase(it);
	}
}

----

std::map<std::string,int> map;


map["Test string"] = 5;

int result = map["I want to work in the video game industry"]; // crash

std::map<std::string,int>::iterator it = map.find("I want to work in the video game industry");
it == map.end();

----

1. Ўаблон математического вектора (3д)
	* C перегруженными операци€ми +, -, * (на константу)
	* ќперации получени€ длины вектора
	* Ќормализаци€
	* dot product
	* cross product
	(+) ¬езде, где состо€ние объекта не мен€етс€ писать const + const type &
	(+) ѕереопределить операции +=, -=, *=
	(+) ќператоры сравнени€ ==, !=, должен работать код std::map<класс вектора, не важно что>

