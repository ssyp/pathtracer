0 <= curX <= 640
0 <= curY <= 480

realSizeX
realSizeY

Camera

* ����������� ��������� ������� � ������� ����� ��� ��������
* ���������� ������� ������������ ����

SimpleMaterial

* ��������� ���������: reflectance (����), emittance (����)
* virtual Vec3<float> getColor(const Vec3<float> & color) = 0; // return emittance + getBRDF() * reflectance * color;
* Init

Factory

* Init ����������

Renderer

Vec3<float> pathTrace(Scene, Ray, Depth) {
	
	��������� ����������� � ���-����
	
	���� ����������� ���, �� ������� ���� ����
	���� ������� ���� ������ ����������, ������� ������ ����
	
	��������� ��������� ��� ������� interact � IMaterial
	��������� BDRF ������� getBDRF � IMaterial
	��������� cosOmega = dot(n, newRay.direction);
	
	��������� ���� ���������� ����, ������� pathTrace
	
	��������� ���� ��������� �� ������� getColor(BRDF * cosOmega * ���� ���������� ����)
}

