#include "tetrahedron_atd.h"

namespace shapes {
	void tetrahedron::InData(ifstream &ifst) {
		ifst >> side;
	}


	void tetrahedron::Out(ofstream &ofst) {
		ofst << "It is tetrahedron: side = " << side;
	}
}