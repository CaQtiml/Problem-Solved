#include "bits/stdc++.h"
using namespace std;
vector<int> ans;
int main()
{
	int n;
	cin >> n;
	int copy=n;
	//int rob=40;
	for(int i=0;i<=40;i++)
	{
		for(int j=0;j<=20;j++)
		{
			if((1<<j)-1==n)
			{
				cout << i << "\n";
				for(auto op : ans) cout << op << " ";
				return 0;
			}
		}
		if(i&1) n++;
		else
		{
			for(int j=19;j>=0;j--)
			{
				if(((1<<j)&n)==0)
				{
					n^=(1<<(j+1))-1;
					ans.emplace_back(j+1);
					break;
				}
			}
		}
	}
}