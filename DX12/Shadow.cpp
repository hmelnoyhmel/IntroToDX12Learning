#include "Shadow.h"

using namespace DirectX;

void Shadow::Update()
{
	Renderer::Update();

	//����� ������ � ��������� ����� � �� ��. + ��������� ������� ��� Plane ����� �� ���� "�����" ���������
	Matrix shadow = Matrix::CreateShadow(mainLight->Direction() * -1, shadowPlane) * Matrix::CreateTranslation(
		0.0f, 0.001f, 0.0f);

	gameObject->GetTransform()->SetWorldMatrix(targetTransform->GetWorldMatrix() * shadow);	
}

Shadow::Shadow(Transform* targetTr, Light* light): targetTransform(targetTr), mainLight(light)
{
}
