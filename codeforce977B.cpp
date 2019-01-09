#include "bits/stdc++.h"
using namespace std;
map<int,string> t;
#define ll long long
string a;
int n;
int rabinkarp(string sub)
{
	int cnt=0;
	ll del=1,x1=0,x2=0;
	for(int i=0;i<2;i++)
	{
		del*=53;
		x1=x1*53+a[i];
		x2=x2*53+sub[i];
	}
	if(x1==x2) cnt++;
	for(int i=2;i<n;i++)
	{
		x1=x1*53+a[i]-a[i-2]*del;
		if(x1==x2) cnt++;
	}
	return cnt;
}
int main()
{
	scanf("%d",&n);
	cin >> a;
	int maxx=-100000;
	for(int i=0;i<n-1;i++)
	{
		string temp = a.substr(i,2);
		//cout << temp << "\n";
		int tmp = rabinkarp(temp);
		t[tmp] = temp;
		maxx=max(maxx,tmp);
	}
	cout << t[maxx];
}