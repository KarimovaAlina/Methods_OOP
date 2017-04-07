#pragma once

#include <fstream>
#include "shape_type.h"
using namespace std;


namespace shapes {
	class shape {
		int temp;
	public:
		type t;
		double destiny;

		

		static shape* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0; // ввод
		virtual void Out(ofstream &ofst) = 0; // вывод
	protected:
		shape() {};
	};
}
