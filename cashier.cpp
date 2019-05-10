#include "bits/stdc++.h"
using namespace std;
vector<int> v[25];
int main()
{
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		int rob;
		cin >> rob;
		for(int j=1;j<=rob;j++)
		{
			int tt;
			cin >> tt;
			v[i].emplace_back(tt);
		}
		sort(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=q;i++)
	{
		int op,num;
		cin >> op >> num;
		if(op==0 and v[num].size()>0) v[num].erase(v[num].begin());
		else if(op==1)
		{
			int pos=1e9+29;
			int cashier=1e9+29;
			for(int j=1;j<=n;j++)
			{
				int st=0,ed=v[j].size()-1;
				while(st<=ed)
				{
					int mid = (st+ed) >> 1;
					if(num<v[j][mid]) ed=mid-1;
					else st=mid+1;
				}
				if(st<pos)
				{
					pos=st;
					cashier=j;
				}
			}
			auto it = upper_bound(v[cashier].begin(),v[cashier].end(),num);
			v[cashier].insert(it,num);
			cout << cashier << "\n";
		}
	}
}