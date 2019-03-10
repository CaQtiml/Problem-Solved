#include "bits/stdc++.h"
using namespace std;
char chk[10];
char inp[100010];
//int a[7];
int main()
{
	scanf("%s",inp);
	int len = strlen(inp);
	chk[1]='c';
	chk[2]='o';
	chk[3]='d';
	chk[4]='e';
	chk[5]='c';
	chk[6]='u';
	chk[7]='b';
	chk[8]='e';
	int ans=0;
	for(int i=0;i<len;)
	{
		for(int j=1;j<=8;j++)
		{
			if(inp[i]!=chk[j]) ans++;
			else i++;
		}
	}
	printf("%d",ans);
}