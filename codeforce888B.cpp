#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n;
	string g;
	scanf("%d",&n);
	cin >> g;
	int x=0;
	int y=0;
	for(int i=0;i<n;i++)
	{
		if(g[i]=='U') x++;
		if(g[i]=='D') x--;
		if(g[i]=='L') y--;
		if(g[i]=='R') y++;
	}
	int val = abs(x)+abs(y);
	cout << n-val;
}