#include <iostream>
#include <iomanip>
#include <Windows.h>

#include "extendFunctions.hpp"
#include "Student.hpp"

using namespace std;

#pragma region PROTO
bool getCondition(
  int cPhysics, int cRank, string cLastName,
  int physics, int rank, string lastName
);

void Sort(Student*, const int);
int* IndexSort(Student*, const int);

int BinSearch(
  Student* students, const int N,
  const string lastName, const unsigned rank, const unsigned physics
);
#pragma endregion

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  string specialtyList[] = {
    "Матем. та економіка",
    "Трудове навчання",
    "Фізика та інформ.",
    "Інформатика",
    "Комп’ютерні науки"
  };

  unsigned int N = 0;
  Student* students = nullptr;
  Student* temp = nullptr;

  Student forAutoFill[10] = {
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

  int* sortedIndex = nullptr;

  string findLastName;
  unsigned findRank;
  int findPhysics;
  int found;

  int menuItem;
  do {
    cout << endl << endl;
    cout << "Виберіть дію:" << endl << endl;
    cout << " [1] - введення даних з клавіатури" << endl;
    cout << " [2] - автоматичне введення даних" << endl;
    cout << " [3] - вивід даних на екран" << endl;
    cout << " [4] - фізичне впорядкування даних" << endl;
    cout << " [5] - індексне впорядкування та вивід даних" << endl;
    cout << " [6] - бінарний пошук працівника за посадою та прізвищем" << endl;

    cout << endl;

    cout << " [0] - вихід та завершення роботи програми" << endl << endl;
    cout << "Введіть значення: "; cin >> menuItem;
    cout << endl << endl << endl;
    
    switch (menuItem)
    {
    case 1:
      cout << "Введіть N: "; cin >> N;
      students = new Student[N];

      Fill(students, N);
      break;
    case 2:
      cout << "Введіть N(max 10): "; cin >> N;
      if (N > 10)
        N = 10;

      temp = new Student[N];

      for (unsigned i = 0; i < N; i++)
        temp[i] = forAutoFill[i];

      delete[] students;
      students = temp;
      break;
    case 3:
      Print(students, N, specialtyList);
      break;
    case 4:
      Sort(students, N);
      break;
    case 5:
      sortedIndex = IndexSort(students, N);
      Print(students, N, specialtyList, sortedIndex, true);
      break;
    case 6:
      cin.get();
      cin.sync();

      cout << "Введіть ключі пошуку:" << endl;
      cout << " прізвище: "; getline(cin, findLastName);

      cout << " курс: "; cin >> findRank;
      cout << endl;

      cout << " оцінка з фізики: "; cin >> findPhysics;
      cout << endl;

      if ((found = BinSearch(students, N, findLastName, findRank, findPhysics)) != -1)
        cout << "Знайдено працівника в позиції " << found + 1 << endl;
      else
        cout << "Шуканого студента не знайдено" << endl;

      break;
    case 0:
      break;
    default:
      cout << "Ви ввели помилкове значення! "
        "Слід ввести число - номер вибраного пункту меню" << endl;
    }
  } while (menuItem != 0);

  return 0;
}

bool getCondition(
  int cPhysics, int cRank, string cLastName,
  int physics, int rank, string lastName
) {

  bool byPhisics = cPhysics > physics;
  bool byRank = cPhysics == physics
    && cRank > rank;

  bool byLastName = cPhysics == physics
    && cRank == rank
    && cLastName > lastName;

  return byPhisics || byRank || byLastName;
}

void Sort(Student* students, const int N)
{
  int countsSwap;
  do
  {
    countsSwap = 0;

    for (int i = 1; i < N; i++) {
      const Student prev = students[i - 1];
      const Student current = students[i];

      if (getCondition(
        current.physics, current.rank, current.lastName,
        prev.physics, prev.rank, prev.lastName
      )) {
        countsSwap++;
        students[i - 1] = current;
        students[i] = prev;
      }
    }
  } while (countsSwap > 0);
}

int* IndexSort(Student* students, const int N)
{
  int* sorted = new int[N];

  for (int index = 0; index < N; index++)
    sorted[index] = index;

  int index, j, key;

  for (index = 1; index < N; index++)
  {
    key = sorted[index];

    for (j = index - 1;
      j >= 0 && getCondition(
          students[key].physics, students[key].rank, students[key].lastName,
          students[sorted[j]].physics, students[sorted[j]].rank,
          students[sorted[j]].lastName
      );
      j--
    ) sorted[j + 1] = sorted[j];

    sorted[j + 1] = key;
  }

  return sorted;
}

int BinSearch(
  Student* students, const int N,
  const string lastName, const unsigned rank, const unsigned physics
) {
  int left = 0, right = N - 1, mid;
  Student student;
  do {
    mid = (left + right) / 2;
    student = students[mid];
    
    if (student.lastName == lastName && student.rank == rank && student.physics == physics)
      return mid;

    if (getCondition(
      student.physics, student.rank, student.lastName,
      physics, rank, lastName
    ))
      left = mid + 1;
    else
      right = mid - 1;

  } while (left <= right);

  return -1;
}