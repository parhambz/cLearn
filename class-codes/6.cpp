#include <stdio.h>

int read(int arr[]){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;scanf("%d",&arr[i++]));
	return n;
}

void write(int arr[],int n){
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	putchar('\n');
}

const int maxSize=100;

int filterodd1(int arr[],int n){
	int temp[maxSize];
	int nt=0;
	for(int i=0;i<n;i++)
		if(arr[i]%2==0)
			temp[nt++]=arr[i];
	for(int i=0;i<nt;i++)
		arr[i]=temp[i];
	return nt;
}

void rem(int arr[],int n,int index){
	for(int i=index;i<n-1;i++)
		arr[i]=arr[i+1];
}

int filterodd2(int arr[],int n){
	for(int i=n-1;i>=0;i--){
		if(arr[i]%2==1){
			rem(arr,n,i);
			n--;
		}
	}
	return n;
}

int filterodd(int arr[],int n){
	int w=0;
	for(int r=0;r<n;r++)
		if(arr[r]%2==0)
			arr[w++]=arr[r];
	return w;
}

int filterRep(int arr[],int n){
	int w=1;
	for(int r=1;r<n;r++){
		if(arr[r]!=arr[r-1])
			arr[w++]=arr[r];
	}
	return w;
}

void sep1(int arr[],int n){
	int w=0;
	for(int r=0;r<n;r++)
		if(arr[r]%2==0)
		{
			int t=arr[w];
			arr[w++]=arr[r];
			arr[r]=t;
		}
}

void sep(int arr[],int n){
	int i=0;
	int j=n-1;
	while(i<=j){
		if(arr[i]%2==0){
			i++;continue;
		}
		if(arr[j]%2==1){
			j--;
			continue;
		}
		int t=arr[i];
		arr[i]=arr[j];
		arr[j]=t;
	}
}

int main(){
	int arr[]={1,2,8,6,9};
	int n=5;
	//n=read(arr);
	//n=filterodd(arr,n);
	//n=filterRep(arr,n);
	sep(arr,n);
	write(arr,n);
	return 0;
}