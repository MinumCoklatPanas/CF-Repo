#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> children[1010];
	bool leaf[1010];
	memset(children,0,sizeof(children));
	memset(leaf,0,sizeof(leaf));
	for (int i=1;i<n;i++)
	{
		int a;
		cin>>a;
		children[a].push_back(i+1);
	}
	for (int i=1;i<=n;i++)
	 if (children[i].size()==0) leaf[i]=1;
//	for (int i=1;i<=n;i++)
//	 cout<<leaf[i]<<" ";
//	cout<<"\n";
	for (int i=1;i<=n;i++)
	{
		int anak=0;
		if (children[i].size()==0) continue;
		for (int j=0;j<children[i].size();j++)
		{
			if (leaf[children[i][j]]) ++anak;
		}
//		cout<<anak<<"\n";
		if (anak<3)
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
}
