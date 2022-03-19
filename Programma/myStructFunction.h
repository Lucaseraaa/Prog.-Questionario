#include <iostream>
#include <string>
#include"myStandardFunction.h"
#ifndef MYSRTUCTFUNCTION_H
#define MYSRTUCTFUNCTION_H

using namespace std;

void riempiRispostaPunteggio(rispostapunteggio &v); //Riempie una struct: "rispostapunteggio"
void riempiRisposte(risposte &c); //Riempie la struct: "risposte"
void riempiDomandaRisposta(domandarisposta &dr); //Riempie la struct: "domandarisposta"
void riempiQuiz(domandarisposta quizVett[], int sizeVett); //Riempie un quiz
void leggiModulo(domandarisposta mod); //Legge un modulo di una domanda
void punteggioQuiz(domandarisposta drQuiz[], int lenArr); //Ritorna il punteggio di un quiz


void riempiRispostaPunteggio(rispostapunteggio &v){
	
	cout << "Inserisci la risposta: ";
	getline(cin, v.ris);
	cout << "Inserisci il punteggio: ";
	cin >> v.punteggio;
	cin.ignore();
}

void riempiRisposte(risposte &c){
	for (int i = 0; i < 4; i++){
		cout << "\nRisposta numero " << i + 1 << ":\n";
		riempiRispostaPunteggio(c.r[i]);
	}
	c.r[4].ris = "Non rispondere";
	c.r[4].punteggio = 0; 
	
	cout << "\nInserisci la risposta corretta: ";
	do{
	cin >> c.rispostaCorretta;
	}while(c.rispostaCorretta < 0 || c.rispostaCorretta >= 5);
}

void riempiDomandaRisposta(domandarisposta &dr){
	cout << "\nInserisci un modulo:\n";
	cin.ignore();
	cout << "Inserisci domanda: ";
	getline(cin, dr.domanda);
	riempiRisposte(dr.r);
}



void leggiModulo(domandarisposta mod){
	char vettOpzioni[4] = {'1', '2', '3', '4'};
	cout << endl << mod.domanda << endl << endl;
	for(int k = 0; k < 4; k++){
		cout << vettOpzioni[k] << ". " << mod.r.r[k].ris << endl;
	}
	cout << "5. Non so rispondere" << endl;
}









#endif
