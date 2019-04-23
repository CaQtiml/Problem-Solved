#include "bits/stdc++.h"
using namespace std;
vector<int> v;
int arr[100010];
int main()
{
	int n;
	cin >> n;
	int cnt=0;
	int now=0;
	v.push_back(-1);
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		//cout << now << "\n";
		if(i==1)
		{
			now=arr[i];
			cnt++;
			continue;
		}
		if(arr[i]!=now)
		{
			//cout << cnt << "\n";
			v.emplace_back(cnt);
			now=arr[i];
			cnt=0;
			cnt++;
			continue;
		}
		if(arr[i]==now)
		{
			cnt++;
			continue;
		}
	}
	v.emplace_back(cnt);
	// for(auto op : v)
	// {
	// 	cout << op << "\n";
	// }
	int ans=0;
	for(int i=1;i<v.size()-1;i++)
	{
		if(v[i]>v[i+1])
		{
			ans=max(ans,v[i+1]);
		}
		else if(v[i]==v[i+1])
		{
			ans=max(ans,v[i]);
		}
		else if(v[i]<v[i+1])
		{
			ans=max(ans,v[i]);
		}
	}
	cout<<ans*2;
}