#include <iostream>
#include <string>
#ifndef MYSTANDARDFUNCTION_H
#define MYSTANDARDFUNCTION_H

int associaLettera(char vettChar[], char lett){
	int i = 0;
	while(i < (sizeof(vettChar)/sizeof(*vettChar))){
		if(lett == vettChar[i]){
			return i;
		}
		i++;
	}
}




















#endif
