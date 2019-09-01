#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

typedef pair<int,int> pii;
char tab[2010][2010];
bool bisa[2010][2010];
bool vis[2010][2010];
int x,y,n,m,b,k;

int bfs(int row,int col)
{
	deque< pair< int,pii > > q;
	q.push_front(make_pair(0,make_pair(row,col)));
	int ret = 0;
	while (!q.empty())
	{
		pair< int,pii > depan = q.front();
		q.pop_front();
		int r = depan.second.first;
		int c = depan.second.second;
        if (vis[r][c]) continue;
        ++ret;
        vis[r][c] = 1;
		// cout << r << " " << c << endl;
		int step = depan.first;
        if (r > 1 && tab[r - 1][c] != '*')
        {
            q.push_front(make_pair(step,make_pair(r - 1,c)));
        }
        if (r < n && tab[r + 1][c] != '*')
        {
            q.push_front(make_pair(step,make_pair(r + 1,c)));
        }
        if (c > 1 && tab[r][c - 1] != '*' && step < x)
        {
            q.push_back(make_pair(step + 1,make_pair(r,c - 1)));
        }
        if (c < m && tab[r][c + 1] != '*' && c - col + step < y)
        {
            q.push_front(make_pair(step,(make_pair(r,c + 1))));
        }
	}
    return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> b >> k >> x >> y;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
		{
			cin >> tab[i][j];
		}
	int ans = bfs(b,k);
    cout << ans << endl;
}