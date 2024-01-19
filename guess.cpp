#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	srand(time(0));
	int scnumber= rand()%100+1;
	int usguess;
	int htry;
	cout<<" welcome  to the guess number game ";
	do{
		cout<<" enter your  guess number :";
		cin>> usguess;
		if( usguess>scnumber){
			cout<<" the number is too high try again ";
		}else if (usguess<scnumber){
			cout<<" too low ";
			
		}else {
			cout<<" congratulations! you guess correctly  ";
			
		}
		htry++;
		
	}
	while(usguess!=scnumber );
	cout<<"  the number of attempt you take to win the games are "<<htry;
	return 0;
}
