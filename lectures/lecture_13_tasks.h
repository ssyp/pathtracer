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

���� ���:		color = color * (surf->getMaterial())->getBRDF(ray.direction, newRay.direction, normal);
				color = color * pathTrace(newRay, scene, color);
				
�������� ��:	IMaterial * material = surf->getMaterial();
				color = material->getColor(color) * dot(n,���������� ����) * pathTrace(newRay, scene, color);
