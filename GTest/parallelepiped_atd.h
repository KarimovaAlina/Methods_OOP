#pragma once

#include "shape_type.h"
#include "shape_atd.h"



namespace shapes {
	class parallelepiped : public shape {
		
	public:
		int e1, e2, e3;
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����
		double Volume();
		parallelepiped() {} // �������� ��� �������������.
	};
}