#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
ii arr[500005];
bool cmp(ii a , ii b)
{
	if(a.f==b.f) return a.s<b.s;
	else return a.f<b.f;
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) /*cin >> arr[i].f >> arr[i].s;*/
	{
		// cin >> arr[i].f;
		// int t;
		// cin >> t;
		// arr[i].s=t;
		cin >> arr[i].f >> arr[i].s;
	}
	sort(arr+1,arr+1+n,cmp);
	int cnt=1;
	int temp=arr[1].s;
	ii last=arr[1];
	for(int i=2;i<=n;i++)
	{
		if(arr[i].f>temp)
		{
			temp=arr[i].s;
			cnt++;
		}
		else
		{
			temp=min(temp,arr[i].s);
		}
	}
	cout << cnt;
}