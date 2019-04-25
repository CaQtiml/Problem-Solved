#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int hh,mm;
    cin >> hh >> mm;
    int ans=0;
    while(1) {
        if(hh%10==7||mm%10==7)
        {
            cout << ans;
            exit(0);
        }
        ans++; 
        mm-=x;
        if(mm<0) 
        {
            mm+=60;
            hh--;
        }
        if(hh<0) hh+=24;
    }
}