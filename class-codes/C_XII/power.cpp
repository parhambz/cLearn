#include<stdio.h>

int pow0(int m,int n){
	int t=1;
	for(int i=0;i<n;i++)
		t=(t*m)%97;
	return t;
}



int pow(int m,int n){
	int t=1;
	while(n){
		if(n&1)
			t=(t*m)%97;
		m=(m*m)%97;
		n>>=1;
	}
	return t;
}

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	printf("%d\n",pow(m,n));
	printf("%d\n",pow0(m,n));
	return 0;
}