#pragma once

#include "shape_type.h"
#include "shape_atd.h"


namespace shapes {
	class sphere : public shape {
		int rad;
	public:
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����
		double Volume();
		sphere() {} // �������� ��� �������������.
	};
}