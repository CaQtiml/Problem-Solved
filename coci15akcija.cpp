#include "bits/stdc++.h"
using namespace std;
int arr[(int)1e5+10];
long long sum;
int main()
{
	int n;
	cin >> n;
	int rob = n/3;
	for(int i=1;i<=n;i++) 
	{
		cin >> arr[i];
		sum+=arr[i];
	}
	sort(arr+1,arr+1+n);
	long long ans=0;
	for(int i=n-2;i>=1;i-=3)
	{
		ans+=arr[i];
		//cout << ans << "\n";
	}
	//for(int i=(3*rob+1);i<=n;i++) ans+=arr[i];
	cout << sum-ans;
}