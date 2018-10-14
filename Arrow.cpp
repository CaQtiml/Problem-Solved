#include "bits/stdc++.h"
using namespace std;
int main()
{
	int a,b,max;
	scanf("%d%d",&a,&b);
	int c=a , d=b ;
	if(a>b) max=a;
	else max=b;
	int op=max;
	for(int i=1;i<=max;i++){
		for(int j=1;j<=op-1;j++) printf(" ");
		if(c<d){
			d--;
			printf(" /");
		}
		else if(c==d){
			c--;
			d--;
			printf("//");
		}
		else if(c>d){
			c--;
			printf("/ ");
		}
		op--;
		printf("\n");
	}
	c=0 , d=0;
	for(int i=1;i<=max;i++)
	{
		for(int j=1;j<i;j++) printf(" ");
		if(c<d){
			printf(" \\");
		}
		else if(c==d){
			printf("\\\\");
		}
		else if(c>d){
			printf("\\ ");
		}
		if(c<a-1) c++;
		if(d<b-1) d++;
		printf("\n");
	}
}
