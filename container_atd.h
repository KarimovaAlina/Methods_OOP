#include <fstream>
#include "shape_type.h"
#include "list.h"
#include "shape_atd.h"
using namespace std;

namespace shapes 
{
	class container 
	{
		int n; // ������� �����
		list *cont;
	public:
		void In(ifstream &ifst); // ���� �����
		void Out(ofstream &ofst); // ����� �����
		void ClearContainer(); // ������� ���������� �� �����

		void Volume(ofstream &ofst);
		void Sort(bool napr);

		void MultiMethod(ofstream &file);
		
		virtual void OutSphere(ofstream &ofst);
		container() { n = 0; cont = NULL; }  // ������������� ����������
		~container() { ClearContainer(); } // ���������� ����������
	};
}