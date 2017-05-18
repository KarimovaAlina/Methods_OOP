#include "parallelepiped_atd.h"


namespace shapes {
	void parallelepiped::InData(ifstream &ifst) {
		ifst >> e1 >> e2 >> e3;
	}


	void parallelepiped::Out(ofstream &ofst) {
		ofst << "It is parallelepiped:  a = " << e1 << ", b = " << e2 << ", c = " << e3;
	}

	void parallelepiped::MultiMethod(shape *other, ofstream &f)
	{
		other->MultiMethodCaseParallelepiped(f);
	}

	void parallelepiped::MultiMethodCaseSphere(ofstream &f)
	{
		f << "Sphere and Parallelepiped" << endl;
	}
	void parallelepiped::MultiMethodCaseParallelepiped(ofstream &f)
	{
		f << "Parallelepiped and Parallelepiped" << endl;
	}
}