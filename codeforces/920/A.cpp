#include <bits/stdc++.h>
using namespace std;

int tab[210];
bool vis[210];
int INF=1000;
int n;
queue< pair<int,int> > q;

void reset()
{
	for (int i=1;i<=n;i++)
	 tab[i]=INF;
	memset(vis,0,sizeof(vis));
}

void BFS()
{
	while (!q.empty())
	{
		pair<int,int> depan=q.front();
		q.pop();
		int x=depan.first;
		int step=depan.second;
//		cout<<x<<" x\n";
		vis[x]=1;
		++step;
		if (tab[x-1]>step && x>0)
		 {
		 	q.push({x-1,step});
		 	tab[x-1]=step;
		 }
		if (tab[x+1]>step && x<=n)
		 {
		 	q.push({x+1,step});
		 	tab[x+1]=step;
		 }
	}
	return;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while (t--)
	{
		int k;
		cin>>n>>k;
//		cout<<n<<" "<<k<<" nk\n";
		reset();
		for (int i=1;i<=k;i++)
		{
			int a;
			cin>>a;
			tab[a]=1;
			q.push({a,1});
		}
		BFS();
		int mx=0;
//		for (int i=1;i<=n;i++)
//		 cout<<tab[i]<<" ";
//		cout<<"\n";
		for (int i=1;i<=n;i++)
		 mx=max(mx,tab[i]);
		cout<<mx<<"\n";
	}
}
