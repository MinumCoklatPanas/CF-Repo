#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	int now=0;
	int n,s;
	cin>>n>>s;
	pair<int,int> tab[110];
	for (int i=1;i<=n;i++)
	{
		cin>>tab[i].first>>tab[i].second;
	}
	tab[n+1].first=10000;
	tab[n+1].second=10000;
	tab[0].first=0;
	tab[0].second=0;
	int ans=-1;
	for (int i=0;i<=n;i++)
	{
		int menit=60*tab[i].first+tab[i].second;
		int anss;
		if (i)
		 anss=menit+1+s;
		else
		 anss=menit; 
		if (i)
		 menit+=2+s+s;
		else
		 menit+=s+1;
		int menit2=60*tab[i+1].first+tab[i+1].second;
		if (menit<=menit2)
		{
			ans=anss;
			break;
		}
	}
	assert(ans!=-1);
	cout<<ans/60<<" "<<ans%60<<"\n";
}
