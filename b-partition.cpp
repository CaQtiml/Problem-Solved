#include "bits/stdc++.h"
using namespace std;
int n,m;
int arr[1010];
int qs[1010];
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		qs[i]=qs[i-1]+arr[i];
	}
	int st=0,ed=3e9;
	while(st<=ed)
	{
		int cnt=1;
		int sum=0;
		int mid=(st+ed)>>1;
		int del=0;
		for(int i=1;i<=n;i++)
		{
			if(arr[i]>mid) cnt=1e9;
			if(qs[i]-del>mid)
			{
				cnt++;
				del=qs[i-1];
			}
		}
		if(cnt>m) st=mid+1;
		else ed=mid-1;
	}
	cout << st;
}