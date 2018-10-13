#include "bits/stdc++.h"
using namespace std;
int main()
{
	int a,b;
	a=5 , b=3;
	int c=5,d=3;
	int max=5;
	int op=max;
	for(int i=1;i<=max;i++){
		for(int j=1;j<=op-1;j++) printf("*");
		if(c<d){
			d--;
			printf("-/");
		}
		else if(c==d){
			c--;
			d--;
			printf("//");
		}
		else if(c>d){
			c--;
			printf("/-");
		}
		op--;
		printf("\n");
	}
}
