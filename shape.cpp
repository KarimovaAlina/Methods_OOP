#include "Secure.h"
#include "sphere_atd.h"
#include "parallelepiped_atd.h"
#include "tetrahedron_atd.h"
#include "shape_atd.h"





namespace shapes {
	shape* shape::In(ifstream &ifst) {
		ChckInFile(ifst);
		if (ifst.eof())
		{
			cout << "Error. Too many shapes is specified." << endl;
			system("pause");
			exit(1);
		}
		shape *sh;
		int type;
		ifst >> type;
		ChckInValue(ifst);
		ChckNegative(type);
		switch (type)
		{
		case 0:
			sh = new sphere;
			break;
		case 1:
			sh = new parallelepiped;
			break;
		case 2:
			sh = new tetrahedron;
			break;
		default:
			return NULL;
			break;
		}
		
		sh->InData(ifst);
		
		ifst >> sh->destiny;
		ChckInValue(ifst);
		ChckNegative(sh->destiny);
		return sh;
	}


	void shape::InData(ifstream &ifst) {
		ifst >> temp;
		ChckInValue(ifst);
		ChckNegative(temp);

	}

	void shape::Out(ofstream &ofst) {
		ChckOutFile(ofst);
		ofst << ", Melting temperature = " << temp;
	}



	void shape::OutSphere(ofstream &ofst) {
		
	}

	
	bool shape::Compare(shape &other) {
		return Volume() < other.Volume();
	}
}