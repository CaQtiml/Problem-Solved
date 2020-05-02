#include "bits/stdc++.h"
using namespace std;
typedef map<string,string> vi;


int main()
{

    int T;
    cin >> T;
    while(T--)
    {
        int op;
        cin >> op;
        map<string,string> par;
        map<string,int> cnt;
        while(op--)
        {
            string x,y;
            cin >> x >> y;
            if(cnt.find(x)==cnt.end())
            {
                cnt[x]++;
                par[x] = x;
            }
            if(cnt.find(y)==cnt.end())
            {
                cnt[y]++;
                par[y] = y;
            }
            
            string root_x,root_y,i;

            i=x;
            while(i!=par[par[i]])
            {
                par[i] = par[par[i]];
                i = par[par[i]];
            }
            root_x = i;

            i=y;
            while(i!=par[par[i]])
            {
                par[i] = par[par[i]];
                i = par[par[i]];
            }
            root_y = i;

            if(root_y!=root_x)
            {
                cnt[root_x]+=cnt[root_y];
                printf("%d\n", cnt[root_x]);
                par[root_y] = root_x;
            }
            else printf("%d\n", cnt[root_x]);
        }
    }
}
