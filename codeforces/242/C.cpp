#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

map< pair<int,int>,bool > ada;
map< pair<int,int>,int > dist;

int d[3] = {-1,0,1};

void bfs(int startX,int startY,int rowNum,int colNum)
{
    queue< pair< pair<int,int>,int > > q;
    q.push({{startX,startY},0});
    dist[{startX,startY}] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int step = cur.second;
        for (int i = 0 ; i < 3 ; i++)
            for (int j = 0 ; j < 3 ; j++)
            {
                int xx = x + d[i];
                int yy = y + d[j];
                if (!dist.count({xx,yy}) && 1 <= xx && xx <= rowNum && 1 <= yy && yy <= colNum && ada.count({xx,yy}))
                {
                    dist[{xx,yy}] = step + 1;
                    q.push({{xx,yy},step + 1});
                }
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int startX,startY,endX,endY;
    cin >> startX >> startY >> endX >> endY;
    int n;
    cin >> n;
    int colNum = -INF;
    int rowNum = -INF;
    for (int i = 1 ; i <= n ; i++)
    {
        int k,l,r;
        cin >> k >> l >> r;
        colNum = max(colNum,r);
        rowNum = max(rowNum,k);
        for (int j = l ; j <= r ; j++)
            ada[{k,j}] = 1;
    }
    bfs(startX,startY,rowNum,colNum);
    if (dist.count({endX,endY}))
        cout << dist[{endX,endY}] << endl;
    else
        cout << -1 << endl;
    return 0;
}