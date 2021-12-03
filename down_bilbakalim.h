#ifndef mutluer_bilbakalim
#define mutluer_bilbakalim
#include <iostream>
#include<fstream>
#include<iomanip>
#include <vector>
#include <string>
#include<cstdlib>
#include<set>
#include<ctime>
using namespace std;

//Name: Mucahid Mutluer Number: 152120191072

class worter
{
public:

	ifstream infile;
	set<string> words;
	vector<string> kandidat;
	string tmp;
	worter();
	//~worter();
	int fRand(int fMax, int fMin);
	void aday_ekle(set<string>& words, vector<string>& adaylar);
	//int cable_ara(vector<string> &kandidat); //bu fonksiyonu test amacli yazmis idim
	//set<string> getwords();
	//vector<string> getkandidat();
	string getirgizli();



};

class spiel
{
public:
	int say_exact;
	int kac_dnm;
	int say_harf;
	char tut;
	int b;
	int n;
	int j;
	bool hint;
	bool buyuk;
	bool inlist;
	spiel();
	void sethint(bool);
	void setkac_dnm(int);
	void oynabakalim(vector<string> &candidates, set<string> &words, string gizli);


};

#endif // !1

