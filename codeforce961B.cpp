#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n+10];
	int t[n+10];
	memset(t,0,sizeof(t));
	int res=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i]==1)
		{
			res+=a[i];
			a[i]=0;
		}
	}
	int maxx=-1;
	for(int i=1;i+k-1<=n;i++)
	{
		int sum=0;
		for(int j=i;j<=i+k-1;j++)
		{
			sum+=a[j];
		}
		maxx=max(maxx,res+sum);
	}
	printf("%d",maxx);
}