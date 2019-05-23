#include "bits/stdc++.h"
using namespace std;
int arr[(int)1e6+10];
int ans=0;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int op;
		cin >> op;
		if(!arr[op+1]) ans++;
		else arr[op+1]--;
		arr[op]++;
	}
	cout << ans;
}