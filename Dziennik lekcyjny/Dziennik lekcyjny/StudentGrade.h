#pragma once

#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class StudentGrade
{
public:
	static int line_track;
	char PESEL[12];				// ID
	long long int pesel;
	string subject;
	float grade;
	string descryption;

	StudentGrade();
	friend std::ostream& operator<<(std::ostream& os, const StudentGrade& p)
	{
		return os << "("
			<< p.PESEL << ", "
			<< p.subject << ", "
			<< p.grade << ", "
			<< p.descryption
			<< ")";
	}
	bool operator >=(const StudentGrade& StudentGradeObj) const
	{
		return pesel >= StudentGradeObj.pesel;
	}
	bool operator <=(const StudentGrade& StudentGradeObj) const
	{
		return pesel <= StudentGradeObj.pesel;
	}
	void LoadData(string file_name, int Student);
	~StudentGrade();

};

