#include "sphere_atd.h"
#include "parallelepiped_atd.h"
#include "tetrahedron_atd.h"
#include "shape_atd.h"





namespace shapes {
	shape* shape::In(ifstream &ifst) {
		shape *sh;

		int type;
		ifst >> type;
		
		switch (type)
		{
		case 0:
			sh = new sphere;
			sh->t = SPHERE;
			break;
		case 1:
			sh = new parallelepiped;
			sh->t = PARALLELEPIPED;
			break;
		case 2:
			sh = new tetrahedron;
			sh->t = TETRAHEDRON;
			break;
		default:
			return NULL;
			break;
		}
		
		sh->InData(ifst);
		
		ifst >> sh->destiny;
		return sh;
	}


	void shape::InData(ifstream &ifst) {
		ifst >> temp;
	}

	void shape::Out(ofstream &ofst) {
		ofst << ", Melting temperature = " << temp;
	}



	void shape::OutSphere(ofstream &ofst) {
		
	}

	
	bool shape::Compare(shape &other) {
		return Volume() < other.Volume();
	}
}