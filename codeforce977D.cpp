#include "bits/stdc++.h"
using namespace std;
#define ll long long
map<int,set<ll>> mp;
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		ll op,now;
		cin >> op;
		now=op;
		ll cnt=0;
		while(now%3==0)
		{
			now/=3;
			cnt++;
		}
		mp[cnt].insert(op);
	}
	for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
		for(auto x : it->second) printf("%lld ", x);
	}
}