#pragma once

#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class StudentData
{
public:
	static int line_track;
	char PESEL[12];				// ID
	string name;
	string surname;
	char birth[11];
	int year;
	char _year[4];
	string street;
	string nr_street;
	string town;
	long long int pesel;

	StudentData();
	friend std::ostream& operator<<(std::ostream& os, const StudentData& p)
	{
		return os << "("
			<< p.PESEL << ", "
			<< p.name << ", "
			<< p.surname << ": "
			<< p.birth << ", "
			<< p.street << ": "
			<< p.nr_street << ", "
			<< p.town
			<< ")";
	}
	bool operator >=(const StudentData& StudentDataObj) const
	{
		return pesel >= StudentDataObj.pesel;
	}
	bool operator <=(const StudentData& StudentDataObj) const
	{
		return pesel <= StudentDataObj.pesel;
	}
	void LoadData(string file_name, int Student);
	~StudentData();


};

