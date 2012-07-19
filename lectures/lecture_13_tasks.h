0 <= curX <= 640
0 <= curY <= 480

realSizeX
realSizeY

Camera

* Соотношение реального размера и размера сетки для пикселей
* Правильный рассчёт выпускаемого луча

SimpleMaterial

* Параметры материала: reflectance (цвет), emittance (цвет)
* virtual Vec3<float> getColor(const Vec3<float> & color) = 0; // return emittance + getBRDF() * reflectance * color;
* Init

Factory

* Init материалов

Renderer

Vec3<float> pathTrace(Scene, Ray, Depth) {
	
	Проверяем пересечение с чем-либо
	
	Если пересечения нет, то вернуть цвет фона
	Если глубина луча больше допустимой, вернуть чёрный цвет
	
	Вычисляем отражённый луч методом interact у IMaterial
	Вычисляем BDRF методом getBDRF у IMaterial
	Вычисляем cosOmega = dot(n, newRay.direction);
	
	Вычисляем цвет отражённого луча, вызывая pathTrace
	
	Финальный цвет вычисляем по формуле getColor(BRDF * cosOmega * цвет отражённого луча)
}

