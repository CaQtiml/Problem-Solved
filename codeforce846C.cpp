#include "bits/stdc++.h"
using namespace std;
#define ll long long
const ll INF = 2e18 ;
ll arr[6000];
ll qs[6000];
ll Sqs(int i , int j)
{
	return qs[i]-qs[j];
}
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) 
	{
		cin >> arr[i];
		qs[i]=qs[i-1]+arr[i];
	}
	int idx1=-1 , idx2=-1 , idx3=-1;
	int t1=-1,t2=-1,t3=-1;
	ll mx=-INF;
	for(int i=0;i<=n;i++)
	{
		ll mx1=-INF;
		for(int j=0;j<=i;j++)
		{
			if(Sqs(j,0)-Sqs(i,j)>=mx1)
			{
				t1=j;
				t2=i;
				mx1=Sqs(j,0)-Sqs(i,j);
			}
		}
		ll mx2=-INF;
		for(int j=i;j<=n;j++)
		{
			if(Sqs(j,i)-Sqs(n,j)>=mx2)
			{
				t3=j;
				t2=i;
				mx2=Sqs(j,i)-Sqs(n,j);
			}
		}
		//cout << mx1 << " " << mx2 << "\n";
		if(mx1+mx2>=mx)
		{
			idx1=t1;
			idx2=t2;
			idx3=t3;
			mx = mx1+mx2;
		}
	}
	cout << idx1 << " " << idx2 << " " << idx3 ;
}