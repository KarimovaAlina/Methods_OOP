#pragma once
#include "shape_atd.h"
#include "shape_type.h"

namespace shapes {
	struct list {
		shape* sh;
		list* next;
	};
}

