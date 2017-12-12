#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<int,int> frek;
	frek.clear();
	int n;
	cin>>n;
	int tab[5010];
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	frek[tab[i]]++;
	 }
	int ans=-1;
	for (int i=1;i<=n;i++)
	 ans=max(ans,frek[tab[i]]);
	cout<<ans<<"\n";
}
