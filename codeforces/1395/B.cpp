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

bool ada[110][110];

bool valid(vector< pair<int,int> > &vis,int n,int m)
{
    if (vis.size() != n * m) return false;
    for (auto it : vis)
    {
        if (ada[it.first][it.second]) 
        {
            // cout << "yo\n";
            return false;
        }
        ada[it.first][it.second] = 1;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("output.txt","w",stdout);
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    int curX = x;
    int curY = y;
    vector< pair<int,int> > vis;
    // cout << curX << " " << curY << endl;
    // vis.emplace_back(curX,curY);
    for (int i = x ; i >= 1 ; i--)
    {
        //ke kanan
        int tmpX = 1,tmpY = 1;
        cout << i << " " << curY << endl;
        vis.emplace_back(i,curY);
        for (int j = m ; j > curY ; j--)
        {
            cout << i << " " << j << endl;
            vis.emplace_back(i,j);
            tmpX = i;
            tmpY = j;
        }
        //ke kiri
        for (int j = 1 ; j < curY ; j++)
        {
            // cout << "yo\n";
            cout << i << " " << j << endl;
            vis.emplace_back(i,j);
            tmpX = i;
            tmpY = j;
        }        
        curX = tmpX;
        curY = tmpY;
        // cout << curX << " " << curY << endl;
    }
    // cout << x + 1 << " " << curY << endl;
    curX = x + 1;
    for (int i = x + 1 ; i <= n ; i++)
    {
        int tmpX = 1,tmpY = 1;
        cout << i << " " << curY << endl;
        vis.emplace_back(i,curY);
        for (int j = m ; j > curY ; j--)
        {
            cout << i << " " << j << endl;
            vis.emplace_back(i,j);
            tmpX = i;
            tmpY = j;
        }
        //ke kiri
        for (int j = 1 ; j < curY ; j++)
        {
            cout << i << " " << j << endl;
            vis.emplace_back(i,j);
            tmpX = i;
            tmpY = j;
        }        
        curX = tmpX;
        curY = tmpY;
    }
    // cout << vis.size() << endl;
    // if (!valid(vis,n,m))
    //     cout << "FAILED\n";
    // else
    //     cout << "SUCCESS\n";
    // for (auto it : vis)
    // {
    //     ada[it.first][it.second] = 1;
    // }
    // for (int i = 1 ; i <= n ; i++)
    //     for (int j = 1 ; j <= m ; j++) if (!ada[i][j])
    //         cout << i << " " << j << endl;       
    return 0;
}