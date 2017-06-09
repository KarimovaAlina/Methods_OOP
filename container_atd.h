#include <fstream>
#include "shape_type.h"
#include "list.h"
#include "shape_atd.h"
using namespace std;

namespace shapes 
{
	class container 
	{
		int n; // текущая длина
		list *cont;
	public:
		void In(ifstream &ifst); // ввод фигур
		void Out(ofstream &ofst); // вывод фигур
		void ClearContainer(); // очистка контейнера от фигур

		void Volume(ofstream &ofst);
		void Sort(bool napr);

		void MultiMethod(ofstream &file);
		
		virtual void OutSphere(ofstream &ofst);
		container() { n = 0; cont = NULL; }  // инициализация контейнера
		~container() { ClearContainer(); } // утилизация контейнера
	};
}