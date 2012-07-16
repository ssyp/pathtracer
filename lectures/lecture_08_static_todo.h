// TODO:

Generic:
1. No warnings
2. Return values

Codestyle:
1. Всё внутреннее представление — в private
2. Все одинаковые get/set рядом, set выше

Renderer:
1. Генерить луч от камеры с учётом её направления, утащить рассчёт этого луча в метод камеры
3. Цвета умножаются
4. Деструктор у MonteCarloImage
5. У MonteCarloImage сделать метод save

Math:
1. operator * (vec, vec)
2. 	bool f_eq(float v1, float v2) {
		// вернуть true, если модуль разности этих чисел очень маленький
	}
3. Математические константы (infinity (100000000.0f), epsilon (0.001f)), отдельный .h файл для f_eq и для констант
4. Отдельный namespace (Math) для математики
// 5. Получение случайного единичного вектора по полусфере от нормали
// 6. Получение случайного единичного вектора, лежащего в плоскости

Parser:
1. Сделать парсер независимым от структуры surface'ов (при добавлении нового surface'а код парсера не должен переписываться)

Scene:
1. У Sphere не пересчитывать dot
2. Проверка на D > 0 не нужна
3. Сделать Mesh
 * Загрузка пока 	
4. Сделать ещё одну иерархию IMaterial, сделать от него наследник SimpleMaterial;

IMaterial {
	virtual float getBRDF(Vec3 in, Vec3 out, Vec3 n) = 0;
	virtual Vec3 interact(Vec3 in, Vec3 ip, Vec3 n) = 0;
};

SimpleMaterial : public IMaterial {
	 getBRDF == 1
	 // interact == случайный луч по полусфере от нормали
};

----
SDL
