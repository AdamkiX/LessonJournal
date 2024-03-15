	#include "Function.h"
#include <vector>

Function::Function()		// Konstruktor
{
	year = 1950;
	av_grade = 0;
	out_file = "C:/Users/Adamki/Desktop/STUDIA/Rok II/PK/e0526ec5-gr12-repo/Projekt/Dziennik lekcyjny/Dziennik lekcyjny/Informacje.txt";
	ofstream file;
	file.open(out_file);
	if (file.is_open() == true)
	{
		file << "";
	}
}

void Function::MainMenu(MyList<StudentData>& S, MyList<StudentGrade>& G)		// Menu glowne
{
	CheckSubjects(G);															
	bool loop = true;
	do
	{
		cout << "Witam w bazie danych uczniów, proszê wybraæ jedn¹ z poni¿szych opcji:" << endl;

		cout << "1. Œrednie ocen uczniów" << endl
		<< "2. Spis osób urodzonych w danym roku" << endl
		<< "3. Spis osób, których œrednia z danego przedmiotu, jest wy¿sza ni¿ zadana ocena" << endl
		<< "4. Wyjœcie z programu" << endl;
		char choice = _getch();

		switch (choice)
		{
		case '1':
		{
			Av_grade(S,G);
			system("CLS");
			break;
		}
		case '2':
		{
			BirthYear(S);
			system("CLS");
			break;
		}
		case '3':
		{
			AvargeSearch(S, G);
			system("CLS");
			break;
		}
		case '4':
		{
			bool loop2 = true;
			do
			{
				cout << "Czy chcesz zakoñczyæ program?	t/n" << endl;
				char yn = _getch();
				switch (yn)
				{
				case 't':
				{
					loop2 = false;
					loop = false;
					break;
				}
				case 'n':
				{
					loop2 = false;
					break;
				}
				}
				system("CLS");
			} while (loop2 == true);
			break;
		}
		default:
		{
			system("CLS");
		}
		}

	} while (loop == true);
}

void Function::CheckSubjects(MyList<StudentGrade>& G)			// Ile i jakie przedmioty sa w bazie danych
{
	subjects.Push(G.Get(0).subject);
	for (int i = 0; i < G.size; i++)
	{	
		for (int j = 0; j < subjects.size; j++)
		{
			if (G.Get(i).subject == subjects.Get(j))
			{
				break;
			}
			else
			{
				if (j == subjects.size - 1)
				{
					subjects.Push(G.Get(i).subject);
				}
			}
		}
	}
}

void Function::Av_grade(MyList<StudentData> &S, MyList<StudentGrade> &G)		// Srednia wszystkich ocen studneta
{
	cout << "Wpisz liczbê studentów, dla których chcesz sprawdziæ œredni¹ ocen ze wszystkich przedmiotów: " << endl;
	int x;
	cin >> x; x = InputCheck(x);
	for (int i = 0; i < x; i++)
	{
		SelectStudent(S, G);
		system("CLS");
	}
	cout << "Wygenerowano œrednie ocen uczniów do pliku wyjœciowego.";
	char wait = _getch();
	system("CLS");

}

void Function::SelectStudent(MyList<StudentData>& S, MyList<StudentGrade>& G)	// Wybranie studenta, dla ktorego liczona bedzie srednia ze wszystkich przedmiotow
{
	cout << "Wybierz studenta wpisuj¹c jego numer PESEL" << endl << endl;
	bool notfound = true;
	do
	{
		string PESEL;
		cin >> PESEL;
		PESELCheck(PESEL);
		notfound = SDatabaseCheck(PESEL, S, G);
	} while (notfound == true);

}

void Function::PESELCheck(string& PESEL)			// Sprawdzanie czy uzytkownik podal poprawnie sformulowany pesel
{
	bool incorrect = true;
	do
	{
		if(PESEL.size() != 11)
		do
		{
			cout << "PESEL Ÿle sformu³owany!" << endl;
			cin >> PESEL;
		} while (PESEL.size() != 11);
		else
		{
			for (int i = 0; i < 11; i++)
			{
				if ((PESEL[i] > 47) and (PESEL[i] < 58))
				{
					incorrect = false;
					// cout << PESEL[i];
				}
				else
				{
					incorrect = true;
					break;
				}

			}
		}
	} while (incorrect == true);
}

bool Function::SDatabaseCheck(string& P, MyList<StudentData>& S, MyList<StudentGrade>& G)	// Sprawdzenie czy uczen widnieje w bazie danych
{
	bool found = false;
	int student = 0;
	for (int i = 0; i < S.size; i++)
	{
		if (S.Get(i).PESEL == P)
		{
			student = i;
			found = true;
			break;
		}
	}
	if (found)
	{
		ofstream file;
		file.open(out_file, std::ios_base::app);
		if (file.is_open() == true)
		{
			file << S.Get(student) << endl;
		}
		file.close();
		ShowAvGrades(S.Get(student), G);
		return false;
	}
	else
	{
		cout << "Nie ma takiego ucznia w bazie danych!" << endl;
		return true;
	}

}

void Function::ShowAvGrades(const StudentData& S, MyList<StudentGrade> &G)	// Wyznaczenie wszystkich srednich
{
	vector<vector<float>> allgrades;
	for (int i = 0; i < subjects.size; i++)
	{
		vector<float>* pointr = new vector<float>;
		allgrades.push_back(*pointr);
	}
	for (int i = 0; i < G.size; i++)
	{
		if (S.pesel == G.Get(i).pesel)			// Znaleziono ocenê studenta
		{
			for (int j = 0; j < subjects.size; j++)
			{
				if (subjects.Get(j) == G.Get(i).subject)	// Przypisanie oceny do przedmiotu
				{
					allgrades[j].push_back(G.Get(i).grade);
					break;
				}
			}

		}
	}
	for (int i = 0; i < allgrades.size(); i++)
	{
		if (allgrades[i].size() != 0)
		{
			float avarge = 0;
			for (int j = 0; j < allgrades[i].size(); j++)
			{
				avarge += allgrades[i][j];
			}
			avarge = avarge / allgrades[i].size();
			OutPut1(subjects.Get(i), avarge);
		}
		else
		{
			float none = 0;
			OutPut1(subjects.Get(i), none);
		}

	}
	ofstream file;
	file.open(out_file, std::ios_base::app);
	if (file.is_open() == true)
	{
		file << endl;
	}
	file.close();
}

void Function::OutPut1(const string& S, float &A)	// Wpisanie do plik wyjsciowego wszystkich srednich ucznia
{
	ofstream file;
	file.open(out_file, std::ios_base::app); 
	if (file.is_open() == true)
	{
		file << "Œrednia z " << S << ": " << A << endl;
	}
	file.close();
}

void Function::BirthYear(MyList<StudentData>& S)	// Funkcja wywolywana w ramach wyboru puktu 2 w menu
{
	cout << "Podaj rok urodzenia, po którym bêd¹ wyszukiwani studenci: " << endl;
	cin >> year; InputCheck(year);
	SearchYear(year, S);
}

void Function::SearchYear(int& Y, MyList<StudentData>& S)	// Przeszukanie listy w celu odnalezienia osob urodzonych w danym roku
{
	for (int i = 0; i < S.size; i++)
	{
		if (year == S.Get(i).year)
		{
			s_b_year.Push(S.Get(i));
		}
	}
	if (s_b_year.size != 0)
	{
		OutPut2(Y);
	}
	else
	{
		cout << "Brak uczniów o danym roczniku" << endl;
		char wait = _getch();
		system("CLS");
	}

}

void Function::OutPut2(int& Y)			// Wypisanie osob urodzonych w danym roku do pliku wyjsciowego
{
	ofstream file;
	file.open(out_file, std::ios_base::app);
	if (file.is_open() == true)
	{
		file << "Lista uczniów z rocznika: " << Y << endl;
		for (int i = 0; i < s_b_year.size; i++)
			file << s_b_year.Get(i) << endl;
		file << endl;
	}
	file.close();
	s_b_year.~MyList();
	cout << "Wygenerowano listê osób" << endl;
	char wait = _getch();
	system("CLS");
}

void Function::AvargeSearch(MyList<StudentData>& S, MyList<StudentGrade>& G)	// Funkcja wywolywana w ramach wyboru punktu 3 w menu
{
	bool found = false;
	cout << "Podaj przedmiot i œredni¹:  " << endl;
	string subject; 
	cin >> subject;
	cin >> av_grade; InputCheck(av_grade);
	for (int i = 0; i < subjects.size; i++)
	{
		if (subject == subjects.Get(i))
		{
			found = true;
			FindStudents(subject, S, G);
		}
	}
	if (found == false)
	{
		cout << "Zadany przedmiot nie istnieje w bazie danych!" << endl;
		char wait = _getch();
		system("CLS");
	}
}

void Function::FindStudents(const string& Su, MyList<StudentData>& S, MyList<StudentGrade>& G)	// Wyszukiwanie osob, ktorych ocena z przedmiotu jest wyzsza niz zadana
{
	StudentData student;
	int grade_count = 0;
	float s_avarge = 0;
	long long int curr_pesel = G.Get(0).pesel;

	ofstream file;
	file.open(out_file, std::ios_base::app);
	if (file.is_open() == true)
	{
		file << "Lista uczniów psoiadaj¹cy ocenê z: " << Su << "wiêksz¹ b¹dŸ równ¹: " << av_grade << endl;
	}
	file.close();

	G.SortGrowing();
	for (int i = 0; i < G.size; i++)
	{
		if (G.Get(i).pesel == curr_pesel)			// Sprawdzanie czy nowa osoba
		{
			if (Su == G.Get(i).subject)
			{ 
				grade_count++;
				s_avarge += G.Get(i).grade;
			}
		}
		else
		{
			if (grade_count != 0)
			{
				s_avarge = s_avarge / grade_count;
				student.pesel = G.Get(i--).pesel;
				for (int j = 0; j < S.size; j++)
				{
					if (student.pesel == S.Get(j).pesel)
					{
						student = S.Get(j);
					}
				}
				if (s_avarge >= av_grade)
				OutPut3(Su, s_avarge, student);
			}
			grade_count = 0;
			s_avarge = 0;
			curr_pesel = G.Get(i).pesel;
		}
	}
	cout << "Wygenerowano listê osób" << endl;
	char wait = _getch();
	system("CLS");
}

void Function::OutPut3(const string& Su, float& A, const StudentData& S)		// Wypisanie do pliku wyjsciowego osob posiadajcych z danego przedmiotu srednia wieksza niz zadana
{
	ofstream file;
	file.open(out_file, std::ios_base::app);
	if (file.is_open() == true)
	{
		file << S << endl;
		file << "Œrednia: " << A << endl;
		file << endl;
	}
	file.close();
}

Function::~Function()					// Destruktor
{
	year = NULL;
	av_grade = NULL;
	subjects.~MyList();
	s_b_year.~MyList();
	out_file.~basic_string();
}