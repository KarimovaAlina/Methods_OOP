#pragma once

#include "shape_type.h"
#include "shape_atd.h"


namespace shapes {
	class tetrahedron : public shape {
	
	public:
		int side;
		// переопределяем интерфейс класса
		void InData(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод

		double Volume();

		tetrahedron() {} // создание без инициализации.
	};
}