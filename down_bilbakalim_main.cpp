#include<iostream>
#include "down_bilbakalim.h"
using namespace std;

//Name: Mucahid Mutluer Number: 152120191072

int main()
{
	srand(time(NULL));
	worter dizin;
	dizin.aday_ekle(dizin.words,dizin.kandidat);
	string gizli = dizin.getirgizli();
	spiel oyun;
	oyun.sethint(false);
	oyun.setkac_dnm(0);
	oyun.oynabakalim(dizin.kandidat, dizin.words, gizli);
	
	system("pause");
	return 0;
}