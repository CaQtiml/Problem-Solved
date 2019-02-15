#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define INF 10000000
vector<int> adj[300000];
int color[300000];
vector<int> aa[5];
int op[300000];
//int color[300000];
int main()
{
	int n,m;
	for(int i=0;i<=299999;i++) color[i]=INF , op[i]=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		if(op[i]==0)
		{
			int cnt=1;
			queue<int> q;
			color[i]=0;
			bool bpt=true;
			q.push(i);
			while(!q.empty()&&bpt)
			{
				int u = q.front();
				op[u] = 1;
				//aa[color[u]].push_back(u);
				q.pop();
				cnt=1;
				for(auto i : adj[u])
				{
					if(cnt==1) //preventing from adding the same number to queue "aa"
					{
						aa[color[u]].push_back(u);
						cnt++;
					}
					if(color[i]==INF)
					{
						//aa[color[u]].push_back(u);
						color[i]=1-color[u];
						q.push(i);
					}
					else if(color[i]==color[u])
					{
						//bpt=false;
						cout << "-1";
						return 0 ;
						//break;
					}
				}
			}
		}
	}
	//if(bpt)
	//{
		printf("%d\n",aa[0].size());
		for(auto i : aa[0]) printf("%d ",i);
		printf("\n");
		printf("%d\n",aa[1].size());
		for(auto i : aa[1]) printf("%d ",i);
		
	//}
	//else cout << "-1";
}

/*
The Graph can have more than one connected component (Not all the vertices might be reachable from vertex 0)
6 4
1 2
1 3
4 5
4 6
OUTPUT
4
2 3 5 6
2
1 4
*/