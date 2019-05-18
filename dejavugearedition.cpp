#include<bits/stdc++.h>
using namespace std;
int a[100005];
vector<int> pos[100005];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int len=0;
    vector<int> lis;
    for(int i=1;i<=n;i++) {
        auto po=upper_bound(lis.begin(),lis.end(),a[i]);
        auto po2=po-lis.begin()+1;
        if(po==lis.end()) {
            lis.emplace_back(a[i]);
            len++;
            po2=len;
        }
        else *po=a[i];
        pos[po2].emplace_back(i);
    }
    long long sum=0;
    int start=len,now=pos[start].front();
    sum+=a[now],start--;
    while(start>0) {
        for(int j=0;j<pos[start].size();j++)
            if(a[pos[start][j]]<=a[now]) { now=pos[start][j]; break;}
        sum+=a[now];
        start--;
    }
    printf("%d %lld",len,sum);
}
//gear