#include "main.h"

using namespace shapes;


int main(int argc, char* argv[]) 
{
	if (argc != 3)
	{
		cout << "incorrect command line!"	<< endl;
		return 0;
	}
	ifstream ifst(argv[1]);
	ChckInFile(ifst);
	ifst.seekg(0, std::ios::end);
	int fileSize = ifst.tellg();
	ifst.seekg(0, std::ios::beg);
	if (fileSize == 0)
	{
		cout << "Error. Input file is empty." << endl;
		system("pause");
		return 0;
	}

	ofstream ofst(argv[2]);
	ChckOutFile(ofst);
	cout << "Start" << endl;
	container c;
	c.ClearContainer();

	c.In(ifst);
	ofst << "Filled container. " << endl;

	//c.Out(ofst);
	c.Sort(1);
	c.Volume(ofst);

	c.OutSphere(ofst);
	ofst << endl;
	c.MultiMethod(ofst);
	c.ClearContainer();
	ofst << "Empty container. " << endl;
	c.Out(ofst);
	cout << "Stop" << endl;
	return 0;
}