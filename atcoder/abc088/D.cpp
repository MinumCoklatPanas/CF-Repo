#include <bits/stdc++.h>
using namespace std;

char tab[55][55];
bool vis[55][55];
queue< pair< pair<int,int>,int > > q;
int dist[55][55];
int n,m;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

void bfs()
{
	memset(dist,-1,sizeof(dist));
	q.push({{1,1},1});
	while (!q.empty())
	{
		pair< pair<int,int>,int > depan=q.front();
		q.pop();
		int x=depan.first.first;
		int y=depan.first.second;
		vis[x][y]=1;
		int step=depan.second;
		for (int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if (1<=xx && xx<=n && 1<=yy && yy<=m && !vis[xx][yy] && tab[xx][yy]=='.')
			{
				q.push({{xx,yy},step+1});
				dist[xx][yy]=step+1;
				vis[xx][yy]=1;
			}
		}
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int hitam=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	cin>>tab[i][j];
	 	hitam+=(tab[i][j]=='#');
	 }
	bfs();
	if (dist[n][m]==-1)
	 cout<<-1<<"\n";
	else
	 {
	 	int ans=n*m-dist[n][m]-hitam;
	 	cout<<ans<<"\n";
	 }
}