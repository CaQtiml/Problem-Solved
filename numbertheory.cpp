#include "bits/stdc++.h"
using namespace std;
const int MAX = 1e6+5;
#define ll long long
int arr[MAX],ar2[MAX],cmp[MAX],seglen[15],skip[15];
bool chk[15][MAX];
//vector<int> vec[15];
void rabinkarp(int n,int m,int seg)
{
	//for(int i=1;i<=m;i++) cout << cmp[i] << " ";
	//cout << "\n";
	ll del=1,x1=0,x2=0;
	for(int i=1;i<=m;i++)
	{
		del*=53;
		x1=x1*53+arr[i];
		x2=x2*53+cmp[i];
	}
	if(x1==x2)
	{
		chk[seg][1]=1;
		//for(int i=1;i<=m;i++) chk[seg][i]=1;
	}
	for(int i=m+1;i<=n;i++)
	{
		x1=x1*53+arr[i]-arr[i-m]*del;
		if(x1==x2)
		{
			//cout << "P\n";
			chk[seg][i-m+1]=1;
			//for(int j=i-m+1;j<=i;j++) chk[seg][j]=1;
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int onecnt=0;
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=1;i<=m;i++) {cin >> ar2[i];if(ar2[i]==1)onecnt++;}
	//scanf("%s%s",arr+1,ar2+1);
	int op2=1;
	int pt=1;
	int seg=1;
	int lent=0;

	while(pt<=m)
	{
		int inp=0;
		while(ar2[pt]!=1 && pt<=m)
		{
			inp++;
			cmp[inp] = ar2[pt];
			pt++;
		}
		rabinkarp(n,inp,seg);
		seglen[op2]=inp;
		op2++;
		//seg++;
		while(ar2[pt]==1 && pt<=m)
		{
			pt++;
			lent++;
		}
		//if(pt==m)
		skip[seg]=lent;
		lent=0;
		seg++;
	}
	
	// for(int i=1;i<=n;i++)
	// {
	// 	cout << chk[1][i] << " ";
	// }
	// cout << "\n";

	// for(int i=1;i<=n;i++)
	// {
	// 	cout << chk[2][i] << " ";
	// }
	// cout << "\n";
	
	seg--;
	//for(int i=1;i<=seg;i++) cout << skip[i] << "\n";
	// cout << seg << "\n" ;

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bool chkb=1;
		int pos=i;
		for(int j=1;j<=seg;j++)
		{
			//cout << pos << "\n";
			if(!chk[j][pos] || pos+seglen[j]+skip[j]-1>n) //don't forget "-1"
			{
				chkb=0;
				break;
			}
			pos+=(skip[j]+seglen[j]);
		}
		//for(int j=1;j<=seg;j++)
		if(chkb) {/*cout << "+\n";*/ans++;}
		//cout << "\n";
	}
	cout << ans;
}

// 5 5
// 2 3 2 3 2
// 2 1 1 1 1
// OUT : 1

// 15 3
// 97 97 97 97 97 97 97 97 97 97 97 97 97 97 97
// 1 97 1
// OUT : 13

