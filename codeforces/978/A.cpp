#include <bits/stdc++.h>
using namespace std;

int pos[1010];
int tab[55];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>tab[i];
		pos[tab[i]]=max(pos[tab[i]],i);
	}
	vector<int> ans;
	for (int i=1;i<=n;i++)
	{
		if (i==pos[tab[i]])
		 ans.push_back(tab[i]);
	}
	cout<<ans.size()<<"\n";
	for (int i=0;i<ans.size();i++)
	{
		if (i==ans.size()-1)
		 cout<<ans[i]<<"\n";
		else
		 cout<<ans[i]<<" ";
	}
}
