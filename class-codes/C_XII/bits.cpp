#include<stdio.h>
#include <stdlib.h>
unsigned char lights=0;

void print(){
	system("cls");
	unsigned char l=1<<7;
	for(int i=0;i<8;i++){
		int t=lights & l;
		printf(t?"on\t":"off\t");
		l>>=1;
	}
	printf("\n");
}

char menu(){
	printf("What do you want to do?\n");
	printf("Set(S)\n");
	
	printf("Unset(U)\n");
	printf("Toggle(T)\n");
	printf("Exit(else)\n");
	return getchar();
}

int valid(int t){
	return t>=0 && t<8;
}

int getL(){
	int n;
	scanf("%d",&n);
	unsigned char l=0;
	for(int i=0;i<n;i++){
		puts("Enter the no of light:");
		int t;
		scanf("%d",&t);
		if(!valid(t)){
			puts("Its not valid");
			i--;
			continue;
		}
		l|=(1<<t);
	}
	return l;
}

void set(){
	puts("No of lights for set: ");
	int l=getL();
	lights|=l;
}

void unset(){
	puts("No of lights for unset: ");
	int l=getL();
	lights&= ~l;
}

void toggle(){
	puts("No of lights for toggle: ");
	int l=getL();
	lights^= l;
	
}


int main(){
	while(1){
		print();
		char option=menu();
		switch(option){
		case 's':
		case 'S':
			set();
			break;
		case 'u':
		case 'U':
			unset();
			break;
		case 't':
		case 'T':
			toggle();
			break;
		default:
			return 0;
		}
	}
	return 0;
}