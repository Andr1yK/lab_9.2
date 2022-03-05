#include <string>

#include "Student.hpp"
#include "extendFunctions.hpp"

using namespace std;

void Fill(Student* students, const int N)
{
  unsigned specialty;
  for (int index = 0; index < N; index++)
  {
    cout << "Студент № " << index + 1 << ":" << endl;

    cin.get(); cin.sync();

    cout << " Прізвище: "; getline(cin, students[index].lastName);

    cout << " Курс: "; cin >> students[index].rank;

    cout << " Спеціальність (0 - МЕ, 1 - МФ, 2 - ФІ, 3 - ІН, 4 - КН): ";
    cin >> specialty;
    students[index].specialty = (Specialty)specialty;

    cout << " Оцінка з фізики : "; cin >> students[index].physics;
    cout << " Оцінка з математики : "; cin >> students[index].mathematics;


    cout << " Оцінка з ";
    switch (students[index].specialty)
    {
    case KN:
      cout << "програмування : "; cin >> students[index].programing;
      break;

    case INF:
      cout << "чисельних методів : "; cin >> students[index].programing;
      break;

    default:
      cout << "педегогіки : "; cin >> students[index].pedagogy;
    }

    cout << endl;
  }
}

void Print(
  Student* students, const int N,
  std::string* specialtyList,
  int* sortedIndex, bool forIndexes
) {
#pragma region Header
  cout << "===========================================================================================================" << endl;

  cout << "| " << setw(2) << "№ " << " | "
    << setw(12) << left << "Прізвище" << " | "
    << setw(4) << "Курс" << " | "
    << setw(20) << "Спеціальність" << " | "
    << setw(6) << "Фізика" << " | "
    << setw(6) << "Матем." << " | "
    << setw(8) << "Програм." << " | "
    << setw(11) << "Чис. методи" << " | "
    << setw(10) << "Педагогіка" << " |"
    << endl;

  cout << "-----------------------------------------------------------------------------------------------------------" << endl;
#pragma endregion

  int currentIndex;

  for (int index = 0; index < N; index++) {
    if (forIndexes)
      currentIndex = sortedIndex[index];
    else
      currentIndex = index;

    cout << "|" << setw(2) << right << index + 1 << " "
      << " | " << setw(12) << left << students[currentIndex].lastName
      << " | " << setw(4) << right << students[currentIndex].rank
      << " | " << setw(20) << left << specialtyList[students[currentIndex].specialty]
      << " | " << setw(6) << right << students[currentIndex].physics
      << " | " << setw(6) << right << students[currentIndex].mathematics;

    switch (students[currentIndex].specialty)
    {
    case KN:
      cout << " | " << setw(8) << right << students[currentIndex].programing
        << " | " << setw(14)
        << " | " << setw(12)
        << " |"
        << endl;
      break;

    case INF:
      cout << " | " << setw(11)
        << " | " << setw(11) << right << students[currentIndex].numMethods
        << " | " << setw(12)
        << " |"
        << endl;
      break;

    default:
      cout << " | " << setw(11)
        << " | " << setw(14)
        << " | " << setw(10) << right << students[currentIndex].pedagogy
        << " |"
        << endl;
    }

    if (index < N-1)
      cout << "-----------------------------------------------------------------------------------------------------------" << endl;

  }

  cout << "==========================================================================================================="
    << endl << endl;
}
