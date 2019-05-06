#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll qs[(int)1e6+10];
int main()
{
	int n,m;
	cin >> n >> m;
	ll mn=1e18,mx=-1e18;
	for(int i=1;i<=n;i++)
	{
		ll a;
		cin >> a;
		qs[i]=qs[i-1]+a;
		if(i>=m)
		{
			mn=min(mn,qs[i-m]);
			mx=max(mx,qs[i]-mn);
		}
	}
	cout << mx;
}