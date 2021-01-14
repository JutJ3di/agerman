#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
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
int menu(){
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
int main(int argc, char const *argv[]){

	elemento *rubrica;
	rubrica = new elemento[10];
	int i = 0 ;
	int *pi;
	pi = & i;
	clear(rubrica);
	while(1){	
		int check = menu();
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
 			case 7 :exit(1);
 		}
 	}

 	delete [] rubrica;
	return 0;
}