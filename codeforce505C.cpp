#include "bits/stdc++.h"
using namespace std;
const int N = 30010;
int dp[N*3][500];
int g[N];
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	//cout << "PASS" ;
	for(int i=1;i<=n;i++)
	{
		int dd;
		scanf("%d",&dd);
		g[dd]++;
	}
	//cout << "PASS";
	for(int i=30000;i>=d;i--)
	{
		for(int j=-245;j<=245;j++)
		{
			dp[i][j+245] = g[i] + max(dp[i+d+j+1][j+1+245],dp[i+d+j][245+j]);
			if(d+j>1) dp[i][j+245] = max(dp[i][j+245],g[i]+dp[i+d+j-1][j-1+245]);
		}
	}
	cout << dp[d][245];
}
