#include "bits/stdc++.h"
using namespace std;
#define ll long long
const ll mod = 909091;
ll dp[10010];
int main()
{
	int n;
	cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i-1;j++)
		{
			dp[i]+=(dp[j]*dp[i-j-1])%mod;
		}
	}
	cout << dp[n]%mod;
}