#include "pch.h"
#include "CppUnitTest.h"
#include "../intersect/line.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(IntersectTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)//边界条件-1
		{
			int i = 0;
			string s[2];
			s[0]= "L 9999 9999 -9999 -9999";
			s[1]= "L 9999 0 9999 9999";
			while (i < 2)
			{
				line coor;
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt, (int)1);
		}
		TEST_METHOD(TestMethod2)//部分为平行线-2
		{
			int i = 0;
			string s[3];
			s[0] = "L 0 0 0 1";
			s[1] = "L 1 0 1 1";
			s[2] = "L 0 2 2 2";
			while (i < 3)
			{
				line coor;
				//getline(cin, str);
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt,(int)2);
		}
		TEST_METHOD(TestMethod3)//相交-5
		{
			int i = 0;
			string s[4];
			s[0] = "L 500 500 0 0";
			s[1] = "L 500 0 -100 0";
			s[2] = "L 999 0 999 -999";
			s[3] = "L 0 250 999 250";
			while (i < 4)
			{
				line coor;
				//getline(cin, str);
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt, (int)5);
		}
		TEST_METHOD(TestMethod4)//全为平行线-0
		{
			int i = 0;
			string s[4];
			s[0] = "L 0 0 0 100";
			s[1] = "L 100 0 100 1000";
			s[2] = "L 1000 0 1000 1000";
			s[3] = "L -1000 0 -1000 -1000";
			while (i < 4)
			{
				line coor;
				//getline(cin, str);
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt, (int)0);
		}
		TEST_METHOD(TestMethod5)//部分点相交于同一点-4
		{
			int i = 0;
			string s[4];
			s[0] = "L 0 0 1 1";
			s[1] = "L 0 0 0 1";
			s[2] = "L 0 0 -1 0";
			s[3] = "L -1000 0 0 -1000";
			while (i < 4)
			{
				line coor;
				//getline(cin, str);
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt, (int)4);
		}
		TEST_METHOD(TestMethod6)//边界条件-5
		{
			int i = 0;
			string s[5];
			s[0] = "L 9999 9999 -9999 -9999";
			s[1] = "L 9999 0 9999 9999";
			s[2] = "L 9999 -9999 -9999 9999";
			s[3] = "L -9999 0 -9999 9999";
			s[4] = "L 0 0 0 9999";
			while (i < 5)
			{
				line coor;
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt, (int)5);
		}
		TEST_METHOD(TestMethod7)//所有点相较于同一点-1
		{
			int i = 0;
			string s[10];
			s[0] = "L 0 9999 0 0";
			s[1] = "L 9999 0 9999 0";
			s[2] = "L 9999 -9999 -9999 9999";
			s[3] = "L -9378 0 4925 0";
			s[4] = "L -9999 -9999 9999 9999";
			s[5] = "L -9378 -9378 1221 1221";
			s[6] = "L -9999 2345 9999 -2345";
			s[7] = "L 0 9999 0 0";
			s[8] = "L 0 9999 0 0";
			s[9] = "L 0 9999 0 0";
			while (i < 10)
			{
				line coor;
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt, (int)1);
		}
		TEST_METHOD(TestMethod8)//部分平行 部分相较于同一点 -12
		{
			int i = 0;
			string s[15];
			s[0] = "L 0 9999 0 0";
			s[1] = "L 9999 0 9999 0";
			s[2] = "L 9999 -9999 -9999 9999";
			s[3] = "L -9378 0 4925 0";
			s[4] = "L -9999 -9999 9999 9999";
			s[5] = "L 0 5 5 5";
			s[6] = "L 0 1000 1000 1000";
			s[7] = "L 0 -9999 -9999 -9999";
			s[8] = "L 0 -234 234 -234";
			s[9] = "L 0 9999 0 0";
			s[10] = "L 0 9999 0 0";
			s[11] = "L 0 9999 0 0";
			s[12] = "L 0 9999 0 0";
			s[13] = "L 0 9999 0 0";
			s[14] = "L 0 9999 0 0";
			while (i < 15)
			{
				line coor;
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt, (int)12);
		}
		TEST_METHOD(TestMethod9)//-2
		{
			int i = 0;
			string s[4];
			s[0] = "L 0 0 0 1000";
			s[1] = "L 1 0 1 1";
			s[2] = "L 0 2 2 2";
			s[3] = "L 0 2 2 2";
			while (i < 4)
			{
				line coor;
				//getline(cin, str);
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt, (int)2);
		}
		TEST_METHOD(TestMethod10)//-3
		{
			int i = 0;
			string s[3];
			s[0] = "L 0 0 345 123";
			s[1] = "L 0 0 -233 -5";
			s[2] = "L 0 500 500 0";
			while (i < 3)
			{
				line coor;
				//getline(cin, str);
				coor.store_coor(s[i]);
				coor_4_line.push_back(coor);
				i++;
			}
			cnt_coor_num();
			p_cnt = intersection.size();
			Assert::AreEqual(p_cnt, (int)3);
		}
	};
}
