#include "Main.h"


namespace shapes 
{
	void container::Out(ofstream &ofst) 
	{
		ChckOutFile(ofst);
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

	void container::In(ifstream &ifst) 
	{
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
		while(!ifst.eof()) 
		{
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

	void container::ClearContainer() 
	{
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


	void container::Volume(ofstream &ofst) 
	{
		ChckOutFile(ofst);
		ofst << "Container contents " << n
			<< " elements." << endl;
		list* cur = cont;
		int s = 0;
		while (cur != NULL && s < n)
		{
			ofst << s + 1 << " :  ";
			cur->sh->Out(ofst);
			
			cur = cur->next;
			++s;
		}
	}

	void container::OutSphere(ofstream &ofst) 
	{
		ChckOutFile(ofst);
		ofst << "Only spheres." << endl;
		list* cur = cont;
		int s = 0;
		while (cur != NULL && s < n)
		{
			
			cur->sh->OutSphere(ofst);
			
			cur = cur->next;
			++s;
		}
	}


	void container::Sort(bool napr) 
	{

		for (int i = 0; i < n - 1; i++) 
		{
			list* cur = cont;
			for (int j = i + 1; j < n; j++) 
			{
				if (cur->sh->Compare(*(cur->next->sh), napr)) 
				{
					shape *tmp = cur->sh;
					cur->sh = cur->next->sh;
					cur->next->sh = tmp;
				}
				cur = cur->next;
			}
		}
		
	}
	
	void container::MultiMethod(ofstream &file)
	{
		file << "Multimethod:" << endl;
		list *temp1 = cont;
		list *temp2 = cont->next;
		while (temp1->next != NULL)
		{
			temp2 = cont->next;
			while (temp2 != NULL)
			{
				temp1->sh->MultiMethod(temp2->sh, file);
				temp1->sh->Out(file);
				file << ", V = " << temp1->sh->Volume() << endl;
				temp2->sh->Out(file);
				file << ", V = " << temp2->sh->Volume() << endl << endl;
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
	}

}