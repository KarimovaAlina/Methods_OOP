#pragma once

#include <fstream>
#include "shape_type.h"
using namespace std;


namespace shapes {
	class shape {
	public:
		type t;
		double destiny;

		static shape* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0; // ����
		virtual void Out(ofstream &ofst) = 0; // �����
		virtual void OutSphere(ofstream &ofst);
	protected:
		shape() {};
	};
}
