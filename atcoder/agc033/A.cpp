#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

char tab[1010][1010];
int dist[1010][1010];
int n,m;
queue< pair< pair<int,int>,int > > q;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void bfs()
{
	while (!q.empty())
	{
		pair< pair<int,int>,int > depan = q.front();
		q.pop();
		int x = depan.first.first;
		int y = depan.first.second;
		int step = depan.second;
		// cout << x << " " << y << " " << step << endl;
		for (int i = 0 ; i < 4 ; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			// cout << xx << " " << yy << endl;
			if (1 <= xx && xx <= n && 1 <= yy && yy <= m && dist[xx][yy] == -1)
			{
				dist[xx][yy] = step + 1;
				q.push(make_pair(make_pair(xx,yy),dist[xx][yy]));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dist,-1,sizeof(dist));
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
		{
			cin >> tab[i][j];
			if (tab[i][j] == '#')
			{
				q.push(make_pair(make_pair(i,j),0));
				dist[i][j] = 0;
			}
		}
	bfs();
	int ans = 0;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
			ans = max(ans,dist[i][j]);
	cout << ans << endl;
}