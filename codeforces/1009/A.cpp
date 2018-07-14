#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	queue<int> q;
	int tab[1010];
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	for (int i=1;i<=m;i++)
	{
		int a;
		cin>>a;
		q.push(a);
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (q.empty()) continue;
		if (tab[i]<=q.front())
		{
			++cnt;
			q.pop();
		}
	}
	cout<<cnt<<"\n";
}
