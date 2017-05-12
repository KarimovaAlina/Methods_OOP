#include "tetrahedron_atd.h"

namespace shapes {
	void tetrahedron::InData(ifstream &ifst) {
		ifst >> side;
		shape::InData(ifst);
	}


	void tetrahedron::Out(ofstream &ofst) {
		ofst << "It is tetrahedron: side = " << side;
		shape::Out(ofst);
	}

	double tetrahedron::Volume() {
		return (side * side * side * sqrt((double)2)  / 12);
	}
}