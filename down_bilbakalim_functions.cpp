#include<iostream>
#include"down_bilbakalim.h"

using namespace std;

//Name: Mucahid Mutluer Number: 152120191072

worter::worter()
{

	infile.open("words.txt");
	if (!infile)
	{
		cout << "Something bad happened about opening the file!" << endl;
		exit(0);
	}
	else
	{
		cout << "File opened correctly!" << endl;

		infile >> tmp;
		while (infile)
		{
			words.insert(tmp);
			infile >> tmp;
		}
	}
}


int worter::fRand(int fMax, int fMin)
{
	int f = ((rand() % (fMax - fMin)) + fMin);
	return f;
}

void worter::aday_ekle(set<string>& words, vector<string>& adaylar) 
{
	int z, i, j, w;
	string onbellek;
	bool yinele;
	
	for (set<string>::iterator it = words.begin(); it != words.end();++it)
	{
		onbellek = *it;
		yinele = false;
		z = -1;
		for (i = 0; i < onbellek.size(); i++)
		{
			for (j = i + 1; j < onbellek.size(); j++)
			{
				if (onbellek[i] == onbellek[j])
				{
					z = i;
					break;
				}
			}
			if (z != -1)
			{
				yinele = true;
				break;
			}
		}
		if (yinele == false)
		{
			adaylar.push_back(onbellek);
		}
	}
}



string worter::getirgizli()
{
	int subscript = fRand(kandidat.size(), 1);
	return kandidat[subscript];
}




spiel::spiel()
{
	int say_exact = 0;
	int kac_dnm = 0;
	int say_harf = 0;
	char tut;
	int b = 0;
	int j = 0;
	int n = 0;
	bool hint = false;
	bool buyuk = false;
	bool inlist = false;
}

void spiel::sethint(bool h)
{
	hint = h;
}

void spiel::setkac_dnm(int s)
{
	kac_dnm = s;
}


void spiel::oynabakalim(vector<string> &candidates, set<string> &words, string gizli)
{
	string buffer, kutu;
	cout << "xxxxx will give you hint!\n";

	while (1)
	{
		cout << "\nPlease guess the secret word\t";
		cin >> buffer;
		cout << endl;
		say_exact = 0;
		say_harf = 0;
		buyuk = false;
		inlist = false;

		if (gizli.size() > buffer.size())
		{
			buyuk = true;
		}

		if ((gizli == buffer) && (hint == true))
		{
			cout << "Your guess is true: " << buffer << "\n";
			kac_dnm++;
			cout << "You found the word at " << kac_dnm << ".th try by using hint\n";
			break;
		}
		else if ((gizli == buffer) && (hint == false))
		{
			cout << "Your guess is true: " << buffer << "\n";
			kac_dnm++;
			cout << "You found the word at " << kac_dnm << ".th try without hint\n";
			break;
		}

		else
		{
			
			for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
			{
				kutu = *it;
				if((buffer==kutu)||(buffer=="xxxxx"))
				{
				inlist = true;
				break;
				}
			}
			

			if (inlist == false)
			{
				cout << "This word is not in dictionary\n";
			}
			else
			{

				if (buffer == "xxxxx")
				{
					cout << "Hint, secret word is: " << gizli << endl;
					kac_dnm++;
					hint = true;
				}
				else
				{
					cout << "Your guess is wrong.\n";
					if (buyuk == true)
					{
						for (j = 0; j < buffer.size(); j++)
						{
							tut = buffer[j];

							if (gizli[j] == buffer[j])
							{
								say_exact++;
							}
							for (b = 0; b < gizli.size(); b++)
							{
								if (tut == gizli[b])
								{
									say_harf++;
									break;
								}
							}

						}
						kac_dnm++;
					}
					else
					{
						for (j = 0; j < gizli.size(); j++)
						{
							tut = gizli[j];


							if (gizli[j] == buffer[j])
							{
								say_exact++;
							}
							for (b = 0; b < buffer.size(); b++)
							{
								if (tut == buffer[b])
								{
									say_harf++;
									break;
								}
							}
						}
						kac_dnm++;
					}
					cout << "The number of true letters at exact positions: " << say_exact << "\n";
					cout << "The number of true letters at no matter which positions: " << say_harf << "\n";
				}
			}

		}

	}
}