#include <iostream>
#include<sstream>  

#include"myStructFile.h"
#ifndef MYLISTFUNCTION_H
#define MYLISTFUNCTION_H


struct lista{
    domandarisposta valore;
    lista *nextLista = NULL;
    lista(){
    };
};

void addLista(lista *&ptrLista); //Aggiunge un elemento alla lista
void readLista(lista head); //Legge una lista completa
void addElenco(lista &top, int m); //Aggiunge una lista completa
int punteggio(lista head, int vUt[]); //Data una lista, ti fa fare il test con annesso punteggio
int maxPunt(risposte ri); //Ritorna il massimo punteggio di una domanda
int maxTest(lista l); //Ritorna il massimo punteggio di un Test
int minPunt(risposte ri);//Ritorna il minimo punteggio di una domanda
int minTest(lista l); //Ritorna il minimo punteggio di un Test
int listLength(lista l); //Ritorna la lunghezza della lista
float voto(lista l, float punteggio); //Ritorna il voto ottenuto in un test
void leggiDomanda(lista c); //Legge tutte le domande, mettendo un segno
void addModulo(lista &c, int posizione); //Aggiunge un mnodulo alla fine o in mezzo ad un quiz
void remModulo(lista &c, int posizione); //Rimuove una domanda all'interno di un quiz
void stringaRisposte(lista l, int v[]);

void addLista(lista *&ptrLista){
    lista *currentPointer = new lista();
    ptrLista->nextLista = currentPointer;

    // Inserimento valore, modificabile

    riempiDomandaRisposta(ptrLista->valore);

    // Fine inserimento

    currentPointer->nextLista = NULL;
    ptrLista = currentPointer;
}

void readLista(lista head){
    lista *ptrHead = &head;
    while(ptrHead != NULL){

        // Valore in uscita, modificabile

        leggiModulo(ptrHead->valore);

        // Fine uscita
        
		ptrHead = ptrHead->nextLista;
    }
}


void addElenco(lista &top, int m){
    lista *el = &top;
    addLista(el);
    for(int k = 0; k < m-1; k++){
        addLista(el);
    }
}

int punteggio(lista head, int vUt[]){
	int p = 0;
	lista *ptrHead = &head;
	int s;
    for(int t = 0; t < listLength(head); t++){
			leggiModulo(ptrHead->valore);
			do{
				cout << "Inserire la risposta: ";
				cin >> s;
			}while(s < 0 || s > 5);
			if(s != 5){
				p = p + ptrHead->valore.r.r[s-1].punteggio;
			}
			vUt[t] = s;
			ptrHead = ptrHead->nextLista;
	}
    return p;
}


int maxPunt(risposte ri){
	int vMax = ri.r[0].punteggio;
	for(int i = 1; i < 4; i++){
		if(ri.r[i].punteggio > vMax){
			vMax = ri.r[i].punteggio;
		}
	}
	return vMax;
}

int minPunt(risposte ri){
	int vMin = ri.r[0].punteggio;
	for(int i = 1; i < 4; i++){
		if(ri.r[i].punteggio < vMin){
			vMin = ri.r[i].punteggio;
		}
	}
	return vMin;
}

int maxTest(lista l){
	lista *ptr = &l;
	int tMax = 0;
	while(ptr != NULL){
		tMax = tMax + maxPunt(ptr->valore.r);
		ptr = ptr->nextLista;
	}
	return tMax;
}

int minTest(lista l){
	lista *ptr = &l;
	int tMin = 0;
	while(ptr != NULL){
		tMin = tMin + minPunt(ptr->valore.r);
		ptr = ptr->nextLista;
	}
	if(tMin > 0){
		tMin = 0;
	}
	return tMin;
}

int listLength(lista l){
	int lLista = 0;
	lista *p = &l;
	while(p->nextLista != NULL){
		lLista++;
		p = p->nextLista;
	}
	return lLista;
}

float voto(lista l, float punteggio){
	int v_max = maxTest(l);
	int v_min = minTest(l);
	float tuoVoto;
	if (v_min < 0){
		v_max = v_max + -(v_min);
		punteggio = punteggio + (-(v_min));
	}
	tuoVoto = (punteggio * 10) / v_max;
	return tuoVoto;
}


void leggiDomanda(lista c){
	lista *pl = &c;
	for(int i = 0; i < listLength(c); i++){
		cout << i + 1 << ". " << pl->valore.domanda << endl;
		pl = pl->nextLista;		
	}
}

void addModulo(lista &c, int posizione){
	lista *currentPtr = &c;
	if(posizione == 1){
		lista *newL = new lista();
		newL->nextLista = currentPtr->nextLista;
		newL->valore = currentPtr->valore;
		currentPtr->nextLista = newL;
		riempiDomandaRisposta(currentPtr->valore);
	}else if(posizione < listLength(c) + 1 && posizione > 1){
		lista *newL = new lista();
		riempiDomandaRisposta(newL->valore);
		for(int g = 0; g < (posizione-2); g++){
			currentPtr = currentPtr->nextLista;
		}
		newL->nextLista = currentPtr->nextLista;
		currentPtr->nextLista = newL;
	}else{
		while(currentPtr->nextLista != NULL){
			currentPtr = currentPtr->nextLista;
		}
		addLista(currentPtr);
	}
	

}

void remModulo(lista &c, int posizione){
	lista *pLista = &c;
	if(posizione == 1){
		pLista = c.nextLista;
		c = *pLista;
	}else if(posizione > 1 || posizione < listLength(c)){
		for(int k = 0; k < (posizione - 2); k++){
			pLista = pLista->nextLista;
		}
		pLista->nextLista = pLista->nextLista->nextLista; 
	}else{
		for(int k = 0; k < posizione-2; k++){
			pLista = pLista->nextLista;
		}
		pLista->nextLista = NULL;
		delete pLista->nextLista;
	}
}

void stringaRisposte(lista l, int v[]){
	lista *ptraL = &l;
	int k = 0;
	while(ptraL != NULL){
		if(ptraL->valore.domanda != ""){
			v[k] = ptraL->valore.r.rispostaCorretta;
			k++;	
		}
		ptraL = ptraL->nextLista;
	}
}








#endif
