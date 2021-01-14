#include <iostream>
using namespace std;

int menu(){
  	
  	int scelta;
	char tmp[1024];
  	do{
	cout << "scegli:" << endl;
	cout << "1) scrivi su agenda" <<
	endl << "2) leggi agenda" <<
	endl << "3) apri rubrica" <<
	endl << "4) data di oggi" <<
	endl << "5) esci" << endl;
	cin>>tmp; 
	scelta = atoi(tmp);
	}while(scelta < 1 || scelta > 6);

	return scelta;		
}
