#include "sphere_atd.h"




namespace shapes {
	void sphere::InData(ifstream &ifst) {
		ifst >> rad;
	}


	void sphere::Out(ofstream &ofst) {
		ofst << "It is sphere: radius = " << rad;
	}

	double sphere::Volume() {
		return rad * rad * rad * 3.1415 * 4 / 3;
	}
}