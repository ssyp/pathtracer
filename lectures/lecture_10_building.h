Как собираются программы
----

*.h

*.cpp


*.cpp -> Compiler -> *.obj -> Linker -> 

-> executable (*.exe *.macos *.a)
-> static library (.lib)
-> dynamic library (*.dll *.so *.dylib *.ppu)

1.cpp

void f() { std::cout << "1.cpp"; }

2.cpp

void f() { std::cout << "2.cpp"; }

1.obj 2.obj

redefined symbol

----

common.h

void f() { std::cout << "f"; }

1.cpp

#include "common.h"

2.cpp

#include "common.h

----

common.h

extern void f();
extern int value;

common.cpp

#include "common.h"

void f() { std::cout << "f"; }

1.cpp

#include "common.h"

2.cpp

#include "common.h"

unresolved symbol

----

Задачи:

1. Скрыть реализацию парсера и реализовать все его методы
2. Метод getBlock должен принимать индекс
3. Собрать тестовую сцену
4. Попробовать порейстрейсить и сохранить картинку
5. Разобраться с SDL (http://www.sdltutorials.com/sdl-tutorial-basics)
