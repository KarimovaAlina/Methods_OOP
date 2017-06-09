#pragma once

#include "shape_type.h"
#include "shape_atd.h"


namespace shapes {
	class sphere : public shape {
		
	public:
		int rad;
		// �������������� ��������� ������
		void InData(ifstream &ifst); // ����
		void Out(ofstream &ofst); // �����

		double Volume();

		void OutSphere(ofstream &ofst);

		sphere() {} // �������� ��� �������������.
	};
}