#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define MULTI_TC 1

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}

void bfs(string s)
{
    map<string,int> vis;
    vis[s] = 0;
    queue<string> q;
    q.push(s);
    while (!q.empty())
    {
        string u = q.front();
        q.pop();
        int cnt = 0;
        for (int i = 0 ; i < u.length() ; i++) cnt += (u[i] != s[i]);
        cerr << u << " " << vis[u] << " " << cnt << endl;
        for (int i = 0 ; i < u.length() ; i++) if (u[i] == '1')
        {
            string tmp = u;
            for (int j = 0 ; j < u.length() ; j++) if (j != i)
            {
                if (tmp[j] == '1')
                    tmp[j] = '0';
                else
                    tmp[j] = '1';
            }
            if (!vis.count(tmp))
            {
                vis[tmp] = vis[u] + 1;
                q.push(tmp);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nyala = 0,mati = 0;
    for (int i = 0 ; i < n ; i++)
    {
        nyala += (s[i] == '1');
        mati += (s[i] == '0');
    }
    string t;
    cin >> t;
    int x = 0,y = 0;
    for (int i = 0 ; i < n ; i++)
    {
        x += (t[i] == '1');
        y += (t[i] == '0');
    }
    int diff = 0;
    for (int i = 0 ; i < n ; i++) diff += (s[i] != t[i]);
    if ((x == nyala && y == mati) || (x == mati + 1 && y == nyala - 1))
    {
        if (nyala == mati + 1)
        {
            int firstStep = n - 1;
            int ans = min(firstStep - diff + 1,diff);
            cout << ans << endl;
        }
        else
        if (x == nyala && y == mati)
        {
            cout << diff << endl;
        }
        else
        if (x == mati + 1 && y == nyala - 1)
        {
            //langkah ganjil
            int firstStep = n - 1;
            int ans = firstStep - diff + 1;
            cout << ans << endl;
        }
    }
    else
        cout << -1 << endl;
    // bfs(s);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}