#include<iostream>
#include<ctime>
using namespace std;

void data(){
	char buffer [80];
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    strftime(buffer, 80, "Sono le %I:%M%p, del giorno %d/%m/%Y.", localTime);
    cout << buffer << endl;
}
