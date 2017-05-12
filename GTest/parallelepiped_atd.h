#pragma once

#include "shape_type.h"
#include "shape_atd.h"



namespace shapes {
	class parallelepiped : public shape {
		
	public:
		int e1, e2, e3;
		// переопределяем интерфейс класса
		void InData(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод
		double Volume();
		parallelepiped() {} // создание без инициализации.
	};
}