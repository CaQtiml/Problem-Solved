#include "bits/stdc++.h"
using namespace std;
int main()
{
	string s;
	int n;
	cin >> n >> s;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]>s[i+1])
		{
			cout << "YES\n";
			cout << i+1 << " " << i+2;
			exit(0);
		}
	}
	cout << "NO";
}