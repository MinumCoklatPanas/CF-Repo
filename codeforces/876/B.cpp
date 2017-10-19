#include <bits/stdc++.h>
using namespace std;

set<int> isi[100010];
	int tab[100010];
	map<int,int> mp;

int main()
{
	int n,m,k;
	cin>>n>>k>>m;
//	memset(isi,0,sizeof(isi));
	memset(tab,0,sizeof(tab));
	mp.clear();
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		isi[a%m].insert(a);
		tab[a%m]++;
		mp[a]++;
	}
	for (int i=0;i<m;i++)
	{
		if (tab[i]>=k)
		{
			cout<<"Yes\n";
			vector<int> ans;
			ans.clear();
			for (set<int>::iterator it=isi[i].begin();it!=isi[i].end();++it)
			{
				for (int j=1;j<=mp[*it];j++)
				{
					ans.push_back(*it);
					//if (ans.size()==k) break;
				}
				//if (ans.size()==k) break;
			}
			for (int j=0;j<k;j++)
			{
				if (j==k-1)
				 cout<<ans[j]<<"\n";
				else
				 cout<<ans[j]<<" ";
			}
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}
