#include "Secure.h"
#include "sphere_atd.h"


namespace shapes
{
	void sphere::InData(ifstream &ifst) 
	{
		ChckInFile(ifst);
		ifst >> rad;
		ChckInValue(ifst);
		ChckNegative(rad);
		shape::InData(ifst);
	}


	void sphere::Out(ofstream &ofst) 
	{
		ChckOutFile(ofst);
		ofst << "It is sphere: radius = " << rad;
		shape::Out(ofst);
	}

	double sphere::Volume() 
	{
		return rad * rad * rad * 3.1415 * 4 / 3;
	}

	void sphere::OutSphere(ofstream &ofst) 
	{
		ChckOutFile(ofst);
		Out(ofst);
		ofst << ", Destiny = " << destiny << "." << endl;
	}
}