#include "container_atd.h"
#include "list.h"


namespace shapes {
	void container::Out(ofstream &ofst) {
		ofst << "Container contains " << n << " elements." << endl;
		list* cur = cont;
		int s = 0;
		while (cur != NULL && s < n)
		{
			ofst << s + 1 << " :  ";
			cur->sh->Out(ofst);
			ofst << ", Destiny = " << cur->sh->destiny << "." << endl;
			cur = cur->next;
			++s;
		}
	}

	void container::In(ifstream &ifst) {
		list* cur = cont;
		if (cont == NULL)
		{
			cont = new list;
			cur = cont;
		}
		else
		{
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = new list;
			cur = cur->next;
		}
		list* prev = cur;
		while(!ifst.eof()) {
			if ((cur->sh = shape::In(ifst)) != 0)
			{
				++n;
				prev = cur;
				cur->next = new list;
				cur = cur->next;
			}
		}
		prev->next = NULL;
	}

	void container::ClearContainer() {
		list* a;
		while (cont != NULL && n > 0)
		{
			a = cont->next;
			delete cont;
			cont = a;
			--n;
		}
		n = 0;
		cont = NULL;
	}

	void container::MultiMethod(ofstream &f)
	{
		f << endl << "Multimethod:" << endl;
		list *temp1 = cont;
		list *temp2 = cont->next;
		while (temp1->next != NULL)
		{
			temp2 = temp1->next;
			while (temp2->next != NULL)
			{
				temp1->sh->MultiMethod(temp2->sh, f);
				temp1->sh->Out(f);
				f << endl;
				temp2->sh->Out(f);
				f << endl << endl;
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
	}
}