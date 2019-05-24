#include "bits/stdc++.h"
using namespace std;
int arr[120];
int main()
{
	int n;
	cin >> n;
	int rob;
	cin >> rob;
	int now=n;
	for(int i=1;i<=rob;i++)
	{
		int op;
		cin >> op;
		if(now-op>=0)
		{
			now-=op;
			now+=n;
		}
		else
		{
			cout << now;
			exit(0);
		}
	}
	cout << now;
}