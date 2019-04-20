#include "bits/stdc++.h"
using namespace std;
int dp[205][205],dp2[205][205],arr[205][205];
int main()
{
	int h,w;
	cin >> h >> w;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cin >> arr[i][j];
		}
	}
	for(int i=h;i>=1;i--)
	{
		for(int j=1;j<=w;j++)
		{
			dp[i][j]=max(dp[i+1][j],dp[i][j-1])+arr[i][j];
		}
	}
	for(int i=h;i>=1;i--)
	{
		dp2[i][1]=dp2[i+1][1]+arr[i][1];
	}
	for(int i=1;i<=w;i++)
	{
		dp2[h][i]=dp2[h][i-1]+arr[h][i];
	}
	for(int i=h-1;i>=1;i--)
	{
		for(int j=2;j<=w;j++)
		{
			dp2[i][j]=min(dp2[i+1][j],dp2[i][j-1]) + arr[i][j];
		}
	}
	cout << dp[1][w]-dp2[1][w];
}