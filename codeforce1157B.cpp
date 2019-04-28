#include "bits/stdc++.h"
using namespace std;
map<char,int> mp;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(char i='1';i<='9';i++) 
    {
        int a;
        cin >> a;
        mp[i]=a+48;
    }
    for(int i=0;i<n;i++) 
    {
        if( mp[s[i]]<=s[i] ) continue;
        else 
        {
            while(i<n && mp[s[i]]>=s[i]) 
            {
                s[i]=mp[s[i]];
                i++;
            }
            break;
        }
    }
    cout << s;
}