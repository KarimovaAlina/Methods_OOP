#include "Secure.h"
#include "parallelepiped_atd.h"
#include <fstream>

using namespace std;

namespace shapes 
{
	void parallelepiped::InData(ifstream &ifst)
	{
		ChckInFile(ifst);
		ifst >> e1;
		ChckInValue(ifst);
		ChckNegative(e1);
		ifst >> e2;
		ChckInValue(ifst);
		ChckNegative(e2);
		ifst >> e3;
		ChckInValue(ifst);
		ChckNegative(e3);
		shape::InData(ifst);
	}


	void parallelepiped::Out(ofstream &ofst) 
	{
		ChckOutFile(ofst);
		ofst << "It is parallelepiped:  a = " << e1 << ", b = " << e2 << ", c = " << e3;
		shape::Out(ofst);
	}

	double parallelepiped::Volume()
	{
		return e1 * e2 * e3;
	}

	void parallelepiped::MultiMethod(shape *other, ofstream &file)
	{
		other->MultiMethodCaseParallelepiped(file);
	}

	void parallelepiped::MultiMethodCaseSphere(ofstream &file)
	{
		file << "Sphere and Parallelepiped" << endl;
	}

	void parallelepiped::MultiMethodCaseParallelepiped(ofstream &file)
	{
		file << "Parallelepiped and Parallelepiped" << endl;
	}

	void parallelepiped::MultiMethodCaseTetrahedron(ofstream &file)
	{
		file << "Tetrahedron and Parallelepiped" << endl;
	}
}