#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5e5+10;
int p , dp[MAXN];
int main()
{
	int n,c;
	cin >> n >> c;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin >> op;
		if(op==c) p++;
		else dp[op]=max(dp[op],p)+1;
		ans=max(ans,dp[op]-p);
	}
	cout << ans+p;
}