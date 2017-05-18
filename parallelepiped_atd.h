#pragma once

#include "shape_type.h"
#include "shape_atd.h"



namespace shapes {
	class parallelepiped : public shape {
		int e1, e2, e3;
	public:
		// переопределяем интерфейс класса
		void InData(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод
		void MultiMethod(shape *other, ofstream &f);
		void MultiMethodCaseSphere(ofstream &f);
		void MultiMethodCaseParallelepiped(ofstream &f);
		parallelepiped() {} // создание без инициализации.
	};
}