#include <bits/stdc++.h>
using namespace std;

int cei(int x,int y)
{
	float f=(float)x/y;
	int e=x/y;
//	if (e==f && e!=0)
//	 return e;
	return e+1; 
}

int main()
{
	int n;
	cin>>n;
	pair<int,int> tab[1010];
	for (int i=1;i<=n;i++)
	 cin>>tab[i].first>>tab[i].second;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
//		cout<<i<<" i\n";
		if (tab[i].first>ans)
		 ans=tab[i].first;
		else
		 {
			ans=tab[i].first+cei(ans-tab[i].first,tab[i].second)*tab[i].second;
		 }
//		cout<<ans<<"\n";
	}
	cout<<ans<<"\n";
}
