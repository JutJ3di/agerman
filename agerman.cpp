#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>

using namespace std;
const char pass[] = "guba98ba17";

const int msize = 32;

typedef struct Elemento{

	char name[msize];
	char surname[msize];         //singolo elemento della lista possiede name,surname e ID 
	char number[10];
}elemento;

void clear(elemento rubrica[]){


	for (int i = 0; i < 10; ++i)
	{
		strcpy(rubrica[i].name,"vuoto");
		strcpy(rubrica[i].surname,"vuoto");
		strcpy(rubrica[i].number,"vuoto");
	}
}
int menurubrica(){
	char scelta[1024];

	cout<<"MENU"<<endl;
	do{
		cout<<"ciao questa e` una rubrica molto semplice"<<endl;
		cout<<"premi 1 se vuoi aggiungere elementi(max 10)"<<endl;
		cout<<"premi 2 se vuoi rimuovere elementi"<<endl;
		cout<<"premi 3 se vuoi cercare un numero"<<endl;
		cout<<"premi 4 se vuoi cercare un nome"<<endl;  
		cout<<"premi 5 se vuoi visualizzare tutta la rubrica"<<endl;
		cout<<"premi 6 se vuoi cancellare tutti gli elementi della rubrica"<<endl;
		cout<<"premi 7 se vuoi uscire"<<endl;	
		cin>>scelta;
		}while( atoi(scelta) < 1|| atoi(scelta) > 7 );


		return atoi(scelta);
}
int foundname(elemento rubrica[]){
	
	char nome[msize]="\0";
	cin>>nome;

	for(int i = 0; i < 10 ;i++)
		if(strcmp(rubrica[i].name,nome) == 0)
			return i;
	
	return -1;	
}
void removeelement(elemento rubrica[],int *pi){
	int i;
	cout<<"che elemento vuoi rimuovere: "<<endl;
	cin>>i;
	strcpy(rubrica[i].name,"vuoto");
	strcpy(rubrica[i].surname,"vuoto");
	strcpy(rubrica[i].number,"vuoto");
}
int remove(elemento rubrica[]){
	char check;
	cout<<"sei sicuro di volere eliminare ogni elemento della rubrica? (y,n)"<<endl;
	cin>>check;
	if(check == 'n')
		return -1;
	check = 'y';

	for (int i = 0; i < 10; ++i)
	{
		strcpy(rubrica[i].name,"vuoto");
		strcpy(rubrica[i].surname,"vuoto");
		strcpy(rubrica[i].number,"vuoto");
	}
	return 0;
}
int getelement(elemento rubrica[],int *pi){
		

		int i = 0;
		*pi = i;

		if(strcmp(rubrica[i].name,"vuoto") == 0)
		{
			cout<<"dimmi il"<<i<<"-esimo nome :";
			cin>>rubrica[i].name;
			cout<<"dimmi il"<<i<<"-esimo cognome :";   // se il surname e` una line tipo ("di marzio" ) dovrei usare la cin.getline()... 
			cin>>rubrica[i].surname;
			cout<<"dimmi il"<<i<<"-esimo ID :";
			cin>>rubrica[i].number;
		}	
		i++;
		if(i == 11)
			return -1;
		else{
			*pi = i;
			return 0;
		}	
}
int foundid(elemento rubrica[]){

	char num[10] = "\0";
	cout<<"che numero cerchi ? "<<endl;
	cin>>num;
	
	for (int i = 0; i < 10; ++i)
			if(strcmp(num,rubrica[i].number) == 0)
				return i;
			
	return -1;					
}
void visualizzare(elemento rubrica[]){

		cout<<"NAME  SURNAME  NUMBER"<<endl;	
		for(int i = 0; i < 10;++i)
			cout<<rubrica[i].name<<" "<<rubrica[i].surname<<" "<<rubrica[i].number<<endl;		
}
int rubrica(){

	elemento *rubrica;
	rubrica = new elemento[10];
	int i = 0 ;
	int *pi;
	pi = & i;
	clear(rubrica);
	while(1){	
		int check = menurubrica();
		switch(check){
			case 1 :getelement(rubrica,pi);
					break;
			case 2 :removeelement(rubrica,pi);
					break;
			case 3 :{
						int index = foundid(rubrica);
						if(index != -1)
							cout<<rubrica[index].number<<" questo e` il numero di "<<rubrica[index].name<<endl;
						else
							cout<<"numero non trovato"<<endl;
						break;
					}
			case 4 :{
						int index = foundname(rubrica);
						if(index != -1)
							cout<<rubrica[index].number<<" questo e` il numero di "<<rubrica[index].name<<endl;
						else
							cout<<"nome non trovato"<<endl;
						break;
					}
 			case 5 : visualizzare(rubrica);
 					break;
 			case 6 : remove(rubrica);
 					break;		
 			case 7 :return -1;
 					
 		}
 	}

 	delete [] rubrica;
	return 0;
}
void data(){
	char buffer [80];
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    strftime(buffer, 80, "Sono le %I:%M%p, del giorno %d/%m/%Y.", localTime);
    cout << buffer << endl;
}

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

int write(){

	cout<<"ok cosa vuoi scrivere"<<endl;
	char buffer[1024];
	cin.ignore();
	cin.getline(buffer,1024);
	char *wrt;
	wrt = new char [strlen(buffer) + 1];
	if(wrt == NULL){
		cout<<"out of memory"<<endl;
		return -1;
	}
	strcpy(wrt,buffer);

	ofstream write("agenda.txt",ios::app);
	write << wrt << endl;
	write.close();

	return 0;
	delete [] wrt;
}

int login(){
	
	time_t currentTime;
    time(&currentTime);
	cout<<"LOGIN"<<endl;
	char nametmp[32];
	char tmppass[32];
	cout << "Name :";
	cin >> nametmp;
	cout << "pass :";
	cin >> tmppass;
	ofstream log("log.txt",ios::app);

	if(strcmp(nametmp,"Herman") != 0 || strcmp(tmppass,pass) != 0){
		cout<<"hai sbagliato nome utente o pass (o entrambi)"<<endl;
		log << "tentativo di accesso da parte di"<<nametmp<<"\t"<<asctime(localtime(&currentTime))<<endl;
		return 0;
	}	
	else if (strcmp(nametmp,"Herman") == 0 && strcmp(tmppass,pass) == 0)
	{
		cout << "benvenuto" << endl;
		log << "tentativo di accesso eseguito,era herman\t"<<asctime(localtime(&currentTime))<<endl;
		return 1;
	}	

	log.close();
}
int read(){

  ifstream OpenFile("agenda.txt",ios::app);
  char ch;
  while(!OpenFile.eof())
  {
    OpenFile.get(ch);
    cout << ch;
  }
  OpenFile.close();
}

void workinprogress(){cout<<"lavori in corso"<<endl;}


int main(int argc, char const *argv[]){
	int  i = 1;
	while(login() == 0 && i < 4){
		if(i == 3){
			cout<<"troppi errori"<<endl;
			exit(1);
		}
			
		++i;    //login
	}
	cout<<"WELCOME :"<<endl;

		while(1){                                //ciclo menu
			switch(menu()){

				case 1:write();
						break;
				case 2:read();
						break;
				case 3:if(rubrica() == -1)
							continue;
						break;
				case 4:data();
						break;

				case 5:{		
						cout<<"sei sicuro ? (s,n)"<<endl; 
						char a;
						cin >> a;
							if(a == 's')
								exit(1);
							else
								cout<<"ok"<<endl;	 
						}					
			}
		
		}


	return 0;
}
