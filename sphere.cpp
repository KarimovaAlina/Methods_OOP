#include "sphere_atd.h"




namespace shapes {
	void sphere::InData(ifstream &ifst) {
		ifst >> rad;
	}


	void sphere::Out(ofstream &ofst) {
		ofst << "It is sphere: radius = " << rad;
	}

	void sphere::MultiMethod(shape *other, ofstream &f)
	{
		other->MultiMethodCaseSphere(f);
	}

	void sphere::MultiMethodCaseSphere(ofstream &f)
	{
		f << "Sphere and Sphere" << endl;
	}
	void sphere::MultiMethodCaseParallelepiped(ofstream &f)
	{
		f << "Parallelepiped and Sphere" << endl;
	}
}