Ввводная часть по С++
--

Типы данных: целочисленный (int), вещественный (float), булевый (bool)

Синтаксис: тип имя_переменной;

Ex (Pascal):

Var
	a: integer;
	b: real;
	c: boolean;
	
	
Ex (C++):

int a;
float b;
bool c;

--

Условия

C++: if(condition) /* code */ else /* code */

Pascal: if(condition) then /* code */ else /* code */

--
Pascal: begin end

if(a = 5) then begin
	{ code }
end;

C++: { }

if(a == 5) {
	/* code */
}

--
Операторы сравнения

Pascal: =, <>, <, >, <=, >=, not, and, or, xor
C++: ==, !=, <, >, <=, >=, !, &&, ||

--
Присваивание переменных

Pascal: переменная := значение;
С++: переменная = значение;

--
Циклы

Pascal:
for i:=1 to N do { code };

C++:
for(инициализация;условия завершения;шаг) /* code */;

for(int i = 0; i < 10; i++) /* code */;

while(condition) /* code */;

do { } while(condition);

--

for(int i = 0; i <= 12; i = i+3);

--
Функции

Pascal: function <name>({var} <name>:<type>, ...) : <return type>

C++: <return type> <name>(<type> <name>, ...);


Pascal: function eval(digit : interger, frac : real) : real;
C++: float eval(int digit, float frac);

Pascal: procedure is_actual(c : integer);
C++: void is_actual(int c);

Pascal: eval:=5; или result:=5;
C++: return 5;

Pascal: если мы в процедуре, то можем выйти из любой её точки через exit
С++: return;


Ex (C++):
void do_something(int a) {
	if(a == 5) return;
	
	int b = a + 5;
}

float get_length(float x, float y) {
	return x*x + y*y;
}

--
Ввод-вывод

Pascal: write, writeln, read, readln
C: printf,scanf
C++: std::cin, std::cout


Ex (Pascal):

Var
	value:integer;
	name:string;
Begin
	Write(name);
	Write(': ');
	Writeln(value);
End.

name == 'Ssyp';
value == 67;

Ssyp: 67

Ex (C):

int main() {
	int value;
	char name;
	
	printf("%c: %d\n",name,value);
	
	return 0;
}

Ex (C++):

int main() {
	
	int value;
	char name;
	
	std::cout << name << ": " << value << std::endl;
	
	int key;
	
	std::cin >> key;
	
	return 0;
}

Нужно подключать библиотеку iostream через
#include <iostream>

--
char -- символьный тип

char key = 'a';

key = 100;

-128 <= key <= 127

--
Массивы

синтаксис: <тип> <имя>[размер][...][...];

int array[10];

0,...,9

int array2d[10][20];


int value = array[5];
array[7] = 6;

--
Задача: написать морской бой на поле 10х10

Требования:
* Управление через консоль
* Расстановка кораблей
 (v) Расстановка руками через консоль
 (+) Автоматическая расстановка с учётом правил (нельзя ставить рядом)
* Вся игровая логика морского боя
 (+) Некий аналог A.I.
* Вывод игрового поля
