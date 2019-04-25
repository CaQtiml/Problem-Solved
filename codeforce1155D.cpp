#include "bits/stdc++.h"
#define ll long long
using namespace std;
ll dp[5];
int main()
{
	ll n,x;
	cin >> n >> x;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll op;
		cin >> op;
		dp[1]=max(0LL,dp[1]+op);
		dp[2]=max(dp[1],dp[2]+op*x);
		dp[3]=max(dp[2],dp[3]+op);
		ans=max(ans,dp[3]);
	}
	cout<<ans;
}