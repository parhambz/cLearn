#include<stdio.h>

int main(){
	


	int a;
	scanf("%d",&a);

	if(a>20 || a<0)
		puts("Invalid Number.");
	else{
		if(a>=17)
			puts("A");
		else{
			if(a>=14)
				puts("B");
			else{
				if(a>=10)
					puts("D");
				else
					puts("Fail");
			}
		}
	}


	if(a>20 || a<0)
		puts("Invalid Number.");
	else if(a>=17)
		puts("A");
	else if(a>=14)
		puts("B");
	else  if(a>=10)
		puts("D");
	else
		puts("Fail");
			
	if(a!=2){
		puts("1");
		if(a==3)
			puts("d");
	}
	else
		puts("2");
		
		

	



	return 0;
	int n;
	int res=scanf("%d",&n);
	//printf("result: %d\n",res);
	if(res==0)
		puts("No input");
	else{
		printf("n is %d\n",n);
		printf("sum of 1 to n is %d\n",(1+n)*n/2);
	}
	/*int x;
	int y;
	x=152;
	y=484;
	printf("x\t+y\t=z\n%d\t+%d\t=%d\n",x,y,x+y);*/
	return 0;
	printf("Hello World!\n"  
		"didi raftam?"
		);
	return 0;
}