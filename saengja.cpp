#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int sz=1e5+10;
const ll INF = 1e18;
#define f first
#define s second
#define ii pair<int,int>
ll X[sz],C[sz],dp[sz];
ii db[sz];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> db[i].first >> db[i].second;
	}
	sort(db+1,db+n+1);
	for(int i=1;i<=n;i++)
	{
		X[i]=db[i].first;
		C[i]=db[i].second;
	}
	deque<int> q;
	for(int i=1;i<=n;i++)
	{
		while(!q.empty() && X[i]-X[q.front()]>k) q.pop_front();
		ll best = q.empty() ? -INF : X[q.front()]+C[q.front()]+dp[q.front()-1];
		dp[i]=max(dp[i-1],C[i]-X[i]+best);
		ll toadd = C[i]+X[i]+dp[i-1];
		while(!q.empty() && toadd >= X[q.back()]+C[q.back()]+dp[q.back()-1]) q.pop_back();
		q.emplace_back(i);
	}
	cout << dp[n];
}