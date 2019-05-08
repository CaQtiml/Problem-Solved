#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll arr[100005];
int main()
{
	int n;
	cin >> n;
	ll gd;
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=1;i<=n;i++)
	{
		if(i==1) gd=arr[i];
		else
		{
			gd=__gcd(gd,arr[i]);
		}
	}
	ll sum=0;
	//cout << gd;
	for(int i=1;i<=n;i++)
	{
		sum+=arr[i]/gd;
	}
	cout << sum;
}