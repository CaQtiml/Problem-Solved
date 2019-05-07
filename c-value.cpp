#include "bits/stdc++.h"
using namespace std;
const int sz=1e6+10;
int arr[sz];
int dp[sz][5];
int a=-1;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2;j++)
		{
			if(j==0) dp[i][j]=dp[i-1][j]+arr[i]*a;
			else if(j==1) dp[i][j]=min(dp[i-1][j]-arr[i]*a , dp[i-1][j-1]+arr[i]*a);
			else dp[i][j]=min(min(dp[i-1][j]+arr[i]*a , dp[i-1][j-1]-arr[i]*a),dp[i-1][j-2]+arr[i]*a);
		}
		a=-a;
	}
	cout << min(min(dp[n][0],dp[n][1]),dp[n][2]);
}