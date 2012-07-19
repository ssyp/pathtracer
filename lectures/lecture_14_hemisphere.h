Сферические координаты

(x,y,z)

(phi,alpha,r)

(phi,alpha,r) -> (x,y,z) (?)

0 <= phi <= 2*pi
-pi/2 <= alpha <= pi/2

x = r * cos(alpha) * cos(phi)
y = r * cos(alpha) * sin(phi)
z = r * sin(alpha)

----

Рандомная точка на единичной сфере

1. Случайно генерируем alpha и phi

alpha in [-pi/2;pi/2]
phi in [0;2*pi]

2. Переводим из (phi,alpha,1) -> (x,y,z)

Рандомная точка на единичной полусфере, которая смотрит "вправо"

1. Случайно генерируем alpha и phi (чуть похитрее)

alpha in [0;pi/2]
phi in [0;2*pi]

2. Переводим из (phi,alpha,1) -> (x,y,z)
