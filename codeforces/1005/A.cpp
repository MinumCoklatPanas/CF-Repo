#include <bits/stdc++.h>
using namespace std;

int tab[1010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	vector<int> ans;
	for (int i=1;i<=n;i++)
	{
		if (tab[i]==1 && i!=1)
		 ans.push_back(tab[i-1]);
	}
	ans.push_back(tab[n]);
	cout<<ans.size()<<"\n";
	for (int i=0;i<ans.size();i++)
	{
		if (i==ans.size()-1)
		 cout<<ans[i]<<"\n";
		else
		 cout<<ans[i]<<" ";
	}
}