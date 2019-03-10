#include "bits/stdc++.h"
using namespace std;
int a[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n ;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,greater<int>());
	int maxx=a[1];
	int cmp=0;
	int cnt=0;
	int temp;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==maxx) cnt++;
		else if(a[i]<a[i-1])
		{
			temp=a[i];
			cmp=0;
			cmp++;
		}
		else if(a[i]==temp)
		{
			cmp++;
			if(cmp>cnt) cnt++;
		}
	}
	cout << cnt;
	//for(int i=1;i<=n;i++) cout << a[i];
}