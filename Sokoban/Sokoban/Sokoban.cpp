#include "pch.h"
#include <iostream>
#include "Field.h"
#include "Cell.h"

using namespace std;

int main()
{
	Worker Sam(1, 1);
	Box box_1(2, 2), box_2(3, 3), box_3(5, 5);
	FinPlace finish_1(7, 7), finish_2(7, 6), finish_3(7, 5);
	Border bord_1(4, 4), bord_2(4, 5), bord_3(4, 6), bord_4(4, 7), bord_5(5, 7);
	Field level_1;
	level_1.addCell(&Sam);
	level_1.addCell(&box_1);
	level_1.addCell(&box_2);
	level_1.addCell(&box_3);
	level_1.addCell(&finish_1);
	level_1.addCell(&finish_2);
	level_1.addCell(&finish_3);
	level_1.addCell(&bord_1);
	level_1.addCell(&bord_2);
	level_1.addCell(&bord_3);
	level_1.addCell(&bord_4);
	level_1.addCell(&bord_5);

}
