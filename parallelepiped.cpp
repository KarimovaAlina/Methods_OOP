#include "parallelepiped_atd.h"


namespace shapes {
	void parallelepiped::InData(ifstream &ifst) {
		ifst >> e1 >> e2 >> e3;
	}


	void parallelepiped::Out(ofstream &ofst) {
		ofst << "It is parallelepiped:  a = " << e1 << ", b = " << e2 << ", c = " << e3;
	}

	double parallelepiped::Volume() {
		return e1 * e2 * e3;
	}
}