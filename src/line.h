#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<sstream>
using namespace std;
class line
{
public:
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	int x2_x1 = 0; //x2 - x1
	int y2_y1 = 0; //y2 - y1
	double k = 0;
	bool ulimited = false; //��б��;

	void store_coor(string str);
};
extern map<string, int> intersection; //���н���
extern vector < line > coor_4_line; //ÿ���ߵ�����
extern vector < vector<double> > new_inter;
extern int p_cnt,N;
void cnt_coor_num(); //���㽻�����
void calcu_coor(int i, int j);
void test();
void duplicate_remove(double x, double y);
int get_random();