#include <stdio.h>

double accounts[2][50];

void open(double amount){
	int i;
	for(i=0; i<50; i++){
		if(!accounts[0][i]){
			accounts[0][i] = 1;
			accounts[1][i] = amount;
			printf("the account number is: %d\n",(i+901));
			break;
		}
	}
	if(i==50){
		printf("there are 50 accounts allready open\n");
	}
	
}

void bank(int an){
	if(accounts[0][an] ==1){
		printf("the amount in this account is: %.2lf\n",accounts[1][an]);
	}
	else{
		printf("this account isn't open\n");
	}
}

void deposit(int an, double amount){
	if(accounts[0][an] ==1){
		accounts[1][an] += amount;
		printf("the new amount in this account is: %.2lf\n",accounts[1][an]);
	}
	else{
		printf("this account isn't open\n");
	}
}

void withdraw(int an, double amount){
	if(accounts[0][an] ==1){
		if(accounts[1][an]-amount<0)
			printf("not enough credit in this account\n");
		else{
			accounts[1][an] -= amount;
			printf("the new amount in this account is: %.2lf\n",accounts[1][an]);
		}
	}
	else{
		printf("this account isn't open\n");
	}
}

void close(int an){
	if(accounts[0][an] ==0){
		printf("this account is allready close\n");
	}
	else{
		accounts[0][an] = 0;
	}
}

void interest(int ir){
	for(int i=0; i<50; i++){
		if(accounts[0][i] == 1)
			accounts[1][i]+= (accounts[1][i]*ir)/100;
	}
}

void print(){
	for(int i=0; i<50; i++){
		if(accounts[0][i] == 1)
			printf("account: %d amount: %.2lf | ",(i + 901),accounts[1][i]);
	}
	printf("\n");
}

void end(){
	for(int i=0; i<50; i++){
		accounts[0][i] = 0;
	}
}
