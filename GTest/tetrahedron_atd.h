#pragma once

#include "shape_type.h"
#include "shape_atd.h"


namespace shapes {
	class tetrahedron : public shape {
	
	public:
		int side;
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����

		double Volume();

		tetrahedron() {} // �������� ��� �������������.
	};
}