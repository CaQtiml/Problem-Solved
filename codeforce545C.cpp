#include "bits/stdc++.h"
using namespace std;
//const int MAXN = 1e9;
int main()
{
	//printf("PASS0\n");
	int n;
	scanf("%d",&n);
	int c[100010];
	int h[100010];
	//printf("PASS1\n");
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&h[i]);
	int fwd=0 , cnt=0 ;
	//printf("PASS2");
	for(int i=1;i<=n;i++)
	{
		if(i==1||i==n) { cnt++; fwd=c[i]; continue; }
		if(c[i]-fwd>h[i])
		{
			cnt++;
			fwd=c[i];
			//printf("==>%d\n",fwd);
			continue;
		}
		if(c[i+1]-c[i]>h[i])
		{
			cnt++;
			fwd=c[i]+h[i];
			//printf("==>%d\n",fwd);
			continue;
		}
		fwd=c[i];
	}
	printf("%d",cnt);
}