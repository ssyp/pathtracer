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

Этот код:		color = color * (surf->getMaterial())->getBRDF(ray.direction, newRay.direction, normal);
				color = color * pathTrace(newRay, scene, color);
				
Заменить на:	IMaterial * material = surf->getMaterial();
				color = material->getColor(color) * dot(n,отражённого луча) * pathTrace(newRay, scene, color);
