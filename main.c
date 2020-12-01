#include <stdio.h>
#include "myBank.h"
void printManu();
void printManu(){
	printf("Please choose a transaction type:\n\
 O-Open Account\n\
 B-Balance Inquiry\n\
 D-Deposit\n\
 W-Withdrawal\n\
 C-Close Account\n\
 I-Interest\n\
 P-Print\n\
 E-Exit\n");
}

int main(){
	char c;
	int an , i;
	double amount;
	
	printManu();
	scanf(" %c",&c);
	while(c!='O' && c!='B' && c!='D' && c!='W' && c!='C' && c!='I' && c!='P' && c!='E'){
		printf("Wrong input\n");
		printManu();
		scanf(" %c",&c);
	}
	while(c != 'E'){
		if(c == 'O'){
			printf("Please enter amount for deposit: ");
			if(scanf(" %lf",&amount) == 0){
				printf("Faild to read the amount\n");
			}
			else{
				open(amount);
			}
		}
		
		if(c == 'B'){
			printf("Please enter Account number: ");
			if(scanf(" %d",&an) == 0){
				printf("Falid to read the account number\n");
			}
			else{
				an -= 901;
				if(an > -1 && an <50)
					bank(an);
				else printf("illegal account number\n");
			}
		}
		
		if(c == 'D'){
			printf("Please enter Account number: ");
			if(scanf(" %d",&an) == 0){
				printf("Falid to read the account number\n");
			}
			else{
				an-= 901;
				if(an > -1 && an <50){
					printf("amount?: ");
					scanf(" %lf",&amount);
					deposit(an, amount);			
				}
				else printf("illegal account number\n");
			}
		}
		
		if(c == 'W'){
			printf("Please enter account number: ");
			if(scanf(" %d",&an) == 0){
				printf("Falid to read the account number\n");
			}
			else{
				an-= 901;
				if(an > -1 && an <50){
					printf("Please enter the amount to withdraw: ");
					scanf(" %lf",&amount);
					withdraw(an, amount);	
				}
				else printf("illegal account number\n");
			}
		}
		
		if(c == 'C'){
			printf("Please enter Account number: ");
			if(scanf(" %d",&an) == 0){
				printf("Falid to read the account number\n");
			}
			else{
				an-= 901;
				if(an > -1 && an <50){	
					close(an);
				}
				else printf("illegal account number\n");
			}
		}
		
		if(c == 'I'){
			printf("Please enter interest rate: ");
			if(scanf(" %d",&i) == 0){
				printf("Faild to read the interest rate\n");
			}
			else{
				interest(i);
			}
		}
		
		if(c == 'P'){
			print();
		}

		printManu();
		scanf(" %c",&c);
		while(c!='O' && c!='B' && c!='D' && c!='W' && c!='C' && c!='I' && c!='P' && c!='E'){
			printf("Invalid transaction type\n");
			printManu();
			scanf(" %c",&c);
		}
	}
	end();

	return 0;
}
