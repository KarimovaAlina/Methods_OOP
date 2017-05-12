#include"Secure.h"
#include "tetrahedron_atd.h"

namespace shapes 
{
	void tetrahedron::InData(ifstream &ifst) 
	{
		ChckInFile(ifst);
		ifst >> side;
		ChckInValue(ifst);
		ChckNegative(side);
		shape::InData(ifst);
	}


	void tetrahedron::Out(ofstream &ofst) 
	{
		ChckOutFile(ofst);
		ofst << "It is tetrahedron: side = " << side;
		shape::Out(ofst);
	}

	double tetrahedron::Volume() 
	{
		return (side * side * side * sqrt((double)2)  / 12);
	}
}