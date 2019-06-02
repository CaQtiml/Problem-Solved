#include "bits/stdc++.h"
using namespace std;
int qs[100005];
int dp[2][100005];
const int INF = 1e9+29;
int main()
{
	int n,k,p;
	cin >> n >> k >> p;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		qs[i]+=t;
		qs[i+1]=qs[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=p;j++) dp[i%2][j] = qs[j];
		for(int j=p+1;j<=n;j++)
		{
			//cout << dp[!(i%2)][j-p] << "\n";
			dp[i%2][j] = max(dp[i%2][j-1],dp[!(i%2)][j-p]+qs[j]-qs[j-p]);
			//cout << dp[i%2][j] << "\n" << "-----" << "\n";
		}
		//cout << "\n";
	}
	cout << dp[k%2][n];
}