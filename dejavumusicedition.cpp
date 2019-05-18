#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define INF 1e9+29
int tree[200005];
int lis[200005];
vector<int> pos[200005];
int main()
{
	int n,ans=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> tree[i];
	}
	//memset(lis,-1,sizeof lis);
	for(int i=0;i<200005;i++) lis[i]=-INF;
	for(int i=1;i<=n;i++){
		int f=1;
		int l=n;
		while(f<=l){ //f=first l=last
			int m=(f+l)/2;
			if( lis[m]==-INF || ( lis[m]!=-INF && tree[i]<lis[m]) ) 
			{
				l=m-1;
			}
			else f=m+1;
		}
		lis[f]=tree[i];
		ans=max(ans,f);
		pos[f].emplace_back(tree[i]);
	}
	//cout << ans;
	ll sum=0;
	int start=ans;
	int now=pos[start].front();
	//sum+=tree[now];
	sum+=now;
	start--;
	while(start>0)
	{
		for(int i=0;i<pos[start].size();i++)
		{
			//if(tree[pos[start][i]]<=tree[now])
			if(pos[start][i]<=now)
			{
				now=pos[start][i];
				break;
			}
		}
		//sum+=tree[now];
		sum+=now;
		start--;
	}
	cout << ans << " " << sum;
}