#include<bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define F first
#define S second

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n,0);
        for(int i=0;i<n;i++)
            p[i]=i;
    }
    int fs(int i) //findset
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j) //issameset
    {
        return (fs(i)==fs(j));
    }
    void us(int i,int j) //unionset
    {
        
        p[fs(i)]=fs(j);
    }
};
vector<pair<int,ii> > edge;
//vector<pair<int,int>> adj[n+10];
int ans[105];
bool visited[105];
void initial()
{
    for(int i=1;i<=100;i++)
    {
        ans[i]=0;
        visited[i]=false;
    }
}
int main()
{
    int n,m,q,cnt=1;
    cin >> n >> m >> q;
    while(n!=0)
    {
        UnionFind uf(n+10);
        vector<pair<int,int>> adj[n+10];
        while(m--)
        {
            int u,v,w;
            cin >> u >> v >> w;
            edge.emplace_back(w,ii(u,v));
        }
        sort(edge.begin(),edge.end());
        //int anss=0;
        for(auto op : edge)
        {
            int w = op.first;
            int u = op.second.first;
            int v = op.second.second;
            if(!uf.iss(u,v))
            {
                //anss+=w;
                adj[u].emplace_back(ii(w,v));
                adj[v].emplace_back(ii(w,u));
                uf.us(u,v);
            }
        }
        //cout << anss << "\n";
        cout << "Case #" << cnt << endl;
        cnt++;
        while(q--)
        {
            int x,y;
            cin >> x >> y;
            priority_queue<ii> pq;
            pq.emplace(ii(0,x));
            while(!pq.empty())
            {
                ii now = pq.top();
                pq.pop();
                int dist = now.first;
                int src = now.second;
                if(src==y) break;
                else if(visited[src]) continue;
                visited[src] = true;
                for(auto op : adj[src])
                {
                    int d2 = op.first;
                    int n2 = op.second;
                    if(!visited[n2])
                    {
                        ans[n2] = max(ans[src],d2);
                        pq.emplace(ans[n2],n2);
                    }
                }
            }
            if(ans[y]!=0)
            {
                cout << ans[y] << "\n";
            }
            else cout << "no path" << "\n";
            initial();
        }
        cin >> n >> m >> q;
        if(n!=0) cout << endl;
        edge.clear();
    }
}