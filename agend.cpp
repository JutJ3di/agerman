#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


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

	delete [] wrt;
	return 0;

}

