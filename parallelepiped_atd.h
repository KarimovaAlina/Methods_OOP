#pragma once

#include "shape_type.h"
#include "shape_atd.h"



namespace shapes 
{
	class parallelepiped : public shape 
	{
		int e1, e2, e3;
	public:
		// переопределяем интерфейс класса
		void InData(ifstream &ifst); // ввод
		void Out(ofstream &ofst); // вывод
		double Volume();
		parallelepiped() {} // создание без инициализации.
		void MultiMethod(shape *other, ofstream &file);
		void MultiMethodCaseSphere(ofstream &file);
		void MultiMethodCaseParallelepiped(ofstream &file);
		void MultiMethodCaseTetrahedron(ofstream &file);
	};
}