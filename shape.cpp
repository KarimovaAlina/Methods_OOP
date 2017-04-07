#include "sphere_atd.h"
#include "parallelepiped_atd.h"
#include "tetrahedron_atd.h"
#include "shape_atd.h"





namespace shapes {
	shape* shape::In(ifstream &ifst) {
		shape *sh;

		int type;
		ifst >> type;
		switch (type)
		{
		case 0:
			sh = new sphere;
			break;
		case 1:
			sh = new parallelepiped;
			break;
		case 2:
			sh = new tetrahedron;
			break;
		default:
			return NULL;
			break;
		}
		
		sh->InData(ifst);
		ifst >> sh->destiny;
		return sh;
	}
	
}