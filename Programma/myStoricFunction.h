#include <iostream>
#include <string>
#ifndef MYSTORICFUNCTION_H
#define MYSTORICFUNCTION_H

struct storicoDomande{
	string titoloTest;
	int punteggioEffettuato;
	int punteggioMassimo;
	float voto;
};

struct listStorico{
	storicoDomande stoDom;
	listStorico *nextSto;
	listStorico(){
	};
};

void riempiStoricoDomande(storicoDomande &sd, string titolo, int punteggio, int pMax, float voto);
void printStoricoDomande(storicoDomande sd);
void addListStorico(listStorico *&tail, string titolo, int punteggio, int pMax, float voto);
void stampaStorico(listStorico *head);


void riempiStoricoDomande(storicoDomande &sd, string titolo, int punteggio, int pMax, float voto){
	sd.titoloTest = titolo;
	sd.punteggioEffettuato = punteggio;
	sd.punteggioMassimo = pMax;
	sd.voto = voto;
}


void printStoricoDomande(storicoDomande sd){
	cout << "\tTest: " << sd.titoloTest << endl;
	cout << "\tPunteggio massimo: " << sd.punteggioMassimo << endl << "\tPunteggio effettuato: " << sd.punteggioEffettuato << endl;
	cout << "\tVoto: " << sd.voto << endl << endl;
}

void addListStorico(listStorico *&tail, string titolo, int punteggio, int pMax, float voto){
	listStorico *l = new listStorico();
	riempiStoricoDomande(tail->stoDom, titolo, punteggio, pMax, voto);
	l->nextSto = tail;
	tail = l;
}

void stampaStorico(listStorico *head){
	while(head != NULL){
		if(head->stoDom.titoloTest != ""){
			printStoricoDomande(head->stoDom);
			cout << endl;
		}
		head = head->nextSto;
	}
}




#endif
