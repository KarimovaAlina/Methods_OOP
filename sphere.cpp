#include "sphere_atd.h"




namespace shapes {
	void sphere::InData(ifstream &ifst) {
		ifst >> rad;
		shape::InData(ifst);
	}


	void sphere::Out(ofstream &ofst) {
		ofst << "It is sphere: radius = " << rad;
		shape::Out(ofst);
	}
}