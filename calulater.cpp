#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;


int main(){
	char select;
	int num1,num2;
	cout<<" Enter operator +,-,/,* ";
	cin>>select;
	cout<<"Enter the first number ";
	cin>> num1;
	cout<<"Enter the second number ";
	cin>>num2;
	switch(select){
		case '+':
			cout<<num1<<"+"<<num2<<"="<<num1+num2;
			break;
		case '-':
			cout<<num1<<"-"<<num2<<"="<<num1-num2;
			break;
		case '*':
			cout<<num1<<"*"<<num2<<"="<<num1*num2;
			break;
		case '/':
			if(num2!=0){
			
			cout<<num1<<"/"<<num2<<"="<<num1/num2;
			break;
		}else{
			cout<<"zero denominater not should be allow ";
			
		}
		default:
			cout<<" \ninvalid  operator ";
			break;
	}
	return  0;
	
}
