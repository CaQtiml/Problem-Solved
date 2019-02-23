#include "bits/stdc++.h"
using  namespace std;
bool dp[505][505]; //dp[partial sum of chocolate's cost][chocolate's cost]
int main()
{
	int n,make;
	scanf("%d%d",&n,&make);
	dp[0][0]=1;
	while(n--)
	{
		int a;
		scanf("%d",&a);
		for(int i=make;i>=0;i--)
		{
			for(int j=make;j>=0;j--)
			{
				if(dp[i][j])
					if(j+a<=make)
					{
						dp[i][j+a]=1;
						dp[i+a][j+a]=1;
					}
			}
		}
	}
	int cnt=0;
	for(int i=0;i<=make;i++)
	{
		if(dp[i][make]) cnt++ ; 
	}
	printf("%d\n",cnt);
	for(int i=0;i<=make;i++)
	{
		if(dp[i][make]) printf("%d ",i);
	}
}
