#include "bits/stdc++.h"
using namespace std;
set<int> ss;
int main()
{
	int n;
	cin >> n;
	ss.insert(n);
	//int cnt=1;
	while(1)
	{

		n+=1;
		//if(ss.count(n)) break;
		//cnt++;
		while(1)
		{
			if(n%10!=0) 
			{
				//cnt++;
				break;
			}
			n=n/10;
			//cnt++;
		}
		
		
		//n+=1;
		if(ss.count(n)) break;
		//cout << n << "\n";
		ss.insert(n);
		
		//n+=1;
		//cnt++;
		//n+=1;
		//cnt++;
		//if(n==cp) break;
	}
	cout << ss.size();
}