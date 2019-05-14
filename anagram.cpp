#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll expo[300];
char a[2010],b[2010];
ll qsa[2010] , qsb[2010];
const int BasePrime = 101;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a+1 >> b+1 ;
	int m = strlen(a+1);
	int n = strlen(b+1);
	//cout << m << " " << n;
	//cout << a[7] << "\n";
	expo[0]=1;
	for(int i=1;i<300;i++) expo[i]=expo[i-1]*BasePrime;
	for(int i=1;i<=m;i++)
	{
		qsa[i] = (a[i]-'A')*expo[a[i]-'A'];
		qsa[i] += qsa[i-1];
		qsb[i] = (b[i]-'A')*expo[b[i]-'A'];
		qsb[i] += qsb[i-1];
	}
	set<ll> s;
	int ans=0;
	for(int len=1;len<=min(m,n);len++)
	{
		for(int i=len;i<=m;i++)
		{
			s.insert(qsa[i]-qsa[i-len]);
		}
		for(int i=len;i<=n;i++)
		{
			if(s.find(qsb[i]-qsb[i-len]) != s.end()) ans=len;
		}
		s.clear();
	}
	cout << ans;
}