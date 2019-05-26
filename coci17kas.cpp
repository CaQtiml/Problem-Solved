#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9+29;
int arr[505];
int dp[505][100005];
int sum=0;
int n;

int main()
{
	//int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		sum+=arr[i];
	}
	//memset(dp,-1,sizeof(dp));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int diff=0;diff<=sum;diff++)
		{
			if(dp[i-1][diff]!=INF)
			{
				dp[i][diff] = min(dp[i][diff],arr[i]+dp[i-1][diff]);
				dp[i][diff+arr[i]] = min(dp[i-1][diff],dp[i][diff+arr[i]]);
				dp[i][abs(diff-arr[i])] = min(dp[i-1][diff],dp[i][abs(diff-arr[i])]);
			}
		}
	}
	int leftover = dp[n][0];
	//cout << leftover;
	sum-=leftover;
	sum/=2;
	sum+=leftover;
	cout << sum;
}

