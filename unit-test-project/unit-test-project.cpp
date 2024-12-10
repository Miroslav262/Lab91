#include "pch.h"
#include "CppUnitTest.h"
#include "../MyProject/telephone_info.h"
#include "../MyProject/processing.h"
#include "../MyProject/sort.h"
#include <cmath>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	const double accurasity = 0.01;
	info* build_info(int hours, int minutes, int seconds, double cost)
	{
		info* information = new info;
		information->lasting.hours = hours;
		information->lasting.minutes = minutes;
		information->lasting.seconds = seconds;
		information->cost = cost;
		return information;
	}
	void delete_info(info** array, int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
		delete[]array;
	}
	
	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			info** information = new info*[3];
			information[0] = build_info(1, 20, 37, 0.02); 
			information[1] = build_info(0, 5, 10, 0.05); 
			information[2] = build_info(0, 27, 53, 1.15); 
			Assert::IsTrue(fabs(process(information, 3)-0.298)<=accurasity);
			delete_info(information, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			info** information = new info * [3];
			information[0] = build_info(0, 15, 6, 0.03);
			information[1] = build_info(0, 5, 9, 0.07);
			information[2] = build_info(0, 59, 16, 0.1);
			Assert::IsTrue(fabs(process(information, 3) - 0.084) <= accurasity);
			delete_info(information, 3);
		}
		TEST_METHOD(TestMethod3)
		{
			info** information = new info * [3];
			information[0] = build_info(9, 45, 8, 4.5);
			information[1] = build_info(0, 8, 9, 2);
			information[2] = build_info(2, 37, 5, 0.8);
			Assert::IsTrue(fabs(process(information, 3) - 3.698) <= accurasity);
			delete_info(information, 3);
		}
	};
	
}
