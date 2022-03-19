#include <iostream>
#include <string>
#ifndef MYSTRUCTFILE_H
#define MYSTRUCTFILE_H
using namespace std;


struct rispostapunteggio{
	string ris;
	int punteggio;
};

struct risposte{
	rispostapunteggio r[5];
	int rispostaCorretta;	
};

struct domandarisposta{
	string domanda;
	risposte r;
};





#endif
