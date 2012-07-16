// TODO:

Generic:
1. No warnings
2. Return values

Codestyle:
1. �� ���������� ������������� � � private
2. ��� ���������� get/set �����, set ����

Renderer:
1. �������� ��� �� ������ � ������ � �����������, ������� ������� ����� ���� � ����� ������
3. ����� ����������
4. ���������� � MonteCarloImage
5. � MonteCarloImage ������� ����� save

Math:
1. operator * (vec, vec)
2. 	bool f_eq(float v1, float v2) {
		// ������� true, ���� ������ �������� ���� ����� ����� ���������
	}
3. �������������� ��������� (infinity (100000000.0f), epsilon (0.001f)), ��������� .h ���� ��� f_eq � ��� ��������
4. ��������� namespace (Math) ��� ����������
// 5. ��������� ���������� ���������� ������� �� ��������� �� �������
// 6. ��������� ���������� ���������� �������, �������� � ���������

Parser:
1. ������� ������ ����������� �� ��������� surface'�� (��� ���������� ������ surface'� ��� ������� �� ������ ��������������)

Scene:
1. � Sphere �� ������������� dot
2. �������� �� D > 0 �� �����
3. ������� Mesh
 * �������� ���� 	
4. ������� ��� ���� �������� IMaterial, ������� �� ���� ��������� SimpleMaterial;

IMaterial {
	virtual float getBRDF(Vec3 in, Vec3 out, Vec3 n) = 0;
	virtual Vec3 interact(Vec3 in, Vec3 ip, Vec3 n) = 0;
};

SimpleMaterial : public IMaterial {
	 getBRDF == 1
	 // interact == ��������� ��� �� ��������� �� �������
};

----
SDL
