#include "parallelepiped_atd.h"


namespace shapes {
	void parallelepiped::InData(ifstream &ifst) {
		ifst >> e1 >> e2 >> e3;
		shape::InData(ifst);
	}


	void parallelepiped::Out(ofstream &ofst) {
		ofst << "It is parallelepiped:  a = " << e1 << ", b = " << e2 << ", c = " << e3;
		shape::Out(ofst);
	}

	double parallelepiped::Volume() {
		return e1 * e2 * e3;
	}
}