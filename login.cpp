#include<iostream>
#include<fstream>

const char pass[] = "guba98ba17";

int login(){
	
	cout<<"LOGIN"<<endl;
	char nametmp[32];
	char tmppass[32];
	cout << "Name :";
	cin >> nametmp;
	cout << "pass :";
	cin >> tmppass;
	ofstream log("log.txt");

	if(strcmp(nametmp,"Herman") != 0 || strcmp(tmppass,pass) != 0){
		cout<<"hai sbagliato nome utente o pass (o entrambi)"<<endl;
		log << "tentativo di accesso"<<endl;
		return 0;
	}	
	else if (strcmp(nametmp,"Herman") == 0 && strcmp(tmppass,pass) == 0)
	{
		cout << "benvenuto" << endl;
		log << "tentativo di accesso eseguito,era herman"<<endl;
		return 1;
	}	

	log.close();
}