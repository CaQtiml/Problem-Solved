#include "bits/stdc++.h"
using namespace std;
vector<int> v;
int main()
{
	int n,k;
	cin >> n >> k ;
	for(int i=1;i<=n;i++)
	{
		int tt;
		cin >> tt;
		v.emplace_back(tt);
	}
	for(int i=1;i<=k;i++)
	{
		int mx=-1e9,po;
		bool chk=0;
		for(int j=0;j<v.size()-1;j++)
		{
			mx=max(mx,v[j]);
			if(v[j]>v[j+1]) 
			{
				po=j;
				chk=1;
				break;
			}
		}
		if(chk) v.erase(v.begin()+po);
		else
		{
			mx=max(mx,v[v.size()-1]);
			for(int i=0;i<v.size();i++)
			{
				if(v[i]==mx) 
				{
					v.erase(v.begin()+i);
					break;
				}
			}
		}
	}
	for(auto j : v) cout << j << " ";
}