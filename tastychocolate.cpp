#include "bits/stdc++.h"
using namespace std;
int arr[1010];
int dp[1010][3010];
const int INF = 1e9+29;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<1010;i++)
	{
		for(int j=0;j<3010;j++)
		{
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=1;i<=n;i++)
	{
		int mn = dp[i-1][0];
		for(int j=1;j<=3000;j++)
		{
			dp[i][j]=mn;
			if(j!=arr[i]) dp[i][j]++;
			mn=min(mn,dp[i-1][j]);
		}
	}
	// for(int i=1;i<=3;i++)
	// {
	// 	//int mn = dp[i-1][0];
	// 	for(int j=0;j<=10;j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	int ans=dp[n][0];

	for(int i=1;i<=3000;i++)
	{
		ans=min(ans,dp[n][i]);
	}
	cout << ans;
}