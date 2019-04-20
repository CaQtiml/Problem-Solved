#include "bits/stdc++.h"
using namespace std;
int dp[105];
int ck[105];
//int cnt;
int main()
{
	int n;
	cin >> n ;
	for(int i=1;i<=n;i++) cin >> dp[i];
	sort(dp+1,dp+1+n);
	int cnt=0;
	int kk=1;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]!=dp[i-1])
		{
			cnt++;
			ck[kk++]=dp[i];
		}
	}
	//for(int i=1;i<=3;i++) cout << ck[i] << "\n";
	//cout << cnt << "\n";
	if(cnt==1) {cout << "0";exit(0);}
	if(cnt>3) {cout << "-1";exit(0);}
	kk--;
	int d=0;
	for(int i=2;i<=kk;i++)
	{
		if(i==2)
		{
			d=ck[i]-ck[i-1];
		}
		else
		{
			if(d!=ck[i]-ck[i-1]) {cout << "-1";exit(0);}
		}
	}
	//if(kk==1) {cout << "0";exit(0);}
	if(kk==2)
	{
		if((ck[2]-ck[1])%2==0) {cout << (ck[2]-ck[1])/2; exit(0);}
		int diff=ck[2]-ck[1];
		if(ck[1]+diff==ck[2] || ck[2]+diff==ck[1]) {cout << ck[2]-ck[1];exit(0);}
		if((ck[2]-ck[1])%2!=0) {cout << "-1";exit(0);}
	}
	if(kk==3)
	{
		cout << ck[2]-ck[1];
	}
}