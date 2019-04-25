#include "bits/stdc++.h"
using namespace std;
//int ch[100010];
//int key[100010];
int evenc=0,oddc=0,evenk=0,oddk=0;
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) 
	{
		int a;
		cin >> a;
		if(a&1) oddc++;
		else evenc++;
	}
	for(int i=1;i<=m;i++)
	{
		int a;
		cin >> a;
		if(a&1) oddk++;
		else evenk++;
	}
	//cout << oddc << evenc << oddk << evenk;
	//int ans=0;
	cout << min(evenk,oddc) + min(evenc,oddk);
}