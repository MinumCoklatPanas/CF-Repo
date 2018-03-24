#include <bits/stdc++.h>
using namespace std;

int n,m;
char tab[55][55];
bool sudah[55];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  cin>>tab[i][j];
	for (int i=1;i<=n;i++)
	{
		if (sudah[i]) continue;
		sudah[i]=1;
		vector<int> friends;
		for (int j=1;j<=m;j++)
		{
			if (tab[i][j]=='#')
			{
				for (int k=i+1;k<=n;k++)
				 if (tab[k][j]=='#')
				  {
				  	friends.push_back(k);
				  	sudah[k]=1;
				  }
			}
		}
		for (int j=1;j<=m;j++)
		{
			char now=tab[i][j];
			for (int k=0;k<friends.size();k++)
			{
				if (tab[friends[k]][j]!=now)
				{
//					cout<<i<<" "<<j<<" "<<k<<"\n";
					cout<<"No\n";
					return 0;
				}
			}
		}
	}
	cout<<"Yes\n";
}
