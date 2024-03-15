#include "FileOpen.h"

#include <fstream>
#include <stdio.h>

using namespace std;

int NumStudents(string file_name)
{
	int num_lines = 0, a = 0,cou = 0;
	string line;
	ifstream file;
	file.open(file_name);

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			a = line.size();
			for (int i = 0; i < a; i++)
			{
				if (line[i] == ' ')
				{
					cou++;
				}

			}
			++num_lines;
			if (cou % 6 != 0)
			{
				cout << "B³¹d wczytu pliku z uczniami! Upewnij siê, ¿e wszystkie pola s¹ wype³nione." << endl;
				exit(0);				
			}
		}
	}
	else
	{
		cout << "Nie odnaleziono pliku!" << endl;
		exit(0);
	}
	file.close();
	return num_lines;
}

int NumMarks(string file_name)
{
	int num_lines = 0, a = 0, cou = 0;
	string line;
	ifstream file;
	file.open(file_name);

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			a = line.size();
			for (int i = 0; i < a; i++)
			{
				if (line[i] == ' ')
				{
					cou++;
				}

			}
			++num_lines;
			if (cou % 3 != 0)
			{
				cout << "B³¹d wczytu pliku z ocenami! Upewnij siê, ¿e wszystkie pola s¹ wype³nione." << endl;
				exit(0);
			}
		}
	}
	else
	{
		cout << "Nie odnaleziono pliku!" << endl;
		exit(0);
	}
	file.close();
	return num_lines;
}

