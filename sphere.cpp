#include "sphere_atd.h"




namespace shapes {
	void sphere::InData(ifstream &ifst) {
		ifst >> rad;
	}


	void sphere::Out(ofstream &ofst) {
		ofst << "It is sphere: radius = " << rad;
	}

	void sphere::OutSphere(ofstream &ofst) {
		Out(ofst);
		ofst << ", Destiny = " << destiny << "." << endl;
	}
}