#include "bits/stdc++.h"
using namespace std;
int cn[5010];
int ac[5010];
//vector<int> cw,ar,both,none,mix;
vector<int> aa,bb,cc,dd;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		char temp;
		cin >> temp;
		if(temp=='0') cn[i]=0;
		else cn[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		char temp;
		cin >> temp;
		if(temp=='0') ac[i]=0;
		else ac[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(cn[i]==0 && ac[i]==0) aa.emplace_back(i);
		if(cn[i]==0 && ac[i]==1) bb.emplace_back(i);
		if(cn[i]==1 && ac[i]==0) cc.emplace_back(i);
		if(cn[i]==1 && ac[i]==1) dd.emplace_back(i);
	}
	int na=aa.size();
	int nb=bb.size();
	int nc=cc.size();
	int nd=dd.size();
	int alpha=n/2;
	int beta=nb+nd;
	int a,b,c,d;
	bool chk=0,chk2=0;
	for(int i=0;i<=nd;i++)
	{
		for(int j=0;j<=na;j++)
		{
			if(i-j==beta-alpha)
			{
				d=i;
				a=j;
				chk2=0;
				for(int i=0;i<=nb;i++)
				{
					for(int j=0;j<=nc;j++)
					{
						if(i+j==(alpha-a-d))
						{
							b=i;
							c=j;
							if(a>aa.size() || b>bb.size() || c>cc.size() || d>dd.size())
							{
								chk2=1;
								break;
							}
							else
							{
								if(a>0)
								{
									for(int i=0;i<a;i++)
									{
										cout << aa[i] << " ";
									}
								}
								if(b>0)
								{
									for(int i=0;i<b;i++)
									{
										cout << bb[i] << " ";
									}
								}
								if(c>0)
								{
									for(int i=0;i<c;i++)
									{
										cout << cc[i] << " ";
									}
								}
								if(d>0)
								{
									for(int i=0;i<d;i++)
									{
										cout << dd[i] << " ";
									}
								}
								exit(0);
							}
							
						}
					}
					if(chk2) break;
				}
			}
		}
		//if(chk) break;
	}
	cout << "-1";
}