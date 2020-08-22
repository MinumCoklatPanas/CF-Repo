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

bool tab[1010][1010];
int dist[1010][1010];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1 ; i <= 1000 ; i++)
        for (int j = 1 ; j <= 1000 ; j++)
            dist[i][j] = INF;
    string s;
    cin >> s;
    int curX = 100;
    int curY = 100;
    for (int i = 0 ; i < s.length() ; i++)
    {
        // cout << curX << " " << curY << endl;
        tab[curX][curY] = 1;
        if (s[i] == 'L')
            --curX;
        if (s[i] == 'R')
            ++curX;
        if (s[i] == 'U')
            --curY;
        if (s[i] == 'D')
            ++curY;
    }
    // cout << curX << " " << curY << endl;
    tab[curX][curY] = 1;
    queue< pair< pair<int,int>,int > > q;
    q.push({{100,100},0});
    dist[100][100] = 0;
    for (int tmp = 1 ; tmp <= 1000000 && !q.empty() ; tmp++)
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int step = cur.second;
        // cout << x << " " << y << " " << step << endl;
        for (int i = 0 ; i < 4 ; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (tab[xx][yy] && dist[xx][yy] > step + 1)
            {
                dist[xx][yy] = step + 1;
                q.push({{xx,yy},step + 1});
            }
        }
    }
    // cout << dist[curX][curY] << endl;
    if (dist[curX][curY] == s.length())
        cout << "OK\n";
    else
        cout << "BUG\n";
    return 0;
}