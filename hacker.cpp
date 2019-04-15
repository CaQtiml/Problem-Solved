#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
int arr[1000010];
ii cmp[1000010]; //<skill,company>
//int ans[1000010];
map<int,int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	// int mn=-1e9;
	// int ans2=-1e9;
	for(int op=1;op<=n;op++)
	{
		for(int i=1;i<=m;i++) cin >> arr[i];
		sort(arr+1,arr+m+1);
		for(int i=1;i<=m;i++)
		{
			if(arr[i]>cmp[i].f)
			{
				cmp[i].f=arr[i];
				cmp[i].s=op;
			}
			if(op==n)
			{
				ans[cmp[i].s]++;
			}
		}
	}
	int mn=-1e9;
	int ans2=1e9;
	for(auto op : ans)
	{
		//cout << op.f << " " << op.s << "\n";
		if(op.s>mn && op.s>0)
		{
			mn=op.s;
			ans2=op.f;
		}
	}
	cout << ans2;
}