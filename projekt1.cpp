#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix
{
	vector<vector<double> >tab;

	public:

		Matrix(int n, int m)
		{
			tab.resize(n, vector<double>(m, 0));
		}

		Matrix(int n)
		{
			tab.resize(n, vector<double>(n, 0));
		}

		Matrix(string path)
		{
			cout << "Wczytano macierz z pliku" << endl;
			ifstream file;
			file.open(path.c_str());

			string line;
			int n, m;

			if (file.is_open())
			{
				file >> line >> n >> line >> m;
				tab.resize(n, vector<double>(m, 0));

					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							file >> line;
							tab[i][j] = atoi(line.c_str());
						}
					}
			}
			else 
				cout << "Blad w otwarciu pliku";

			file.close();
		}

		Matrix(Matrix &copy)
		{
			tab = copy.tab;
		}

		~Matrix()
		{
			tab.erase(tab.begin());
		}

		void set(int n, int m, double val)
		{
			cout << "Ustawiono wartosc " << val << " na n=" << n << " i m=" << m << endl;
			tab[n][m] = val;
		}	

		void get(int n, int m)
		{
			cout<<"Pobrano element z n=" <<	n << " i m=" << m <<". Wartosc elementu wynosi ";
			cout << tab[n][m]<<endl;
		}

		void add(Matrix addition)
		{
			cout << "Dodano macierze" << endl;
			for (int i = 0; i < tab.size(); i++)
			{
				for (int j = 0; j < tab[i].size(); j++)
				{
					tab[i][j] = tab[i][j] + addition.tab[i][j];
				}
			}
		}

		void substract(Matrix substract)
		{
			cout << "Odjeto macierze" << endl;
			for (int i = 0; i < tab.size(); i++)
			{
				for (int j = 0; j < tab[i].size(); j++)
				{
					tab[i][j] = tab[i][j] - substract.tab[i][j];
				}
			}
		}

		void multiply(Matrix multiply)
		{
			cout << "Pomnozono macierze" << endl;
			vector<vector<double> >helper;
			helper.resize(tab.size(), vector<double >(multiply.tab[0].size(), 0));

			for (int i = 0; i < tab.size(); i++)
			{
				for (int j = 0; j < multiply.tab[0].size(); j++)
				{
					int x = 0;
					for (int k = 0; k < tab[0].size(); k++)
						x += tab[i][k] * multiply.tab[k][j];

					helper[i][j] = x;
				}
			}
			tab = helper;
		}
	
		int cols()
		{
			return tab.size();
		}

		int rows()
		{
			return tab[0].size();
		}

		void print()
		{
			for (int i = 0; i < tab.size(); i++)
			{
				for (int j = 0; j < tab[i].size(); j++)
				{
					cout << tab[i][j] << "   ";
				}
				cout<< endl;
			}
		}

		void store(string filename, string path)
		{
			cout << "Zapisywanie macierzy do pliku" << endl;
			ofstream file;
			file.open("matrix.txt");

			if (file.is_open())
			{
				file << "Wierszy: " << rows() << " Kolumn: " << cols() << endl;

				for (int i = 0; i < tab.size(); i++)
				{
					for (int j = 0; j < tab[i].size(); j++)
					{
						file << tab[i][j] << " ";
					}
					file << endl;
				}
			}
			else
				cout << "Blad w otwarciu pliku";

			file.close();
		}

		void allthesame()
		{
			srand(time(NULL));
			int random = rand() % 10 + 1;

			for (int i = 0; i < tab.size(); i++)
			{
				for (int j = 0; j < tab[i].size(); j++)
				{
					tab[i][j]=random;
				}
			}
			cout << endl;
		}
};
//___________________________________________________________________________________________MAIN________________________________________________________________________
int main()
{
	//Zadanie 1
	Matrix m1(8, 7);

	//Zadanie 2
	cout << "Zadanie 2:\n" << endl;
	m1.set(2, 4, 5);
	cout << "(dla macierzy m1)" << endl;
	cout << "_________________________________________" << endl;

	//Zadanie 3
	cout << "Zadanie 3:\n" << endl;
	m1.get(2, 4);
	cout << "(pobrano z macierzy m1)" << endl;
	cout << "_________________________________________________________" << endl;

	//Zadanie 4
	cout << "Zadanie 4:\n" << endl;
	Matrix m2(8, 7);
	m2.set(2, 4, 5);
	cout << "(ustawiono dla macierzy m2)\n" << endl;
	m1.add(m2);
	cout << "(dodano macierz m1 i m2)" << endl;
	m1.print();
	cout << "____________________________________________________________" << endl;

	//Zadanie 5
	cout << "Zadanie 5:" << endl;
	m1.allthesame();
	m1.print();

	m2.allthesame();
	m2.print();

	m1.substract(m2);
	m1.print();
	cout << "____________________________________________________________" << endl;

	//Zadanie 6
	cout << "Zadanie 6:";
	Matrix m3(5);
	Matrix m4(5);

	m3.allthesame();
	m3.print();

	m4.allthesame();
	m4.print();

	m3.multiply(m4);
	m3.print();
	cout << "____________________________________________________________" << endl;

	//Zadanie 7
	cout << "Zadanie 7:\n" << endl;
	cout << "Zwrocono liczbe kolumn macierzy: ";
	cout << m1.cols();
	cout << "\n(zwrocono dla macierzy m1)" << endl;
	cout << "\n____________________________________________________________" << endl;

	//Zadanie 8
	cout << "Zadanie 8:\n" << endl;
	cout << "Zwrocono liczbe wierszy macierzy: ";
	cout << m3.rows();
	cout << "\n(zwrocono dla macierzy m3)" << endl;
	cout << "\n____________________________________________________________" << endl;

	//Zadanie 10
	cout << "Zadanie 10:\n" << endl;
	m3.store("matrix.txt", "./");
	cout << "(zapisano do pliku macierz m3, ktora byla wynikiem mnozenia macierzy)" << endl;
	cout << "____________________________________________________________" << endl;

	//Zadanie 11
	cout << "Zadanie 11:" << endl;
	Matrix m7("matrix.txt");
	cout << "(wczytano macierz, ktora w zadaniu 10 zostala zapisana do pliku)" << endl;
	m7.print();
	cout << "____________________________________________________________" << endl;
}
