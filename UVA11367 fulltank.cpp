#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
#define pb emplace_back
#define mkp make_pair
#define INF 1000000000
#define f first
#define s second
int p[1005];
int dist[1005][105];
int main()
{
    int V,E;
    cin >> V >> E;
    for(int i=1;i<=V;i++) cin >> p[i-1];
    vector<vii> adj;
    adj.assign(V+10,vii());
    for(int i=1;i<=E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].emplace_back(mkp(v,w));
        adj[v].emplace_back(mkp(u,w));
    }
    int Q;
    cin >> Q;
    while(Q--){
        int ff,st,ed;
        bool chkb=false;
        cin >> ff >> st >> ed;
        for(int i=0;i<=V;i++){
            for(int j=0;j<=ff;j++){
                dist[i][j]=INF;
            }
        }
        //vi dist(V+5,INF);
        priority_queue<iii,vector<iii>,greater<iii>> pq;
        pq.emplace(mkp(0,mkp(0,st))); // (cost,(gas,src))
        dist[st][0]=0;
        while(pq.size())
        {
            int cup =pq.top().first; //cup=cost update
            int gup=pq.top().s.first; //gup=gas update
            int src=pq.top().second.s;
            if(src==ed) {cout << dist[src][gup]<<"\n"; chkb=true; break;}
            pq.pop();
            if(dist[src][gup]<cup) continue;
            if(gup<ff&&dist[src][gup+1]>cup+p[src])
            {
                dist[src][gup+1]=cup+p[src];
                pq.emplace(mkp(dist[src][gup+1],mkp(gup+1,src)));
            }
            for(auto j:adj[src]) //for(auto j:adj[src])=for(int j=0;j<adj[src].size();j++)
            {
                int sr=j.first; //sr=src update
                int gu=j.second; //gu=gas update2
                //int cu=j.s.second;
                if(gup>=gu)
                {
                    if(dist[sr][gup-gu]>cup)
                    {
                        dist[sr][gup-gu]=cup;
                        pq.emplace(mkp(dist[sr][gup-gu],mkp(gup-gu,sr)));
                    }
                }
            }
        }
        while(pq.size()) pq.pop();
        if(!chkb) cout << "impossible\n";
    }
}
