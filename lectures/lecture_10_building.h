﻿��� ���������� ���������
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

������:

1. ������ ���������� ������� � ����������� ��� ��� ������
2. ����� getBlock ������ ��������� ������
3. ������� �������� �����
4. ����������� �������������� � ��������� ��������
5. ����������� � SDL (http://www.sdltutorials.com/sdl-tutorial-basics)
