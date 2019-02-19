#include "bits/stdc++.h"
using namespace std;
const int N = 1e7+10;
#define ll long long
const int mod = 1e9+7;
ll dp[2][N];
int main()
{
	int n;
	cin >> n;
	dp[1][0]=1;
	for(int i=1;i<=n;i++) //i=#step
	{
		dp[0][i]=(2LL*dp[0][i-1]+dp[1][i-1])%mod;
		dp[1][i]=(3LL*dp[0][i-1])%mod;
	}
	cout << dp[1][n];
}
