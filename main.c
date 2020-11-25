#include <stdio.h>
#include "myBank.h"

int main(){
	char c;
	int an , i;
	double amount;
	
	printf("Transaction type?: ");
	scanf(" %c",&c);
	while(c!='O' && c!='B' && c!='D' && c!='W' && c!='C' && c!='I' && c!='P' && c!='E'){
		printf("Wrong input\n");
		printf("Transaction type?: ");
		scanf(" %c",&c);
	}
	while(c != 'E'){
		if(c == 'O'){
			printf("Initial deposit?: ");
			scanf(" %lf",&amount);
			open(amount);
		}
		
		if(c == 'B'){
			printf("Account number?: ");
			scanf(" %d",&an);
			an -= 901;
			if(an > -1 && an <50)
				bank(an);
			else printf("illegal account number\n");
		}
		
		if(c == 'D'){
			printf("Account number?: ");
			scanf(" %d",&an);
			an-= 901;
			if(an > -1 && an <50){
				printf("amount?: ");
				scanf(" %lf",&amount);
				deposit(an, amount);			
			}
			else printf("illegal account number\n");
		}
		
		if(c == 'W'){
			printf("Account number?: ");
			scanf(" %d",&an);
			an-= 901;
			if(an > -1 && an <50){
				printf("amount?: ");
				scanf(" %lf",&amount);
				withdraw(an, amount);	
			}
			else printf("illegal account number\n");
		}
		
		if(c == 'C'){
			printf("Account number?: ");
			scanf(" %d",&an);
			an-= 901;
			if(an > -1 && an <50){	
				close(an);
			}
			else printf("illegal account number\n");
		}
		
		if(c == 'I'){
			printf("Interest rate?: ");
			scanf(" %d",&i);
			interest(i);
		}
		
		if(c == 'P'){
			print();
		}

		printf("Transaction type?: ");
		scanf(" %c",&c);
		while(c!='O' && c!='B' && c!='D' && c!='W' && c!='C' && c!='I' && c!='P' && c!='E'){
			printf("Wrong input\n");
			printf("Transaction type?: ");
			scanf(" %c",&c);
		}
	}
	end();

	return 0;
}
