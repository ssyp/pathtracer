----

1. ����� ��-���� �������� ����� ����������� � �������
2. �����, ����� ��������� ��� �� �������� ����������� � ������������, �� ������� �� �������

������ ��������� �� ISurface � ����

----

1. �������� � ������ ��������� ������ � �������

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

2. ����� ����������� � ����

������� ������� �������

onRender {
	// �������� render
	// ����� ���������� ������� ����������� �� renderer->getSamples();
	// ������� � ����
	x,y
	Vec3<float> color;
	
	unsigned char * pixel = static_cast<unsigned char *>(surfDisplay->pixels) + y * surfDisplay->pitch + x * surfDisplay->format->BytesPerPixel;
	*pixel++ = static_cast<unsigned char>(color.x);
	*pixel++ = static_cast<unsigned char>(color.y);
	*pixel++ = static_cast<unsigned char>(color.z);

}

� MonteCarloImage ���� ������� ������ getWidth � getHeight
