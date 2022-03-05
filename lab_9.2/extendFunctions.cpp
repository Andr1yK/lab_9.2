#include <string>

#include "Student.hpp"
#include "extendFunctions.hpp"

using namespace std;

void Fill(Student* students, const int N)
{
  unsigned specialty;
  for (int index = 0; index < N; index++)
  {
    cout << "������� � " << index + 1 << ":" << endl;

    cin.get(); cin.sync();

    cout << " �������: "; getline(cin, students[index].lastName);

    cout << " ����: "; cin >> students[index].rank;

    cout << " ������������ (0 - ��, 1 - ��, 2 - Բ, 3 - ��, 4 - ��): ";
    cin >> specialty;
    students[index].specialty = (Specialty)specialty;

    cout << " ������ � ������ : "; cin >> students[index].physics;
    cout << " ������ � ���������� : "; cin >> students[index].mathematics;


    cout << " ������ � ";
    switch (students[index].specialty)
    {
    case KN:
      cout << "������������� : "; cin >> students[index].programing;
      break;

    case INF:
      cout << "��������� ������ : "; cin >> students[index].programing;
      break;

    default:
      cout << "��������� : "; cin >> students[index].pedagogy;
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

  cout << "| " << setw(2) << "� " << " | "
    << setw(12) << left << "�������" << " | "
    << setw(4) << "����" << " | "
    << setw(20) << "������������" << " | "
    << setw(6) << "Գ����" << " | "
    << setw(6) << "�����." << " | "
    << setw(8) << "�������." << " | "
    << setw(11) << "���. ������" << " | "
    << setw(10) << "���������" << " |"
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
