#include "bits/stdc++.h"
using namespace std;
char dp[10];
int day[10];
int main()
{
	dp[1]=dp[2]=dp[5]='F';
	dp[3]=dp[7]='R';
	dp[4]=dp[6]='C';
	int fi,ra,ch;
	cin >> fi >> ra >> ch;
	int mnday=1e9;
	int typemn;
	int t1,t2,t3;
	for(int i=1;i<=3;i++)
	{
		if(i==1)
		{
			// int tmp=fi/3;
			// mnday=min(mnday,tmp);
			// fi/=3;
			t1=fi/3;
		}
		if(i==2)
		{
			// int tmp=ra/2;
			// mnday=min(mnday,tmp);
			// ra%=2;
			t2=ra/2;
		}
		if(i==3)
		{
			// int tmp=ra/2;
			// mnday=min(mnday,tmp);
			// ra%=2;
			t3=ch/2;
		}
	}
	mnday=min(t1,min(t2,t3));
	int ans = mnday*7;
	//int sur=0;
	fi-=(mnday*3);
	ra-=(mnday*2);
	ch-=(mnday*2); 
	if(fi>3) fi=3;
	if(ra>2) ra=2;
	if(ch>2) ch=2;
	int mx=-1;
	for(int i=1;i<=7;i++)
	{
		int tmp=0;
		int fi2=fi;
		int ra2=ra;
		int ch2=ch;
		for(int j=i;j<=i+7;j++)
		{
			if(j==1||j==8||j==2||j==9||j==5||j==12)
			{
				if(fi2>0)
				{
					fi2--;
					tmp++;
				}
				else break;	
			}
			if(j==3||j==10||j==7||j==14)
			{
				if(ra2>0)
				{
					ra2--;
					tmp++;
				}
				else break;	
			}
			if(j==4||j==11||j==6||j==13)
			{
				if(ch2>0)
				{
					ch2--;
					tmp++;
				}
				else break;	
			}
		}
		mx=max(mx,tmp);
	}
	cout << ans+mx;
}