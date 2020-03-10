#include "line.h"
using namespace std;

vector < line > coor_4_line; //每条线的坐标
map<string, int> intersection; //所有交点
vector < vector<double> > new_inter;
int N;
int p_cnt = 0;

void line::store_coor(string str)
{	
	vector<string> res;//用于存放分割后的字符串 
	string result;//暂存从str中读取的字符串 
	stringstream input(str);//将字符串读到input中 
	while (input >> result)
		res.push_back(result);//依次输出到result中，并存入res中 

	x1 = stoi(res[1], 0, 10);
	y1 = stoi(res[2], 0, 10);
	x2 = stoi(res[3], 0, 10);
	y2 = stoi(res[4], 0, 10);;
	x2_x1 = stoi(res[3], 0, 10) - stoi(res[1], 0, 10);
	y2_y1 = stoi(res[4], 0, 10) - stoi(res[2], 0, 10);
	if (x2_x1 == 0)
	{
		ulimited = true;
	}
	else
	{
		k = y2_y1 / x2_x1;
	}
}

void cnt_coor_num()
{
	int i, j;
	for (i = 0;i < N;i++)
		for (j = i + 1;j < N;j++)
		{
			if (coor_4_line[i].ulimited == true || coor_4_line[j].ulimited == true)
			{
				if (coor_4_line[i].ulimited != coor_4_line[j].ulimited)
				{
					calcu_coor(i, j);
				}
			}
			else
			{
				if (coor_4_line[i].k != coor_4_line[j].k)
				{
					calcu_coor(i, j);
				}
			}
		}
}

void calcu_coor(int i, int j)
{
	string coor;
	double x, y, xa;
	int ya,yb,xb;
	xa = 0;
	ya = ((-coor_4_line[i].y2_y1) * (coor_4_line[j].y2_y1) * coor_4_line[i].x1 +
		(coor_4_line[j].y2_y1) * (coor_4_line[i].x2_x1) * coor_4_line[i].y1 +
		(coor_4_line[i].y2_y1) * (coor_4_line[j].y2_y1) * coor_4_line[j].x1 +
		(-coor_4_line[j].x2_x1) * (coor_4_line[i].y2_y1) * coor_4_line[j].y1);
	yb = coor_4_line[i].x2_x1 * coor_4_line[j].y2_y1 + (-coor_4_line[i].y2_y1) * coor_4_line[j].x2_x1;
	if (ya == 0)
	{
		if (yb == 0) y = 1;
		else y = 0;
	}
	else y = ya / yb;
	int m = j;
	if (coor_4_line[j].k == 0) {
		m = i;
	}
	xb = -coor_4_line[m].y2_y1;
	if (xb == 0)
	{
		if (coor_4_line[m].x2_x1 == 0) xa = y - coor_4_line[m].y2;
		else if ((y - coor_4_line[m].y2) == 0) xa = -coor_4_line[m].x2_x1;
	}
	else xa = -coor_4_line[m].x2_x1 * (y - coor_4_line[m].y2) / xb;
	x = coor_4_line[m].x2 + xa;

	coor = to_string(x) + to_string(y); //shit
	intersection.insert(pair<string, int>(coor, 0));
	//duplicate_remove(x, y);
}

void duplicate_remove(double x,double y)
{
	vector<double> tmp;
	int flag = 0;
	tmp.push_back(x);
	tmp.push_back(y);
	vector<vector<double>>::iterator it = find(new_inter.begin(), new_inter.end(), tmp);

	if (it != new_inter.end())
		flag = 1;

	if (flag == 0)
	{
		new_inter.push_back(tmp);
		//cout << "sss" << endl;
	}
}

int main()
{
	//test();
	int i = 0;
	cin >> N;
	cin.get();//用于吃掉回车
	while (i < N)
	{
		string str;
		line coor;
		getline(cin, str);
		coor.store_coor(str);
		coor_4_line.push_back(coor);
		i++;
	}
	if (N > 1)
	{
		cnt_coor_num();
		p_cnt = intersection.size();
		//p_cnt = new_inter.size();
	}
	cout << p_cnt << endl;
	return 0;
}