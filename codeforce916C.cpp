#include "bits/stdc++.h"
using namespace std;
const int prime = 100271;
const int INF =1e8;
int main()
{
	int n,m;
	cin >> n >> m;
	cout << prime << " " << prime << "\n";
	cout << "1 2 " << prime-(n-2) << "\n";
	for(int i=1;i<n-1;i++)
	{
		cout << i+1 << " " << i+2 << " 1\n";
	}
	int f=1,la=f+2;
	for(int i=1;i<=m-(n-1);i++)
	{
		cout << f << " " << la << " " << INF << "\n";
		la++;
		if(la>n)
		{
			f++;
			la=f+2;
		}
	}
}