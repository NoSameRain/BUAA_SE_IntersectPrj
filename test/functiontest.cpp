#include "line.h"
#include <ctime>
using namespace std;

#define random(a, b) (rand() % (b - a + 1)) + a

int get_random() {
	return random(-9999, 9999);
}

void test()
{
	int i = 0;
	N = 1000;
	while (i < N)
	{
		string space = " ";
		string str = "L" + space + to_string(get_random()) + space + to_string(get_random()) + space
			+ to_string(get_random()) + space + to_string(get_random());
		line coor;
		coor.store_coor(str);
		coor_4_line.push_back(coor);
		i++;
	}

	cnt_coor_num();
	p_cnt = intersection.size();
	cout << p_cnt << endl;
}