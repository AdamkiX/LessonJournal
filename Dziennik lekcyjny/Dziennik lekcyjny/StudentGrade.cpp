	#include "StudentGrade.h"

StudentGrade::StudentGrade()				// Konstruktor
{
	for (int i = 0; i < 12; i++)
	{
		PESEL[i] = '0';
	}
	subject = "";
	grade = 0;
	descryption = "";
}
void StudentGrade::LoadData(string file_name, int S)	// Ladowanie danych do obiektu klasy
{
	string line, s;
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
			ss >> PESEL >> subject >> grade >> descryption;
			if ((PESEL == 0))
			{
				cout << "B³êdny PESEL (oceny)! Upewnij siê, ¿e wszystkie pola s¹ poprawnie wype³nione." << endl;
				exit(0);
			}
			ss.clear();
			if (i > S)
				break;
		}
		line_track++;
	}
	else
	{
		cout << "Nie znaleziono pliku z ocenami!" << endl;
		exit(0);
	}
	std::stringstream str(PESEL);
	str >> pesel;
}

StudentGrade::~StudentGrade()		// Destruktor
{
	line_track = NULL;
	for (int i = 0; i < 12; i++)
	{
		PESEL[i] = NULL;
	}
	pesel = NULL;
	subject.~basic_string();
	grade = NULL;
	descryption.~basic_string();
}
