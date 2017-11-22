#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

char tab[15][15][15];
bool vis[15][15][15];
int langkah[15][15][15];
//queue<pair<pii,pii>> q;
int k,n,m;

bool between(int x,int y)
{
	return ((1<=y) && (x<=y));
}

void dfs(int x,int y,int z)
{
	if (x<1) return;
	if (x>k) return;
	if (y<1) return;
	if (y>n) return;
	if (z<1) return;
	if (z>m) return;
	if (tab[x][y][z]=='#') return;
	if (vis[x][y][z]) return;
	vis[x][y][z]=1;
	dfs(x-1,y,z);
	dfs(x+1,y,z);
	dfs(x,y-1,z);
	dfs(x,y+1,z);
	dfs(x,y,z-1);
	dfs(x,y,z+1);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>k>>n>>m;
	memset(vis,0,sizeof(vis));
	memset(langkah,0,sizeof(langkah));
	for (int i=1;i<=k;i++)
		for (int j=1;j<=n;j++)
		 for (int l=1;l<=m;l++)
		  cin>>tab[i][j][l];
	int x,y;
	cin>>x>>y;
	int ans=0;
	dfs(1,x,y);
//	for (int i=1;i<=k;i++)
//	{
//		for (int j=1;j<=n;j++)
//		 for (int l=1;l<=m;l++)
//		  cout<<tab[i][j][l];
//		cout<<"\n";
//	}
	for (int i=1;i<=k;i++) 
	 for (int j=1;j<=n;j++)
	  for (int l=1;l<=m;l++)
	   if (vis[i][j][l]) ++ans;
	cout<<ans<<"\n";
}
