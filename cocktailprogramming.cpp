#include "bits/stdc++.h"
using namespace std;
long long dp[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,mx=-1;
	cin >> N;
	long long cnt=0;
	for(int i=1;i<=N;i++)
	{
		int tt;
		cin >> tt;
		mx=max(mx,tt);
		dp[tt]++;
		//cin >> dp[i];
	}
	int tg;
	cin >> tg;
	//cout << mx << "\n";
	for(int i=mx;i>=0;i--)
	{
		int diff = tg-i;
		if(tg-i<0) continue;
		if(diff>i) break;
		if(i!=diff)
		{
			cnt+=dp[diff]*dp[i];
		}
		else
		{
			cnt+=((dp[i]*(dp[i]-1))/2);
		}
	}
	cout << cnt;
}