#include "bits/stdc++.h"
#include "ricehub.h"
using namespace std;
#define ll long long
int a[100010];
ll qs[100010];
bool price(int st , int ed , ll budget)
{
	int mid = (st+ed)>>1;
	ll temp = a[mid]*((mid-st)-(ed-mid)) - qs[mid-1] + qs[st-1] + qs[ed] - qs[mid];
	//temp+=(qs[ed]-qs[mid-1])-1ll*a[mid]*(ed-mid+1);
	if(temp<=budget) return 1;
	else return 0;
}
int besthub(int n , int L , int X[] , ll budget)
{
	for(int i=1;i<=n;i++) 
	{
		a[i]=X[i-1];
		qs[i]=qs[i-1]+a[i];
	}
	int mx=-1;
	int save;
	for(int i=1;i<=n;i++)
	{
		int st=i;
		int ed=n;
		while(st<=ed)
		{
			int mid = (st+ed)>>1;
			if(price(i,mid,budget)) {save=mid; st=mid+1;}
			else ed=mid-1;
		}
		mx=max(mx,save-i+1);
	}
	return mx;
}
// int main()
// {
// 	int r , lim ,x[100010];
// 	ll bud;
// 	cin >> r >> lim >> bud ;
// 	for(int i=0;i<r;i++)
// 	{
// 		cin >>x[i];
// 	}
// 	//cin >> bud;
// 	cout << besthub(r,lim,x,bud);
// }