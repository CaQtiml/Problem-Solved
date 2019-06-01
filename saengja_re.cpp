#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int sz = 1e5+10;
const ll INF = 1e18;
#define ii pair<int,int>
#define pli pair<ll,int>
#define f first
#define s second
ll X[sz],C[sz],dp[sz];
ii db[sz];
int main()
{
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> db[i].f >> db[i].s;
	}
	sort(db+1,db+1+n);
	for(int i=1;i<=n;i++)
	{
		X[i] = db[i].f;
		C[i] = db[i].s;
	}
	priority_queue<pli> pq; //<toadd,pos>
	for(int i=1;i<=n;i++)
	{
		while(!pq.empty() and X[i]-X[pq.top().s]>k) pq.pop();
		ll best = pq.empty() ? -INF : X[pq.top().s]+C[pq.top().s]+dp[pq.top().s-1];
		dp[i]=max(dp[i-1],C[i]-X[i]+best); // dp[i]=C[i]-X[i]+best will give the wrong answer.
		ll toadd = X[i]+C[i]+dp[i-1];
		pq.emplace(toadd,i);
	}
	cout << dp[n] ;
}