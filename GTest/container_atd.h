#include <fstream>
#include "shape_type.h"
#include "list.h"
#include "shape_atd.h"
using namespace std;

namespace shapes {
	class container {
		
	public:
		int n; // ������� �����
		list *cont;
		void In(ifstream &ifst); // ���� �����
		void Out(ofstream &ofst); // ����� �����
		void ClearContainer(); // ������� ���������� �� �����

		void Volume(ofstream &ofst);
		void Sort();
		
		virtual void OutSphere(ofstream &ofst);
		container() { n = 0; cont = NULL; }  // ������������� ����������
		~container() { ClearContainer(); } // ���������� ����������
	};
}