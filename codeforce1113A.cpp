#include "bits/stdc++.h"
using namespace std;
//int dp[200][200];
int main()
{
	int n,v,cost=0;
	scanf("%d%d",&n,&v);
	if(n-1<=v) {cout << n-1; return 0;}
	cost=v;
	//int vop=v;
	for(int i=2;i<=n;i++)
	{
		v--;
		if(v<n-1-(i-1))
		{
			v++;
			cost+=i;
		}
	}
	cout << cost;
}