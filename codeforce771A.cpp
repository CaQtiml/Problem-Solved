#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int MAXX = 160000;
vector<int> edge[MAXX];
bool visit[MAXX];
//int ce,cv;
void dfs(int u , ll &ce , ll &cv)
{
	//cout << "PASS\n";
	if(visit[u]) return;
	visit[u]=true;
	cv++;
	ce += edge[u].size();
	for(auto op : edge[u])
	{
		//printf("==>%d\n",op);
		if(!visit[op])
		{
			//cout << op << ce << cv << "\n";
			//cout << "PASS/n";
			//printf("%d %d %d\n",op,ce,cv);
			dfs(op,ce,cv);
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		edge[x].emplace_back(y);
		edge[y].emplace_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!visit[i])
		{
			ll ce=0,cv=0; //ce=count_edge cv=count_vertice
			dfs(i,ce,cv);
			//printf("%d %d\n",ce,cv);
			if(ce!=(ll)cv*(cv-1)) //check clique graph (every vertice needs to pair each others.)
			{
				//cout << "PASS";
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
}