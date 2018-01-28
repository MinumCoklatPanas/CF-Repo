#include <bits/stdc++.h>
using namespace std;

int mx=0;
int tab[5][110];
bool vis[5][110];
int n;

void dfs(int x,int y,int now)
{
	if (x>2) return;
	if (y>n) return;
	vis[x][y]=1;
	now+=tab[x][y];
//	cout<<x<<" "<<y<<" "<<now<<"\n";
	if (x==2 && y==n)
	{
//		cout<<now<<" now\n";
		mx=max(now,mx);
		return;
	}
	dfs(x,y+1,now);
	dfs(x+1,y,now);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=1;i<=2;i++)
	 for (int j=1;j<=n;j++)
	  cin>>tab[i][j];
	dfs(1,1,0);
	cout<<mx<<"\n";
}