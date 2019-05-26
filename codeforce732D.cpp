#include "bits/stdc++.h"
using namespace std;
int arr[100005];
int prep[100005];
int last[100005];
int n,m;
bool check(int mid)
{
	for(int i=1;i<=mid;i++) last[arr[i]]=i;
	int pp=0,pass=0;
	for(int i=1;i<=mid;i++)
	{
		if(arr[i]==0 || last[arr[i]]!=i) pp++;
		else if(pp>=prep[arr[i]])
		{
			pass++;
			pp-=prep[arr[i]];
		}
	}
	if(pass==m) return 1;
	else return 0;
}
int main()
{
	//int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=1;i<=m;i++) cin >> prep[i];
	int st=1,ed=n,mid,keep;
	while(st<=ed)
	{
		mid = (st+ed)>>1;
		if(check(mid)) {keep=mid,ed=mid-1;}
		else st=mid+1;
	}
	if(st>n) cout << "-1";
	else cout << keep;
}