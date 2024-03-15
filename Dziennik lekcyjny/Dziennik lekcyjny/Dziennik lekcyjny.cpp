
#include <chrono>

#include "Function.h"
#include "FileOpen.h"

using namespace std;

int StudentData::line_track = 0;
int StudentGrade::line_track = 0;

int main(int argc, char* argv[])
{
	if (argc == 7)
	{
		setlocale(LC_CTYPE, "Polish");

		int count = 0;
		string file1 = "";
		string file2 = "";

		Function function;

		for (int i = 1; i < 7; i ++)
		{
			string inper = "-inper";
			string insub = "-insub";
			string out = "-out";

			if (argv[i] == inper)
			{
				file1 = argv[i + 1];
				i++;
				count++;
			}
			else if (argv[i] == insub)
			{
				file2 = argv[i + 1];
				i++;
				count++;
			}
			else if (argv[i] == out)
			{
				function.out_file = argv[i + 1];
				i++;
				count++;
			}
			else
			{
				cout << "Podano zły parametr!" << endl;
				exit(-1);
			}
		}

		MyList<StudentData> StudentsDatabase;
		MyList<StudentGrade> GradesDatabase;

		for (int i = 0; i < NumStudents(file1); i++)
		{
			StudentData* pointr_data = new StudentData;
			pointr_data->LoadData(file1, i);
			StudentsDatabase.Push(*pointr_data);
		}
		for (int i = 0; i < NumMarks(file2); i++)
		{
			StudentGrade* pointr_grade = new StudentGrade;
			pointr_grade->LoadData(file2,i);
			GradesDatabase.Push(*pointr_grade);
		}

		function.MainMenu(StudentsDatabase, GradesDatabase);

		function.~Function();
		file1.~basic_string();
		file2.~basic_string();
		StudentsDatabase.~MyList();
		GradesDatabase.~MyList();

	}
	else 
	{
		cout << "Podano zły parametr!" << endl;
		_getch();
		exit(-1);
	}
}



