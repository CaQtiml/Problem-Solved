#include "bits/stdc++.h"
using namespace std;
int arr[800000];
vector<int> vec2,vec;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		//vec2.emplace_back(arr[i]);
	}
	//sort(vec2.begin(),vec2.end());
	sort(arr+1,arr+1+n);
	int now=0;
	for(int i=1;i<=n;i++)
	{
		vec.emplace_back(now+(arr[i]-arr[i-1]-1));
		now+=arr[i]-arr[i-1]-1;
	}
	//for(auto op : vec) cout << op << "\n";
	for(int i=1;i<=k;i++)
	{
		int a;
		cin >> a;
		int pos = lower_bound(vec.begin(),vec.end(),a)-vec.begin();
		cout << pos+a << " ";
	}
}