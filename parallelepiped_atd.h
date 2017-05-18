#pragma once

#include "shape_type.h"
#include "shape_atd.h"



namespace shapes 
{
	class parallelepiped : public shape 
	{
		int e1, e2, e3;
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����
		double Volume();
		parallelepiped() {} // �������� ��� �������������.
		void MultiMethod(shape *other, ofstream &file);
		void MultiMethodCaseSphere(ofstream &file);
		void MultiMethodCaseParallelepiped(ofstream &file);
		void MultiMethodCaseTetrahedron(ofstream &file);
	};
}