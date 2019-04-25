#include "bits/stdc++.h"
using namespace std;
int arr[15];
int main()
{
	int n,eight=0,any=0;
	bool pass=false;
	int cnt=0;
	cin >> n;
	for(int i=1;i<=n-10;i++)
	{
		char temp;
		cin >> temp;
		//if(temp!='8' && !pass) {cnt++;continue;}
		if(temp=='8' && !pass) {eight++;continue;}
	}
	//cout <<eight;
	if(eight-((n-11)/2)>=1) cout << "YES";
	else cout << "NO";
	//cout << cnt << " " << eight << "\n";
	
}