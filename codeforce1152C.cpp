#include "bits/stdc++.h"
using namespace std;
#define ll long long
//vector<ll> div;
int main()
{
	ll a,b;
	cin >> a >> b;
	ll diff = abs(a-b);
	vector<ll> div;
	if(diff==0) 
	{
		cout << "0";
		exit(0);
	}
	ll mlcm=1e18 , ans=0;
	for(ll i=1;i*i<=diff;i++)
	{
		if(diff%i) continue;
		div.emplace_back(i);
		if(diff/i!=i) div.emplace_back(diff/i);
	}
	for(auto op : div)
	{
		if(b%op==a%op)
		{
			ll r = b%op;
			if(r>0) r=op-r;
			ll lcm = (a+r)*(b+r) / op;
			if(lcm<mlcm)
			{
				mlcm=lcm;
				ans=r;
			}
		}
	}
	cout << ans;
}