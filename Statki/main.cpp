#include <iostream>
#include <random>

using namespace std;

void ustaw_statki(int plansza[10][10]);
void wypisz(int plansza[10][10]);

int main()
{
	int plansza[10][10]{ 0 };

		ustaw_statki(plansza);
		wypisz(plansza);



	//system("PAUSE");
}


void ustaw_statki(int plansza[10][10])
{
	random_device ziarno;
	mt19937 losowa(ziarno());
	uniform_int_distribution<int> zakres_plansza(0, 9);
	uniform_int_distribution<int> zakres_kierunek(0, 3);

	//int x = 1;
	//int y = 9;
	//int kierunek = 3;

	for (int maszt = 4; maszt > 3; maszt--)
	{
		for (int ilosc = 1;ilosc < (6 - maszt);)
		{
			int x = zakres_plansza(losowa);
			int y = zakres_plansza(losowa);
			int kierunek = zakres_kierunek(losowa);
					
			
			if (kierunek == 0) //w gore
			{
				if (y+1 - maszt >= 0)
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
				if (x - 1 + maszt <= 9)
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
				if (y - 1 + maszt <= 9)
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
				if (x + 1 - maszt >= 0)
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

void wypisz(int plansza[10][10])
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