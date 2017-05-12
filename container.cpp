#include "Secure.h"
#include "container_atd.h"
#include "list.h"


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
			ofst << ", Destiny = " << cur->sh->destiny << ", Volume = " << cur->sh->Volume() << "." << endl;
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


	void container::Sort() 
	{

		for (int i = 0; i < n - 1; i++) 
		{
			list* cur = cont;
			for (int j = i + 1; j < n; j++) 
			{
				if (cur->sh->Compare(*(cur->next->sh))) 
				{
					shape *tmp = cur->sh;
					cur->sh = cur->next->sh;
					cur->next->sh = tmp;
				}
				cur = cur->next;
			}
		}
		
	}
	
	

}