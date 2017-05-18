#pragma once

#include <fstream>
#include "shape_type.h"
using namespace std;


namespace shapes 
{
	class shape
	{
		int temp;
	public:
		type t;
		double destiny;

		static shape* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0; // ����
		virtual void Out(ofstream &ofst) = 0; // �����

		virtual double Volume() = 0;
		bool Compare(shape &other);

		virtual void OutSphere(ofstream &ofst);

		virtual void MultiMethod(shape *other, ofstream &f) = 0;
		virtual void MultiMethodCaseSphere(ofstream &f) = 0;
		virtual void MultiMethodCaseParallelepiped(ofstream &f) = 0;
		virtual void MultiMethodCaseTetrahedron(ofstream &f) = 0;
	protected:
		shape() {};
	};
}
