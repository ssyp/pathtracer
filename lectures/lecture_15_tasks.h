TODO:

1. Правильный вектор up у камеры (z вверх)
2. MonteCarloImage::save(), Camera::Camera() правильная конверсия int / int во float
3. MathUtils, метод getRandomPointOnHemisphere, везде делить на RAND_MAX и правильно кастовать во float
4. У класса Scene::getIntersection возвращать -1, если ничего не было найдено
5. У класса Renderer::pathTrace, если вернули -1, то возвращать цвет фона

6. Растяжения картинки
7. Почему возникает серая полоска?