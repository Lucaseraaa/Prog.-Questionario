# Progetto: questionario
### Il progetto ha come scopo la creazione dinamica di questionari a risposta multipla. I gestori dei questionari preparano e gestiscono l'impegno generale richiesto dal test. Il processo prevede la preparazione del questionario e l'impostazione di un processo di revisione e calcolo del risultato.

## *__Menu__*


- [1 Operazioni generali](#operazioni-generali)
	- [1.1 Caratteristiche generali](#11-caratteristiche-generali)
	- [1.2 Menu del questionario](#12-menu-del-questionario)
	- [1.3 Strutture di dati utilizzate](#13-strutture-di-dati-utilizzate)
		- [1.3.1 Struct: domandarisposta](#131-struct-domandarisposta)
		- [1.3.2 Struct: risposte](#132-struct-risposte)
		- [1.3.3 Struct: rispostapunteggio](#133-struct-rispostapunteggio)
	- [1.4 Liste e puntatori](#14-liste-e-puntatori)
		- [1.4.1 Metodi delle liste](#141-metodi-delle-liste)
- [2 Creazione di un questionario](#creazione-di-un-questionario)
	- [2.1 Sovrascrivere un questionario](#21-sovrascrivere-un-questionario)
		- [2.1.1 Titolo](#211-titolo)
		- [2.1.2 Numero di domande](#212-numero-di-domande)
	- [2.2 Struttura del questionario](#22-struttura-del-questionario)
		- [2.2.1 Composizione della lista](#221-composizione-della-lista)
		- [2.2.2 Riempimento di una lista](#222-riempimento-di-una-lista)
	- [2.3 Inserimento della struct domandarisposta](#23-inserimento-della-struct-domandarisposta)
		- [2.3.1 Inserimento domandarisposta](#231-inserimento-domandarisposta)
		- [2.3.2 Inserimento di dati in una lista](#232-inserimento-di-dati-in-una-lista)
- [3 Modifica un modulo](#modifica-un-modulo)
	- [3.1 Scelta del modulo da modificare](#31-scelta-del-modulo-da-modificare)
	- [3.2 Modificare il modulo](#31-modificare-il-modulo)
- [4 Esecuzione questionario](#esecuzione-questionario)
	- [4.1 Selezione e apertura di un questionario](#41-selezione-e-apertura-di-un-questionario)
	- [4.2 Svolgimento di un questionario](#42-svolgimento-di-un-questionario)
		- [4.2.1 Stampa a schermo dei moduli](#421-stampa-a-schermo-dei-moduli)
		- [4.2.2 Richiedere una risposta all'utente](#422-richiedere-una-risposta-allutente)
	- [4.3 Punteggio del questionario](#43-punteggio-del-questionario)
		- [4.3.1 La funzione punteggio](#431-la-funzione-punteggio)
		- [4.3.2 La funzione voto](#432-la-funzione-voto)
		- [4.3.3 Stampa a schermo del punteggio](#433-stampa-a-schermo-del-punteggio)
	- [4.4 Risposte errate](#44-risposte-errate)
		- [4.4.1 La funzione confrontarisposte](#441-la-funzione-confrontarisposte)
		- [4.4.2 Riempire i vettori di risposte](#442-riempire-i-vettori-di-risposte)
			- [4.4.2.1 Risposte esatte](#4421-risposte-esatte)
			- [4.4.2.2 Risposte dell'utente](#4421-risposte-dellutente)
- [5 Calcolo del punteggio](#calcolo-del-punteggio)
	- [5.1 Calcolo del massimo](#51-calcolo-del-massimo)
	- [5.2 Calcolo del minimo](#52-calcolo-del-minimo)
	- [5.3 Stampa dei punteggi](#53-stampa-dei-punteggi)
- [6 Aggiungi un modulo](#aggiungi-un-modulo)
	- [6.1 Scegliere la posizione](#61-scegliere-la-posizione)
	- [6.2 Inserimento dei moduli](#62-inserimento-dei-moduli)
		- [6.2.1 Inserire un modulo all'inizio](#621-inserire-un-modulo-allinizio)
		- [6.2.2 Inserire il modulo in mezzo a due elementi](#622-inserire-il-modulo-in-mezzo-a-due-elementi)
		- [6.2.3 Inserire un modulo alla fine](#623-inserire-il-modulo-alla-fine)
- [Rimuovere un modulo](#rimuovere-un-modulo)
	- [7.1 Scegliere la posizione](#71-scegliere-la-posizione)
	- [7.2 Rimozione di un modulo](#72-rimozione-di-un-modulo)
		- [7.2.1 Eliminare un modulo all'inizio](#721-eliminare-un-modulo-allinizio)
		- [7.2.2 Eliminare un modulo in mezzo a due elementi](#722-eliminare-un-modulo-in-mezzo-a-due-elementi)
		- [7.2.3 Eliminare un modulo alla fine](#723-eliminare-un-modulo-alla-fine)
- [Elimina un test](#elimina-un-test)
	- [8.1 Eliminare un test](#81-eliminare-un-test)
- [Storico del test](#storico-del-test)
	- [9.1 Strutture necessarie](#91-strutture-necessarie)
	- [9.2 Aggiungere liste e riempirle](#92-aggiungere-liste-e-riempirle)
		- [9.2.1 Aggiungere una lista](#921-aggiungere-una-lista)
		- [9.2.2 Riempire i parametri](#922-riempire-i-parametri)
	- [9.3 Visualizzare le storico](#93-visualizzare-lo-storico)
---

# Operazioni generali
## 1.1 Caratteristiche generali
L'applicazione da la possibilita di creare un massimo di 10 test, ognuno con un numero di domande potenzialmente infinito. Ogni domanda può contenere 5 risposte, ognuna con un punteggio variabile (che può essere scelto dall'utente), tranne la numero 5, la quale ha un punteggio di 0 e contientiene la `stringa` "Non so rispondere".

## 1.2 Menu del questionario
Il questionario, una volta avviata l'applicazione `Progetto.exe` (nella cartella `Questionario`), si presenta nel seguente modo:


```
Benvenuto nell`applicazione
Menu:
1. Creazione questionario
2. Modifica un modulo
3. Esecuzione questionario
4. Calcolo del punteggio
5. Aggiungi un modulo
6. Elimina un modulo
7. Elimina un test
8. Storico quiz
9. Esci

Scegli il numero relativo all`opzione:
```
In questo momento l'applicazione __si aspetta in input un numero intero da 1 a 9__, a seconda della voce che vogliamo selezionare. Nel caso in cui il numero selezionato fosse al di fuori di questo range, l'applicazione richiederebbe in input un numero. Nel caso in cui venisse selezionato un numero valido, l'applicazione eseguirebbe ciò che è scritto nell'opzione selezionata. Una volta terminato, il menù ricomparira, fino a quando non si uscirà da esso, tramite il tasto "9". Il ciclo che ci permette di farlo è il *__ciclo do while__* qua sotto riportato:
```cpp
cout << "1. Creazione questionario\n2. Modifica domande\n3. Esecuzione questionario\n4. Calcolo del punteggio\n5. Aggiungi un modulo\n6. Elimina un modulo\n7. Elimina un test\n8. Esci\n\n\n";
		do{
			cout << "Scegli il numero relativo all'opzione: ";
			cin >> scelta;
			cout << endl;
		}while(scelta < 1 || scelta > 8);
		
		switch(scelta){
			case 1:
				creaQuestionario(elenco_di_test, titoli_di_test);
				break;
			
			case 2:
				modificaDomande(elenco_di_test, titoli_di_test);
				break;
				
			case 3:
				scegliQuiz(elenco_di_test, titoli_di_test);
				break;
			
			case 4:
				calcoloPunteggio(elenco_di_test, titoli_di_test);
				break;

			case 5:
				aggiungiUnaDomanda(elenco_di_test, titoli_di_test);
				break;
			case 6:
				removeModulo(elenco_di_test, titoli_di_test);
				break;
			
			case 7:
				eliminaUnTest(elenco_di_test, titoli_di_test);
				break;
			
			
			case 8: 
				printStoricoQuiz(ptrHeadTail);
				break;
			
			default:
				break;	
		}
	}while(scelta != 8);
```

## 1.3 Strutture di dati utilizzate
Per caricare nostre domande abbiamo bisogno di un nuovo tipo di dato: `domandarisposta`.


### 1.3.1 Struct: domandarisposta
La struttra `domandarisposta` contiene la `stringa` "domanda", che contiene la domanda al modulo e la struct `risposte` "r".
```cpp
struct domandarisposta{
	string domanda;
	risposte r;
};
```


### 1.3.2 Struct: risposte
La struttura `risposte`, contiene la variabile `int` "rispostaCorretta", che indica la risposta corretta, mentre il vettore di struct `rispostapunteggio` "r[5]".
```cpp
struct risposte{
	rispostapunteggio r[5];
	int rispostaCorretta;	
};
```

### 1.3.3 Struct: rispostapunteggio
La struttura `rispostapunteggio` contiene due variabili `stringa` "ris", che indica il contenuto della risposta e il valore `int` "punteggio", che contiene il punteggio della domanda.


## 1.4 Liste e puntatori
Per creare una serie di domande, utilizziamo una `lista`, una struttura dinamica di dati con la quale possiamo creare una serie di moduli consecutivi, terminando con la creazione di un test. La `lista` contiene due valori ed un costruttore.

```cpp
struct lista{
    domandarisposta valore;
    lista *nextLista = NULL;
    lista(){
    };
};
```
Il primo valore è la struct `domandarisposta` "valore" e contiene un modulo, vi è poi il puntatore alla lista successiva `lista* ` "nextLista" ed un costruttore, in grado di creare delle classi dalle struct.

### 1.4.1 Metodi delle liste
Le liste contengono una serie di metodi qui sotto riportati

```cpp
void addLista(lista *&ptrLista); //Aggiunge un elemento alla lista

void readLista(lista head); //Legge una lista completa

void addElenco(lista &top, int m); //Aggiunge una lista completa

int punteggio(lista head); //Data una lista, ti fa fare il test con annesso punteggio

int maxTest(lista l); //Dato in input l'head di una lista, ritorna il massimo punteggio di un Test

int minTest(lista l); //Dato in input l'head di una lista, ritorna il minimo punteggio di un Test

int listLength(lista l); //Dato in input l'head di una lista, ritorna la lunghezza della lista

float voto(lista l, float punteggio); //Dato in input l'head di una lista e il punteggio, ritorna il voto ottenuto in un test

void leggiDomanda(lista c); //Legge tutte le domande, mettendo un segno

void addModulo(lista &c, int posizione); //Aggiunge un modulo all'interno di un quiz

void remModulo(lista &c, int posizione); //Rimuove una domanda all'interno di un quiz
```
Oguno di questi metodi permette di modificare una lista e compiere operazioni su di essa.

---
# Creazione di un questionario


## 2.1 Sovrascrivere un questionario
Per creare il questionario necessitiamo di un titolo e di un numero di domande precedentemente stabilto, in futuro modificabile (vedi modifica, eliminazione). Il test verrà sovrascritto in un apposito vettore, il quale verrà scorso nelle varie posizioni, fino a cercarne una libera per l'inserimento del test.
### 2.1.1 Titolo 
Il questionario verrà fornito di un titolo, che verrà inserito nel vettore dei titoli

```bash
Benvenuto nella sezione per creare quiz!
Inserisci il titolo del tuo test:
```
al quale corrisponde il seguente codice `c++`:
```cpp
cout << "\n\nBenvenuto nella sezione per creare quiz!\nInserisci il titolo del tuo test: ";
getline(cin, v_titoli[k]);
```
### 2.1.2 Numero di domande
Il numero di domande può essere infinito e sarà necessario indicarlo

```bash
Scegli il numero di domande da inserire: 
```
al quale corrisponde il seguente codice `c++`:
```cpp
cout << "\nScegli il numero di domande da inserire: ";
cin >> n;
```
## 2.2 Struttura del questionario
Il questionario è quindi formato da un titolo, associato ad una lista con n elementi (il numero di domande). Per crearlo abbiamo bisogno di alcune funzioni
### 2.2.1 Composizione della lista
Per creare una lista utilizzeremo una funzione del file `myListFunction.h`: addElenco. Tramite questa funzione, utilizzando un ciclo for, verranno create diverse liste (di un numero corrispondente a quello scelto dall'utente) e collegate l'una all'altra.
>La funzione addElenco(lista &top, int m) necessita di due parametri: l'indirizzo della lista da cui partire, e il numero di domdande da inserire.

```cpp
void addElenco(lista &top, int m){
    lista *el = &top;
    addLista(el);
    for(int k = 0; k < m-1; k++){
        addLista(el);
    }
}
```
La funzione, a partire dalla testa della lista, aggiunge tante liste quante indicate dall'utente (cioè m - 1, perchè la prima lista è quella di partenza).

### 2.2.2 Riempimento di una lista
Per riempire una lista necessitiamo della funzione del file `myListFunction.h`: addLista. A partire da questa funzione, verrà inizializzata una nuova lista, e l'ultima presente nella nostra struttura verrà riempita(tramite la funzione riempiDomandaRisposta). Infine il parametro nextLista, verrà indirizzato verso la lista inizializzata.
>La funzione addLista(lista *ptrLista) richiede un solo parametro, ossia il puntatore alla testa della struct lista.  
```cpp
void addLista(lista *&ptrLista){
    lista *currentPointer = new lista();
    ptrLista->nextLista = currentPointer;

    // Inserimento valore, modificabile

    riempiDomandaRisposta(ptrLista->valore);

    // Fine inserimento

    currentPointer->nextLista = NULL;
    ptrLista = currentPointer;
}
```
## 2.3 Inserimento della struct domandarisposta
Per riempire il valore di una lista, verranno utilizzate tre funzioni, allo scopo di riempire le struct che la costituiscono
### 2.3.1 Inserimento domandarisposta
La struct che è contenuta nel valore di una lista è `domandarisposta` ed è riempita tramite un'apposita funzione del file `myStructFunction.h`: riempiDomandaRisposta. Tramite essa è possibile riempire i vari campi della variabile riempiDomandaRisposta. All'interno di questa funzione ne sono racchiuse altre due per ottimizzare il codice.
>La funzione riempiDomandaRisposta(domandarisposta &dr) necessita un parametro di tipo domandarisposta.
```cpp
void riempiDomandaRisposta(domandarisposta &dr){
	cout << "\nInserisci un modulo:\n";
	cin.ignore();
	cout << "Inserisci domanda: ";
	getline(cin, dr.domanda);
	riempiRisposte(dr.r);
}
```
### 2.3.2 Inserimento di dati in una lista
L'utente avrà quindi la possibilità di inserire una domanda e 4 opzioni, sempre grazie alla funzione del paragrafo precedente. In primo luogo si avrà la possibilità di inserire la domanda.
```bash
Inserisci un modulo:
Inerisci domanda: 
```
Successivamente, per 4 volte, verranno chieste le possibili opzioni e il punteggio ad esse associato.
```
Risposta numero n:
Inserisci la risposta:
Inserisci il punteggio:
```
Infine, verrà chiesta la risposta corretta (valore da 1 a 4).
```bash
Inserisci la risposta corretta: 
``` 
---
# Modifica un modulo
## 3.1 Scelta del modulo da modificare
L'applicazione permette di modificare un modulo una volta inserito all'interno di un quiz.
Inizialmente, per scegliere il modulo da modificare, viene utilizzata una funzione del file `mySceltaFunction`: printTest, la quale stampa tutti i nomi dei quiz.
>La funzione printTest(lista v_test[], string v_titoli[]) necessita di due parametri: la lista dei quiz e quella dei titoli
```cpp
void printTest(lista v_test[], string v_titoli[]){
	int s = 0;
	while(s < 10){
		if(v_titoli[s] != ""){
			cout << s + 1 << ". " << v_titoli[s] << endl << endl;
		}
		s++;
	}
}
```
La quale genera un output del genere:
```bash
1. Test 1

2. Test 2

3. Test 3

Scegli il test da modificare:
```
In questo momento la nostra console si aspetta in input il numero corrispondente al test da modificare. Una volta selezionato il test, viene inserito come argomento della funzione leggiDomanda, la quale manda in output tutti i moduli di quest'ultimo. 
```cpp
void leggiDomanda(lista c){
	lista *pl = &c;
	for(int i = 0; i < listLength(c); i++){
		cout << i + 1 << ". " << pl->valore.domanda << endl;
		pl = pl->nextLista;		
	}
}
```
La quale genera un output del genere:
```bash
1. Domanda 1
2. Domanda 2
3. Domanda 3
4. Domanda 4
Scegli la domanda da modificare: 
```
L'utente deve selezionare la domanda da modificare, di modo da azzerare il modulo ad essa corrispondente e riempirlo da capo.

## 3.2 Modificare il modulo
Una volta arrivati a scegliere il modulo da modificare, verrà creato un puntatore che punterà alla lista con il modulo che desideraimo modificare. Questo verrà raggiunto tramite un ciclo for:
```cpp
for(int t = 0; t < scl - 1; t++){
	p = p->nextLista;
}
```
Una volta arrivati ad esso, tramite la funzione già citata [riempiDomandaRisposta](#231-inserimento-domandarisposta) sarà possibile modificare il modulo selezionato.


---
# Esecuzione questionario

## 4.1 Selezione e apertura di un questionario
Tramite la precedentemente citata funzione [printTest](#31-scelta-del-modulo-da-modificare) è possibile mostrare i questionari che possono essere selezionati per l'esecuzione e tramite un semplice cin è possibile, di fatto, selezionare il questionario da eseguire.

## 4.2 Svolgimento di un questionario
La parte a seguito mostra il modo in cui i moduli di un questionario (creati prima agg link), vegnono stampati a schermo ed eseguiti.
### 4.2.1 Stampa a schermo dei moduli
Una volta selezionato il questionario, previa breve introduzione, verranno visualizzati i moduli delle domande tramite la funzione `leggiModulo`, ripetuta tante volte quanto il numero di moduli nel test selezionato (coadiuvata da un ciclo for). Riporto a seguito la precedentemente citata funzione:
>La funzione leggiModulo(domandarisposta mod) richiede un parametro: una struct `domandarisposta`, essa è racchiusa nella funzione punteggio, spiegata più avanti 
```cpp
void leggiModulo(domandarisposta mod){
	char vettOpzioni[4] = {'1', '2', '3', '4'};
	cout << endl << mod.domanda << endl << endl;
	for(int k = 0; k < 4; k++){
		cout << vettOpzioni[k] << ". " << mod.r.r[k].ris << endl;
	}
	cout << "5. Non so rispondere" << endl;
}
```
Essa, considerando un esempio, mostra un output di questo tipo
```bash
Di che colore era il cavallo bianco di Napoleone?

1. Nero
2. Bianco
3. Rosso
4. Blu
5. Non so rispondere
Inserire la risposta: 
```
### 4.2.2 Richiedere una risposta all'utente
Una volta che è stato stampato il modulo, viene chiesto all'utente una risposta da selezionare. La risposta deve sottostare ad alcune caratteristiche: essere di tipo numerico intero ed essere compresa tra 1 e 5. La risposta è presa tramire un cin, successivamente verrà spiegato il modo in cui gli si attribuiscono i punti

## 4.3 Punteggio del questionario
Una volta terminato, il questionario stamperà a schermo il punteggio ottenuto dall'utente rispetto al punteggio massimo e il voto ad esso attribuito.
### 4.3.1 La funzione punteggio
La funzione che permette di calcolare il punteggio è la funzione `punteggio`, la quale, oltre a stampare a schermo le domande permette di calcolare il punteggio effettuato dall'utente. Viene inizializzata la variabile p, che parte da zero e alla quale vengono aggiunti o sottratti i punti corrispondenti all'opzione scelta dall'utente. La funzione è la seguente:
```cpp
int punteggio(lista head, int vUt[]){
	int p = 0;
	lista *ptrHead = &head;
	int s;
    for(int t = 0; t < listLength(head); t++){
			leggiModulo(ptrHead->valore);
			do{
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
```
### 4.3.2 La funzione voto
Una volta ottenuto il punteggio, è necessario conoscere il voto ottenuto nella prova. Per questo viene utilizzata la funzione `voto`, la quale ha la funzione di restituire un voto di tipo float corrispondente alla risultato ottenuto nella prova. La funzione ottiene i valori massimi e minimi possibili della prova e la loro somma in valori assoluti corrisponde al massimo punteggio ottenibile nella prova. Nel caso in cui il punteggio minimo sia minore di 0, al punteggio verrà aggiunto il valore assoluto del voto minimo. La funzione è la seguente:

```cpp
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
```

Infine, il voto si ottiene dividendo per il valore massimo del test il punteggio dell'utente moltiplicato per 10.

### 4.3.3 Stampa a schermo del punteggio
Una volta terminato il test, grazie alle funzioni precedentemente elencate, verrà stampato a schermo una risposta del genere:

```bash
Hai ottenuto un punteggio di 17/20
Il tuo voto: 8.5
```
In questo caso il punteggio ottenuto è di 17 su 20, con un relativo voto di 8.5.

## 4.4 Risposte errate
Nel caso si commettessero errori nei test, verrà eseguita la correzione del test. Verranno indicate le risposte errate, con le rispettive risposte corrette le quali si avrebbe dovuto selezionare.
### 4.4.1 La funzione confrontarisposte
Per fare ciò è necessaria la funzione `confrontarisposte`, la quale verifica le risposte corrette e quelle sbagliate
>La funzione confrontaRisposte(int vUtente[], int vTest[], int d) richiede tre parametri: le risposte dell'utente, quelle corrette e il numero di risposte del quiz.

La funzione, rivcevendo i suoi parametri, controllerà se le risposte fornite dall'utente e quelle corrette siano uguali, nel caso contrario manderà in out la risposta dell'utente, con conseguente correzione. La funzione:

```cpp
void confrontaRisposte(int vUtente[], int vTest[], int d){
	int i = 0;
	cout << "Correzione domande: \n\n";
	for(i = 0; i < d; i++) {
		if(vUtente[i] != vTest[i]){
			cout <<"Domanda " << i + 1 << " --> Hai selezionato l'opzione: " << vUtente[i] << ". La risposta corretta era: " << vTest[i] <<endl << endl;   
		}
	}
}
```
Che genera il seguente tipo di output

```
Domanda 1 --> Hai selezionato l'opzione: 3. La risposta corretta era 1.

Domanda 5 --> Hai selezionato l'opzione: 2. La risposta corretta era 3.
```
### 4.4.2 Riempire i vettori di risposte
Per passare i precedenti parametri alla funzione confrontaRisposte è necessario riempire due vettori: uno con le risposte corrette, l'altro con quelle selezionate dall'utente.

#### 4.4.2.1 Risposte esatte
Per riempire il vettore delle risposte esatte viene utilizzata la funzione `stringaRisposte`, la quale scorre tutte le liste di un test, selezionando la risposta corretta (in forma numerica). Segue il codice:
```cpp
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
```

#### 4.4.2.1 Risposte dell'utente
La funzione che riempie le risposte dell'utente si trova all'interno di [punteggio](#43-punteggio-del-questionario), ogni volta che una risposta viene data dall'utente, viene salvata nel vettore corrispondente.

---
# Calcolo del punteggio
Tramite questa funzione è possibile ottenere tutti i punteggi dei test creati: massimi e minimi. Infine questi valori vengono mandati in out tramite una funzione generica.
## 5.1 Calcolo del massimo
Per calcolare il massimo punteggio di un test si utilizza la funzione `maxTest`, la quale riceve come input un test e permette di ottenere il massimo punteggio che si può fare. Questo avviene tramite lo scorrimento della lista, e la somma dei punteggi massimi. 

```cpp
int maxTest(lista l){
	lista *ptr = &l;
	int tMax = 0;
	while(ptr != NULL){
		tMax = tMax + maxPunt(ptr->valore.r);
		ptr = ptr->nextLista;
	}
	return tMax;
}
```
La funzione ritorna un valore di tipo intero: il punteggio massimo.

## 5.2 Calcolo del minimo
Contraria alla precedente maxTest, vi è la funzione `minTest`, la quale riceve una lista (che scorre) e ne ricava il minimo punteggio che si può ottenere. Anche in questo caso viene ritornato un valore intero che corrisponde al minimo del test.

```cpp
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
```

## 5.3 Stampa dei punteggi
Grazie alle due funzioni elencate precedentemente è possibile ottenere i punteggi di tutti i test creati. Per fare ciò viene utilizzato un ciclo for, che permette di scorrere tutte le posizioni del vettore conteneti un test, e conseguentemente anche un titolo.

```cpp
for(int t = 0; t < 10; t++){
		if(v_titoli[t] != ""){
			cout << "Test: " << v_titoli[t] << endl << "Massimo: " << maxTest(v_test[t])<< endl << "Minimo: "<< minTest(v_test[t]) << endl << endl;
		}
	}
```
Tramite il ciclo, viene madato in output il nome del test, il punteggio massimo e minimo. Segue un esempio

```
Punteggio di tutti i test:

Test: Test di storia
Massimo: 100
Minimo -10

Test: Test di biologia
Massimo :10
Minimo: 0

Test: Test di storia
Massimo: 25
Minimo: -5
```
---
# Aggiungi un modulo
Nel test è possibile inserire altri moduli rispetto a quelli inseriti inizialmente. Tutto ciò è possibile tramite la funzione `aggiungiUnaDomanda`. 
## 6.1 Scegliere la posizione
Inizialmente, viene fatto scegliere un test, elencandoli tutti. Tramite la funzione precedentemente descritta `leggiDomanda` è possibile scegliere una domanda dato il suo indice. In questo modo si ha possibilità di scegliere una posizione dove inserire il nuovo modulo del test. Segue un esempio di scelta:
```
1. Domanda 1
2. Domanda 2
3. Domanda 4
4. Domanda 5

Scegli la posizione del nuovo modulo:
```
In questo caso, scegliendo un numero, il nuovo modulo avrà la posizione del numero scelto, e la domanda che attualmente lo occupa verrà automaticamente fatta scalare di una posizione in avanti.
## 6.2 Inserimento dei moduli
Una volta scelto il numero sarà possibile inserire un nuovo modulo, creato tramite la funzione addLista e riempiDomandaRisposta. Per inserire i moduli viene utilizzata la funzione `addModulo`.
>La funzione addModulo(lista &c, int posizione) prende due parametri: la "testa" della lista e la posizione dove inserire il nuovo modulo.
```cpp
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
```
Il modulo potrebbe essere inserito in tre situazioni diverse: all'inizio della lista, in mezzo alla lista oppure alla fine. Seguono i tre modi per inserirli.
### 6.2.1 Inserire un modulo all'inizio
Nel caso in cui il modulo venga inserito nella posizione numero 1, viene creata una nuova lista, inserito il nuovo modulo al suo interno e, a seguire, il suo puntatore punta alla prima lista del test selezionato.
```cpp
    lista *newL = new lista();
    newL->nextLista = currentPtr->nextLista;
    newL->valore = currentPtr->valore;
    currentPtr->nextLista = newL;
    riempiDomandaRisposta(currentPtr->valore);
```
### 6.2.2 Inserire il modulo in mezzo a due elementi
Nel caso in cui si voglia inserire il modulo tra due elementi, è possibile creare un nuovo modulo e riempirlo con i valori. La nuova lista, verrà puntata dal puntatore della lista precedente e punterà alla lista successiva.
```cpp
    lista *newL = new lista();
	riempiDomandaRisposta(newL->valore);
	for(int g = 0; g < (posizione-2); g++){
		currentPtr = currentPtr->nextLista;
	}
	newL->nextLista = currentPtr->nextLista;
	currentPtr->nextLista = newL;
```
### 6.2.3 Inserire il modulo alla fine
Con un metodo analogo ai due precedenti, è possibile inserire un modulo all'interno di una lista, e puntare l'ultimo elemento del test alla nuova lista creata. 
```cpp
    while(currentPtr->nextLista != NULL){
		currentPtr = currentPtr->nextLista;
	}
	addLista(currentPtr);
```
---
# Rimuovere un modulo
Nell'applicazione è possibile rimuovere un modulo, per poi passare direttamente al modulo successivo. 
## 7.1 Scegliere la posizione
Analogamente al capitolo precedente, è possibile scegliere la posizione in cui eliminare il modulo. Tramite la funzione  `leggiDomanda` è possibile stampare a schermo tutti i moduli di un determinato quiz. Una volta scelto sarà possibile eliminarlo in tre diversi metodi, a seconda della posizione.
```
1. Domanda 1
2. Domanda 2 
3. Domanda 3
4. Domanda 4

Scegliere la domanda da eliminare:
```
## 7.2 Rimozione di un modulo
La funzione `remModulo` elimina un modulo "staccandolo" dalla lista del test, e facendo puntare la precedente alla successiva. Quest'ultimo assume un comportamento diverso a seconda della posizione del modulo
>La funzione remModulo(lista &c, int posizione) accetta due parametri: la lista in cui eliminare il modulo e la posizione del modulo da eliminare
```cpp
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
```
### 7.2.1 Eliminare un modulo all'inizio
Nel caso in cui si voglia eliminare il primo modulo, il puntatore al primo modulo assumerà il valore del secondo modulo, e conseguentemente, il secondo modulo diventerà il primo.
```cpp
pLista = c.nextLista;
c = *pLista;
```
### 7.2.2 Eliminare un modulo in mezzo a due elementi
Nel caso in cui si voglia eliminare un modulo in mezzo a due elementi, è possibile far puntare il puntatore del modulo precedente di quello selezionato al successivo di quest'ultimo, di modo che il selezionato ne rimanga escluso, eliminandosi. 
```cpp
for(int k = 0; k < (posizione - 2); k++){
	pLista = pLista->nextLista;
}
	pLista->nextLista = pLista->nextLista->nextLista;
```
### 7.2.3 Eliminare un modulo alla fine
Per eliminare un modulo alla fine del quiz, semplicemente, è possibile far puntare a "NULL" il puntatore del penultimo modulo.
```cpp
for(int k = 0; k < posizione-2; k++){
	pLista = pLista->nextLista;
	}
pLista->nextLista = NULL;
delete pLista->nextLista;
```
# Elimina un test
E' inoltre possibile eliminare direttamente un test intero eliminandone il titolo nel vettore dei titoli.
## 8.1 Eliminare un test
Il procedimento è molto semplice e fattibile da una sola funzione: `eliminaUnTest` . In questo caso la funzione scorrerà il vettore dei titoli fino a quello designato, impostandolo a vuoto. In questo modo, mentre la funzione leggerà i titoli per verificare la presenza di un test, non lo troverà e lo sovrascriverà

---
# Storico del test 
Nell'applicazione, è possibile ottenere lo storico dei risultati dei quiz che sono stati eseguiti. Tramite questa voce, è possibile risalire al test effettuato, al numero di risposte esatte e al voto preso, tutto in ordine cronologico.

## 9.1 Strutture necessarie
Per creare questa funzionalità sono necessarie due strutture: quella specifica dello storico domande e quella della lista che le contiene. La prima contiene i seguenti campi: 
```cpp
struct storicoDomande{
	string titoloTest;
	int punteggioEffettuato;
	int punteggioMassimo;
	float voto;
};
```
La struct contiene il titolo del test, il punteggio effettuato, il punteggio massimo e il voto.
La seconda, invece, è una semplice lista che contiene una variabile di tipo `storicoDomande` come valore. 
```cpp
struct listStorico{
	storicoDomande stoDom;
	listStorico *nextSto;
	listStorico(){
	};
};
```
## 9.2 Aggiungere liste e riempirle
Tramite due funzioni: `addListStorico` e `riempiStoricoDomande` è possibile riempire le liste che porteranno a creare lo storico delle domande all'interno dell'applicazione. 

### 9.2.1 Aggiungere una lista
Per aggiungere una lista, viene utilizzata la funzione void addListStorico ogni volta che un test viene completato. La sintassi è la seguente:
```cpp
void addListStorico(listStorico *&tail, string titolo, int punteggio, int pMax, float voto){
	listStorico *l = new listStorico();
	riempiStoricoDomande(tail->stoDom, titolo, punteggio, pMax, voto);
	l->nextSto = tail;
	tail = l;
}
```
La funzione ha circa la stessa modalità di utilizzo della funzione [addLista](#222-riempimento-di-una-lista).

### 9.2.2 Riempire i parametri
Tramite la funzione riempiStoricoDomande è possibile riempire i parametri della struct listStorico. 
```cpp
void riempiStoricoDomande(storicoDomande &sd, string titolo, int punteggio, int pMax, float voto){
	sd.titoloTest = titolo;
	sd.punteggioEffettuato = punteggio;
	sd.punteggioMassimo = pMax;
	sd.voto = voto;
} 
```
Vengono presi come parametri il titolo, punteggio, punteggio massimo e voto e vengono inseriti all'interno della variabile della struct corrispondente.

## 9.3 Visualizzare lo storico
Tramite la funzione `stampaStorico` è possibile stampare lo storico dei test effettuati, con annessi parametri precedentemente citati. La funzione è la seguente:
```cpp
void stampaStorico(listStorico *head){
	while(head != NULL){
		if(head->stoDom.titoloTest != ""){
			printStoricoDomande(head->stoDom);
			cout << endl;
		}
		head = head->nextSto;
	}
}
```
Tramite questa funzione, vengono stampati sullo schermo, in ordine cronologico, tutti gli storici dei punteggi dei test effettuati.
La stampa è fatta dalla funzione `printsStoricoDomande`
```cpp
void printStoricoDomande(storicoDomande sd){
	cout << "\tTest: " << sd.titoloTest << endl;
	cout << "\tPunteggio massimo: " << sd.punteggioMassimo << endl << "\tPunteggio effettuato: " << sd.punteggioEffettuato << endl;
	cout << "\tVoto: " << sd.voto << endl << endl;
}
```
Da esse risulta un output del genere:
```
Test: test 1
Punteggio massimo: 100
Punteggio effettuato: 95
Voto: 9.5

Test: test 1
Punteggio massimo: 100
Punteggio effettuato: 95
Voto: 9.5

Test: test 2
Punteggio massimo: 50
Punteggio effettuato: 15
Voto: 3.0
```
