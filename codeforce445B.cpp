#include "bits/stdc++.h"
using namespace std;
#define ll long long
int p[100];
int fs(int i)
{
	return (p[i]==i) ? i : (p[i]=fs(p[i]));
}
void us(int u , int v)
{
	p[fs(u)]=fs(v);
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<100;i++) p[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		us(x,y);
	}
	ll ans = 1LL << n ; //1<<n = expo(2,n);
	for(int i=1;i<=n;i++)
	{
		if(p[i]==i) ans/=2;
	}
	cout << ans;
}