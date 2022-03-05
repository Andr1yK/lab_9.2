#include "pch.h"
#include "CppUnitTest.h"

#include "../lab_9.2/Student.cpp"
#include "../lab_9.2/extendFunctions.cpp"
#include "../lab_9.2/lab_9.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
    TEST_METHOD(TestSort)
    {
      const int N = 10;

      Student students[N] = {
        {"Moroz",     1, KN,  4, 4, 5},
        {"Tkachuk",   4, INF, 4, 3, 4},
        {"Petrenko",  1, ME,  5, 4, 2},
        {"Koval",     3, KN,  3, 3, 3},
        {"Tkachenko", 4, FI,  5, 5, 2},
        {"Rudenko",   1, INF, 3, 5, 5},
        {"Boyko",     5, FI,  2, 4, 4},
        {"Savchenko", 4, MF,  4, 3, 5},
        {"Lysenko",   2, INF, 4, 5, 3},
        {"Melnyk",    3, FI,  1, 3, 5},
      };

      Student excepted[N] = {
        {"Tkachenko", 4, FI,  5, 5, 2},
        {"Petrenko",  1, ME,  5, 4, 2},
        {"Tkachuk",   4, INF, 4, 3, 4},
        {"Savchenko", 4, MF,  4, 3, 5},
        {"Lysenko",   2, INF, 4, 5, 3},
        {"Moroz",     1, KN,  4, 4, 5},
        {"Koval",     3, KN,  3, 3, 3},
        {"Rudenko",   1, INF, 3, 5, 5},
        {"Boyko",     5, FI,  2, 4, 4},
        {"Melnyk",    3, FI,  1, 3, 5},
      };

      Sort(students, N);

      for (int i = 0; i < N; i++)
        Assert::AreEqual(excepted[i].lastName, students[i].lastName);
    };

    TEST_METHOD(TestIndexSort)
    {
      const int N = 10;

      Student students[N] = {
        {"Moroz",     1, KN,  4, 4, 5},
        {"Tkachuk",   4, INF, 4, 3, 4},
        {"Petrenko",  1, ME,  5, 4, 2},
        {"Koval",     3, KN,  3, 3, 3},
        {"Tkachenko", 4, FI,  5, 5, 2},
        {"Rudenko",   1, INF, 3, 5, 5},
        {"Boyko",     5, FI,  2, 4, 4},
        {"Savchenko", 4, MF,  4, 3, 5},
        {"Lysenko",   2, INF, 4, 5, 3},
        {"Melnyk",    3, FI,  1, 3, 5},
      };

      int* sortedIndexes = IndexSort(students, N);

      Student excepted[N] = {
        {"Tkachenko", 4, FI,  5, 5, 2},
        {"Petrenko",  1, ME,  5, 4, 2},
        {"Tkachuk",   4, INF, 4, 3, 4},
        {"Savchenko", 4, MF,  4, 3, 5},
        {"Lysenko",   2, INF, 4, 5, 3},
        {"Moroz",     1, KN,  4, 4, 5},
        {"Koval",     3, KN,  3, 3, 3},
        {"Rudenko",   1, INF, 3, 5, 5},
        {"Boyko",     5, FI,  2, 4, 4},
        {"Melnyk",    3, FI,  1, 3, 5},
      };

      for (int i = 0; i < N; i++)
        Assert::AreEqual(excepted[i].lastName, students[sortedIndexes[i]].lastName);
    }

    TEST_METHOD(TestBinSearch1)
    {
      const int N = 10;

      Student students[N] = {
        {"Moroz",     1, KN,  4, 4, 5},
        {"Tkachuk",   4, INF, 4, 3, 4},
        {"Petrenko",  1, ME,  5, 4, 2},
        {"Koval",     3, KN,  3, 3, 3},
        {"Tkachenko", 4, FI,  5, 5, 2},
        {"Rudenko",   1, INF, 3, 5, 5},
        {"Boyko",     5, FI,  2, 4, 4},
        {"Savchenko", 4, MF,  4, 3, 5},
        {"Lysenko",   2, INF, 4, 5, 3},
        {"Melnyk",    3, FI,  1, 3, 5},
      };

      Sort(students, N);
      int pos = BinSearch(students, N, "Koval", 3, 3);

      Assert::AreEqual(6, pos);
    };

    TEST_METHOD(TestBinSearch2)
    {
      const int N = 10;

      Student students[N] = {
        {"Moroz",     1, KN,  4, 4, 5},
        {"Tkachuk",   4, INF, 4, 3, 4},
        {"Petrenko",  1, ME,  5, 4, 2},
        {"Koval",     3, KN,  3, 3, 3},
        {"Tkachenko", 4, FI,  5, 5, 2},
        {"Rudenko",   1, INF, 3, 5, 5},
        {"Boyko",     5, FI,  2, 4, 4},
        {"Savchenko", 4, MF,  4, 3, 5},
        {"Lysenko",   2, INF, 4, 5, 3},
        {"Melnyk",    3, FI,  1, 3, 5},
      };

      int pos = BinSearch(students, N, "Koval", 4, 3);

      Assert::AreEqual(-1, pos);
    };
	};
}
 