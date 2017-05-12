#include <fstream>
#include "shape_type.h"
#include "list.h"
#include "shape_atd.h"
using namespace std;

namespace shapes {
	class container {
		
	public:
		int n; // текущая длина
		list *cont;
		void In(ifstream &ifst); // ввод фигур
		void Out(ofstream &ofst); // вывод фигур
		void ClearContainer(); // очистка контейнера от фигур

		void Volume(ofstream &ofst);
		void Sort();
		
		virtual void OutSphere(ofstream &ofst);
		container() { n = 0; cont = NULL; }  // инициализация контейнера
		~container() { ClearContainer(); } // утилизация контейнера
	};
}