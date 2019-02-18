#include "bits/stdc++.h"
using namespace std;
const int N = 200000 ;
vector<int> g[N];
int color[N];
bool ok;
int nowcolor;
void dfs(int u , int par)
{
    //printf("%d %d\n",color[u],nowcolor);
    if(color[u]!=nowcolor) 
    {
        
        //printf("PASS\n");
        ok=false;

    }
    for(auto v : g[u])
    {
        if(v!=par)
        {
            //printf("PASS2\n");
            dfs(v,u);
        }
    }
    //printf("========>%d\n",ok);
}
bool solve(int u)
{
    //bool ans = true;
    for(auto v : g[u])
    {
        nowcolor=color[v];
        //printf("==>%d\n",nowcolor);
        ok = true ;
        dfs(v,u);
        if(!ok) return ok;
    }
    //return ans;
}
int main()
{
    int n;
    cin >> n ;
    for(int i=1;i<=n-1;i++)
    {
        int x , y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    for(int i=1;i<=n;i++) cin >> color[i];
    int r1=-1 , r2=-1;
    for(int i=1;i<=n;i++)
    {
        for(auto op : g[i])
        {
            if(color[op]!=color[i])
            {
                r1=op;
                r2=i;
            }
        }
    }
   //printf("===>%d %d\n",r1,r2);
    if(r1==-1)
    {
        cout << "YES\n1";
        return 0;
    }
    bool c1=solve(r1);
    //cout << c1 <<"\n";
    //printf("BREAK\n");
    bool c2=solve(r2);
    //cout << c2 <<"\n";
    if(c1)
    {
        cout << "YES\n" << r1;
    }
    else if(c2)
    {
        cout << "YES\n" << r2;
    }
    else cout << "NO";
}