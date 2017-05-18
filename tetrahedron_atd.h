#pragma once

#include "shape_type.h"
#include "shape_atd.h"


namespace shapes 
{
	class tetrahedron : public shape 
	{
		int side;
	public:
		// переопределяем интерфейс класса
		void InData(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод

		double Volume();

		void MultiMethod(shape *other, ofstream &file);
		void MultiMethodCaseSphere(ofstream &file);
		void MultiMethodCaseParallelepiped(ofstream &file);
		void MultiMethodCaseTetrahedron(ofstream &file);

		tetrahedron() {} // создание без инициализации.
	};
}