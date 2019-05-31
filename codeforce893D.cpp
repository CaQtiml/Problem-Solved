#include "bits/stdc++.h"
using namespace std;
int main()
{
	int n,d,x;
	cin>>n>>d; 
	int tk=0,mx=0;
	int ans=0;
	while(n--)
	{
		cin>>x;
		if (x!=0)
		{
			tk+=x,mx+=x;
			if (tk>d) 
			{
				cout<<"-1"; exit(0);
			}
			mx=min(mx,d);
		}
		else
		{
			if (mx>=0) tk=max(tk,0);
			else ans++,tk=0,mx=d;
		}
	}
	cout<<ans;
}