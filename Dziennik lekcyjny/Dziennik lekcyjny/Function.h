#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <conio.h>

#include "MyList.h"
#include "StudentData.h"
#include "StudentGrade.h"

using namespace std;

class Function
{
public:
	int year;
	float av_grade;
	MyList<string> subjects;
	MyList<StudentData> s_b_year;
	string out_file;

	Function();
	void MainMenu(MyList<StudentData>& StudentDatabase, MyList<StudentGrade>& GradesDatabase);
	void Av_grade(MyList<StudentData>& StudentDatabase, MyList<StudentGrade>& GradesDatabase);
	void SelectStudent(MyList<StudentData>& StudentDatabase, MyList<StudentGrade>& GradesDatabase);
	void PESELCheck(string& PESEL);
	bool SDatabaseCheck(string& PESEL, MyList<StudentData>& StudentDatabase, MyList<StudentGrade>& GradesDatabase);
	void ShowAvGrades(const StudentData& Student, MyList<StudentGrade>& GradesDatabase);
	void CheckSubjects(MyList<StudentGrade>& GradesDatabase);
	void OutPut1(const string& subject, float& AvGarde);
	template<typename T>
	T InputCheck(T value)
	{
		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Podano nie poprawn¹ wartoœæ! Proszê podaæ j¹ ponownie: " << endl;
			cin >> value;
		}
		return value;
	}

	void BirthYear(MyList<StudentData>& StudentDatabase);
	void SearchYear(int & year, MyList<StudentData>& StudentDatabase);
	void OutPut2(int& year);
	void AvargeSearch(MyList<StudentData>& StudentDatabase, MyList<StudentGrade>& GradesDatabase);
	void FindStudents(const string& Subject, MyList<StudentData>& StudentDatabase, MyList<StudentGrade>& GradesDatabase);
	void OutPut3(const string& Subject, float& Avarge, const StudentData& StudentDatabase);
	~Function();
};
#endif