-1 < x < 1
-1 < y < 1
z = sqrt(1 - x^2 - y^2)

v(x,y,z)

n

rand_v

dir_x = cross(n,rand_v);
dir_y = cross(n,dir_x);

v = x * dir_x + y * dir_y + z * n