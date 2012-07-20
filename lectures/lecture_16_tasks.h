----

1. Нужно всё-таки находить точку пересечения и нормаль
2. Нужно, чтобы исходящий луч не проверял пересечение с поверхностью, из которой он выходит

Храним указатель на ISurface в луче

----

1. Добавить в парсер настройки камеры и рендера

Config {
	Settings camera pos:[...] focus:[...]
	Settings render backgroundColor:[...] samplesPerIteration:5
}

Materials {
	Material ...
	...
}

Scene {
	Surface ...
	...
}

2. Вывод изображения в окно

Завести счётчик семплов

onRender {
	// вызываем render
	// обшее количество семплов увеличиваем на renderer->getSamples();
	// выводим в окно
	x,y
	Vec3<float> color;
	
	unsigned char * pixel = static_cast<unsigned char *>(surfDisplay->pixels) + y * surfDisplay->pitch + x * surfDisplay->format->BytesPerPixel;
	*pixel++ = static_cast<unsigned char>(color.x);
	*pixel++ = static_cast<unsigned char>(color.y);
	*pixel++ = static_cast<unsigned char>(color.z);

}

У MonteCarloImage надо завести методы getWidth и getHeight
