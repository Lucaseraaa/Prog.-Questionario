#include <iostream>
#include <string>
#include<sstream>
#include"myStructFile.h"
#include"myStructFunction.h"
#include"myStandardFunction.h"
#include"myListFunction.h"
#include"mySceltaFunction.h"
#include"myStoricFunction.h"

using namespace std;

	const int MAXTEST = 10;
	


int main(int argc, char** argv) {
	
	int scelta = 0;
	listStorico headTail;
	listStorico *ptrHeadTail = &headTail;
	headTail.nextSto = NULL;
	lista elenco_di_test[MAXTEST];
	string titoli_di_test[MAXTEST];
	cout << "Benvenuto nell'applicazione!\nMenu:\n";
	 
 


	do{

	
		cout << "1. Creazione questionario\n2. Modifica un modulo\n3. Esecuzione questionario\n4. Calcolo del punteggio\n5. Aggiungi un modulo\n6. Elimina un modulo\n7. Elimina un test\n8. Storico Quiz\n9. Esci\n\n\n";
		do{
			cout << "Scegli il numero relativo all'opzione: ";
			cin >> scelta;
			cout << endl;
		}while(scelta < 1 || scelta > 9);
		
		
		switch(scelta){
			case 1:
				creaQuestionario(elenco_di_test, titoli_di_test);
				break;
			
			case 2:
				modificaDomande(elenco_di_test, titoli_di_test);
				break;

			case 3:
				scegliQuiz(elenco_di_test, titoli_di_test, ptrHeadTail);
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
	}while(scelta != 9);
	

	

	return 0;
}








