#include "bits/stdc++.h"
using namespace std;
#define ll long long 
const int sz=3e5+10;
ll x[sz],p[sz],g[sz];
ll gcd(ll a,ll b)
{
	if(b%a==0) return a;
	else return gcd(b%a,a);
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> x[i];
	for(int i=1;i<=m;i++) cin >> p[i];
	for(int i=1;i<n;i++)
	{
		g[i]=x[i+1]-x[i];
	}
	ll gd=g[1];
	// for(int i=1;i<n;i++)
	// {
	// 	cout << g[i] << "\n";
	// }
	for(int i=2;i<n;i++)
	{
		//cout << gd << " " << g[i] << "\n";
		gd=gcd(gd,g[i]);
	}
	//cout << gd;
	for(int i=1;i<=m;i++)
	{
		if(gd%p[i]==0)
		{
			cout << "YES\n" << x[1] << " " << i ;
			exit(0);
		}
	}
	cout << "NO";
}