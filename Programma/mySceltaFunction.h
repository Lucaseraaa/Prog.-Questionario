#include <iostream>
#include <string>
#ifndef MYSCELTAFUNCTION_H
#define MYSCELTAFUNCTION_H
#include"myListFunction.h"
#include"myStoricFunction.h"

void creaQuestionario(lista v_test[], string v_titoli[]);
void printTest(lista v_test[], string v_titoli[]);
void calcoloPunteggio(lista v_test[], string v_titoli[]);
void giocaQuiz(lista v_test[], string v_titoli[], int s, listStorico *&ptr);
void scegliQuiz(lista v_test[], string v_titoli[], listStorico *&ptr);
void modificaDomande(lista v_test[], string v_titoli[]);
void aggiungiUnaDomanda(lista v_test[], string v_titoli[]);
void removeModulo(lista v_test[], string v_titoli[]);
void eliminaUnTest(lista v_test[], string v_titoli[]);
void printStoricoQuiz(listStorico *&ptrHead);
void confrontaRisposte(int vUtente[], int vTest[], int d);


void creaQuestionario(lista v_test[], string v_titoli[]){
	
	int n;
	int k = 0;
	while(v_titoli[k] != ""){
		k++;
	}
	if(k == 9){
		cout << endl << "La memoria dei quiz e' piena" << endl;
		return;
	}
	
	cin.ignore();
	cout << "\n\nBenvenuto nella sezione per creare quiz!\nInserisci il titolo del tuo test: ";
	getline(cin, v_titoli[k]);
	
	
	cout << "\nScegli il numero di domande da inserire: ";
	cin >> n;
	addElenco(v_test[k], n);
	
}

void printTest(lista v_test[], string v_titoli[]){
	int s = 0;
	while(s < 10){
		if(v_titoli[s] != ""){
			cout << s + 1 << ". " << v_titoli[s] << endl << endl;
		}
		s++;
	}
}


void calcoloPunteggio(lista v_test[], string v_titoli[]){
	int t = 0;
	cout << "Punteggio di tutti i test:"<<endl<<endl;
	for(int t = 0; t < 10; t++){
		if(v_titoli[t] != ""){
			cout << "Test: " << v_titoli[t] << endl << "Massimo: " << maxTest(v_test[t])<< endl << "Minimo: "<< minTest(v_test[t]) << endl << endl;
		}
	}
}

void giocaQuiz(lista v_test[], string v_titoli[], int s, listStorico *&ptr){
	int vRisposteCorrette[listLength(v_test[s])];
	int vRisposteUtente[listLength(v_test[s])];
	stringaRisposte(v_test[s], vRisposteCorrette);
	cout << "Benvenuto nel Test: " << v_titoli[s] << "\nTi ricordiamo di rispondere a tutte le " << listLength(v_test[s]) << " domande.";
	cout << "\nPuo essere espressa una sola risposta per domanda, ogni risposta puo essere espressa con un numero da 1 a 5.";
	cout << "\nOgni risposta ha un valore diverso, sta all'utente decidere quale.\nBuon divertimento!\n\n";
	int t = punteggio(v_test[s], vRisposteUtente);
	cout << "\nHai ottenuto un punteggio di " << t << "/" << maxTest(v_test[s]);
	cout << "\nIl tuo voto: " << voto(v_test[s], t) << endl << endl; 
	confrontaRisposte(vRisposteUtente, vRisposteCorrette, listLength(v_test[s]));
	addListStorico(ptr, v_titoli[s], t, maxTest(v_test[s]), voto(v_test[s], t)); 
}

void scegliQuiz(lista v_test[], string v_titoli[], listStorico *&ptr){
	int sce = 0;
	printTest(v_test, v_titoli);
	cout << "Scegli il test da eseguire: ";
	cin >> sce;
	giocaQuiz(v_test, v_titoli, sce - 1, ptr);
}

void modificaDomande(lista v_test[], string v_titoli[]){
	int sMod, scl;
	printTest(v_test, v_titoli);
	cout << "Scegli il test da modificare: ";
	cin >> sMod;
	leggiDomanda(v_test[sMod-1]);
	cout << "Scegli la domanda da modificare: ";
	cin >> scl;
	lista *p = &v_test[sMod-1];
	for(int t = 0; t < scl - 1; t++){
		p = p->nextLista;
	}
	riempiDomandaRisposta(p->valore);
}

void aggiungiUnaDomanda(lista v_test[], string v_titoli[]){
	int sce = 0, pos = 0;
	printTest(v_test, v_titoli);
	cout << "Scegli il test da modificare: ";
	cin >> sce;
	leggiDomanda(v_test[sce-1]);
	do{
		cout << "Scegliere la posizione del nuovo modulo: ";
		cin >> pos;
	}while(pos < 1 || pos > listLength(v_test[sce-1]) + 1);
	addModulo(v_test[sce-1], pos);
	cout << "Domanda aggiunta con successo!" << endl << endl;
}

void removeModulo(lista v_test[], string v_titoli[]){
	int sC = 0, p = 0;
	printTest(v_test, v_titoli);
	cout << "Scegli il test da modificare: ";
	cin >> sC;
	leggiDomanda(v_test[sC-1]);
	do{
		cout << "Scegliere la domanda da eliminare: ";
		cin >> p;
	}while(p < 1 || p > listLength(v_test[sC-1]));
	remModulo(v_test[sC-1], p);
	cout << "Domanda rimossa con successo!" << endl << endl;
}

void eliminaUnTest(lista v_test[], string v_titoli[]){
	int k;
	printTest(v_test, v_titoli);
	do{
		cout << "Scegli il test da eliminare: ";
		cin >> k;
	}while(v_titoli[k-1] == "");
	v_titoli[k-1] = "";
}

void printStoricoQuiz(listStorico *&ptrHead){	
	cout << "Cronologia risposte: " << endl << endl;
	stampaStorico(ptrHead);
}

void confrontaRisposte(int vUtente[], int vTest[], int d){
	int i = 0;
	cout << "Correzione domande: \n\n";
	for(i = 0; i < d; i++) {
		if(vUtente[i] != vTest[i]){
			cout <<"Domanda " << i + 1 << " --> Hai selezionato l'opzione: " << vUtente[i] << ". La risposta corretta era: " << vTest[i] <<endl << endl;   
		}
	}
}



#endif
