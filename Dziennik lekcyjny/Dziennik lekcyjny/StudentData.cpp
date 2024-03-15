#include "StudentData.h"


StudentData::StudentData()
{
	for (int i = 0; i < 12; i++)
	{
		PESEL[i] = '0';
	}
	name = "a";
	surname = "a";
	birth[0] = '0'; birth[1] = '0'; birth[2] = '.'; birth[3] = '0'; birth[4] = '0'; birth[5] = '.';
	birth[6] = '0'; birth[7] = '0'; birth[8] = '0'; birth[9] = '0';
	birth[10] = '\0';
	street = "Ulica";
	nr_street = "0/0";
	town = "Miasto";
}

void StudentData::LoadData(string file_name, int S)
{
	string line,s;
	ifstream file;
	stringstream ss;
	int i = 0;

	file.open(file_name);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			i++;
			ss << line;
			ss >> PESEL >> name >> surname >> birth >> street >> nr_street >> town;
			if ((PESEL == 0))
			{
				cout << "B³êdny PESEL (uczniowie)! Upewnij siê, ¿e wszystkie pola s¹ poprawnie wype³nione." << endl;
				exit(0);
			}
			ss.clear();
			if (i > S)
				break;
		}

	}
	else
	{
		cout << "Nie znaleziono pliku ze studentami!" << endl;
		exit(0);
	}
	std::stringstream str(PESEL);
	str >> pesel;
	_year[0] = birth[6];
	_year[1] = birth[7];
	_year[2] = birth[8];
	_year[3] = birth[9];
	std::stringstream str2(_year);
	str2 >> year;
	// cout << year << endl;

}

StudentData::~StudentData()
{
	line_track = NULL;
	for (int i = 0; i < 12; i++)
	{
		PESEL[i] = NULL;
	}
	name.~basic_string();
	surname.~basic_string();
	for (int i = 0; i < 11; i++)
	{
		birth[i] = NULL;
	}
	year = NULL;
	for (int i = 0; i < 4; i++)
	{
		_year[i] = NULL;
	}
	street.~basic_string();
	nr_street.~basic_string();
	town.~basic_string();
	pesel = NULL;
}