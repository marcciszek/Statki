#include <iostream>
#include <random>
#include <Windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void ustaw_statki(int plansza[10][10]);
void wypisz_cyfry(int plansza[10][10]);
void wypisz_znaki(int plansza[10][10]);
int sprawdzanie_miejsca(int x,int y, int plansza[10][10],int kierunek, int maszt);

int main()
{
	int plansza[10][10]{ 0 };
		ustaw_statki(plansza);
		wypisz_cyfry(plansza);
		cout << endl;
		wypisz_znaki(plansza);



	//system("PAUSE");
}

void ustaw_statki(int plansza[10][10])
{
	random_device ziarno;
	mt19937 losowa(ziarno());
	uniform_int_distribution<int> zakres_plansza(0, 9);
	uniform_int_distribution<int> zakres_kierunek(0, 3);

	//int x = 5;
	//int y = 5;
	//int kierunek = 2;

	for (int maszt = 4; maszt > 0; maszt--)
	{
		for (int ilosc = 1;ilosc < (6 - maszt);)
		{
			int x = zakres_plansza(losowa);
			int y = zakres_plansza(losowa);
			int kierunek = zakres_kierunek(losowa);
							
			if (kierunek == 0) //w gore
			{
				if ((y  + 1 - maszt) >= 0 and sprawdzanie_miejsca(x,y,plansza,kierunek,maszt)==1)
				{
					for (int i = y;i > (y - maszt);i--)
					{
						plansza[i][x] = maszt;
						if (i == y)
						{
							if (y < 9)
							{
								plansza[i + 1][x] = -1;
							}
							if (y < 9 and x > 0)
							{
								plansza[i + 1][x-1] = -1;
							}
							if (y < 9 and x < 9)
							{
								plansza[i + 1][x + 1] = -1;
							}
							if (x > 0)
							{
								plansza[i][x - 1] = -1;
							}
							if (x < 9)
							{
								plansza[i][x + 1] = -1;
							}
						}
						if (i == (y + 1 - maszt))
						{
							if ((y + 1 - maszt) > 0)
							{
								plansza[i - 1][x] = -1;
							}
							if ((y + 1 - maszt) > 0 and x > 0)
							{
								plansza[i - 1][x-1] = -1;
							}
							if ((y + 1 - maszt) > 0 and x < 9)
							{
								plansza[i - 1][x + 1] = -1;
							}
							if (x > 0)
							{
								plansza[i][x - 1] = -1;
							}
							if (x < 9)
							{
								plansza[i][x + 1] = -1;
							}
						}
						else
						{
							if (x > 0)
							{
								plansza[i][x-1] = -1;
							}
							if (x < 9)
							{
								plansza[i][x+1] = -1;
							}
						}
					}
					ilosc++;
				}			
			}
			else if (kierunek == 1) // w prawo
			{
				if ((x - 1 + maszt) <= 9 and sprawdzanie_miejsca(x, y, plansza, kierunek, maszt)==1)
				{
					for (int i = x;i < (x + maszt);i++)
					{
						plansza[y][i] = maszt;
						if (i == x)
						{
							if (x > 0)
							{
								plansza[y][i-1] = -1;
							}
							if (x > 0 and y > 0)
							{
								plansza[y - 1][i - 1] = -1;
							}
							if (x > 0 and y < 9)
							{
								plansza[y + 1][i - 1] = -1;
							}
							if (y > 0)
							{
								plansza[y-1][i] = -1;
							}
							if (y < 9)
							{
								plansza[y+1][i] = -1;
							}

						}
						if (i == (x - 1 + maszt))
						{
							if ((x - 1 + maszt) < 9)
							{
								plansza[y][i+1] = -1;
							}
							if ((x - 1 + maszt) < 9 and y > 0)
							{
								plansza[y-1][i + 1] = -1;
							}
							if ((x - 1 + maszt) < 9 and y < 9)
							{
								plansza[y+1][i + 1] = -1;
							}
							if (y > 0)
							{
								plansza[y-1][i] = -1;
							}
							if (y < 9)
							{
								plansza[y+1][i] = -1;
							}
						}
						else
						{
							if (y > 0)
							{
								plansza[y - 1][i] = -1;
							}
							if (y < 9)
							{
								plansza[y + 1][i] = -1;
							}
						}
					}
					ilosc++;
				}
			}
			else if (kierunek == 2) // w dol
			{
				if ((y - 1 + maszt) <= 9 and sprawdzanie_miejsca(x, y, plansza, kierunek, maszt)==1)
				{
					for (int i = y;i < (y + maszt);i++)
					{
						plansza[i][x] = maszt;
						if (i == y)
						{
							if (y  > 0)
							{
								plansza[i - 1][x] = -1;
							}
							if (y > 0 and x > 0)
							{
								plansza[i - 1][x - 1] = -1;
							}
							if (y > 0 and x < 9)
							{
								plansza[i - 1][x + 1] = -1;
							}
							if (x > 0)
							{
								plansza[i][x - 1] = -1;
							}
							if (x < 9)
							{
								plansza[i][x + 1] = -1;
							}
							
						}
						if (i == (y - 1 + maszt))
						{
							if ((y - 1 + maszt) < 9)
							{
								plansza[i + 1][x] = -1;
							}
							if ((y - 1 + maszt) < 9 and x > 0)
							{
								plansza[i + 1][x - 1] = -1;
							}
							if ((y - 1 + maszt) < 9 and x < 9)
							{
								plansza[i + 1][x + 1] = -1;
							}
							if (x > 0)
							{
								plansza[i][x - 1] = -1;
							}
							if (x < 9)
							{
								plansza[i][x + 1] = -1;
							}
						}
						else
						{
							if (x > 0)
							{
								plansza[i][x - 1] = -1;
							}
							if (x < 9)
							{
								plansza[i][x + 1] = -1;
							}
						}
					}
					ilosc++;
				}
			}
			else if (kierunek == 3) // w lewo
			{
				if ((x + 1 - maszt) >= 0 and sprawdzanie_miejsca(x, y, plansza, kierunek, maszt)==1)
				{
					for (int i = x;i > (x - maszt);i--)
					{
						plansza[y][i] = maszt;
						if (i == x)
						{
							if (x < 9)
							{
								plansza[y][i + 1] = -1;
							}
							if (x < 9 and y > 0)
							{
								plansza[y - 1][i + 1] = -1;
							}
							if (x < 9 and y < 9)
							{
								plansza[y + 1][i + 1] = -1;
							}
							if (y > 0)
							{
								plansza[y - 1][i] = -1;
							}
							if (y < 9)
							{
								plansza[y + 1][i] = -1;
							}

						}
						if (i == (x + 1 - maszt))
						{
							if ((x + 1 - maszt) > 0)
							{
								plansza[y][i - 1] = -1;
							}
							if ((x + 1 - maszt) > 0 and y > 0)
							{
								plansza[y - 1][i - 1] = -1;
							}
							if ((x + 1 - maszt) > 0 and y < 9)
							{
								plansza[y + 1][i - 1] = -1;
							}
							if (y > 0)
							{
								plansza[y - 1][i] = -1;
							}
							if (y < 9)
							{
								plansza[y + 1][i] = -1;
							}
						}
						else
						{
							if (y > 0)
							{
								plansza[y - 1][i] = -1;
							}
							if (y < 9)
							{
								plansza[y + 1][i] = -1;
							}
						}
					}
					ilosc++;
				}
			}
		}
	}
}

void wypisz_cyfry(int plansza[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout.width(3);
			cout.fill(' ');
			cout << plansza[i][j];
		}
		cout << endl;
	}
}

void wypisz_znaki(int plansza[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout.width(3);
			cout.fill(' ');
			if (plansza[i][j] == -1)					cout << "+";
			else if (plansza[i][j] >= 1)
			{
				SetConsoleTextAttribute(hConsole, 4);	//czerowny
														cout << plansza[i][j];  //cout << char(0xDC);
				SetConsoleTextAttribute(hConsole, 15);	//standardowy
			}
			else if (plansza[i][j] ==0)					cout << " ";
		}
		cout << endl;
	}
}

int sprawdzanie_miejsca(int x, int y, int plansza[10][10], int kierunek, int maszt)
{
	if (kierunek == 0)// wgore
		{
			for (int i = y; i > (y - maszt); i--)
			{
				if (plansza[i][x] != 0) return 0;
			}
		}
	else if (kierunek == 1)//w prawo
		{
			for (int i = x; i < (x + maszt); i++)
			{
				if (plansza[y][i] != 0) return 0;
			}
		}
	else if (kierunek == 2)//w dol
		{
			for (int i = y; i < (y + maszt); i++)
			{
				if (plansza[i][x] != 0) return 0;
			}
		}
	else if (kierunek == 3)//w lewo
		{
			for (int i = x; i > (x - maszt); i--)
			{
				if (plansza[y][i] != 0) return 0;
			}
		}
	return 1;
}