#include "container_atd.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace shapes;


void main(int argc, char* argv[]) {
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container c;
	c.ClearContainer();

	c.In(ifst);
	ofst << "Filled container. " << endl;
	c.Out(ofst);
	c.MultiMethod(ofst);
	c.ClearContainer();
	ofst << "Empty container. " << endl;
	c.Out(ofst);
	cout << "Stop" << endl;
}