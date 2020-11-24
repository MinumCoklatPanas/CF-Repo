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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long

int dist[1010];

int queryDist(int k)
{
    cout << 1 << " " << 1 << " " << 2 << " " << k << endl; 
    int ret;
    cin >> ret;
    return ret;
}

int queryDir(int x, int k)
{
    cout << 2 << " " << 1 << " " << x << " " << k << endl;
    int ret;
    cin >> ret;
    return ret;
}

bool cmp(int a, int b)
{
    return (dist[a] < dist[b]);
}

vector<int> fix(vector<int> point, int dir)
{
    int mx = -INFF;
    int ix = -1;
    for (auto it : point) if (dist[it] > mx)
    {
        mx = dist[it];
        ix = it;
    }
    vector<int> far,near;
    for (auto it : point) if (it != ix)
    {
        if (queryDir(ix,it) == dir)
            near.push_back(it);
        else
            far.push_back(it);
    }
    sort(near.begin(), near.end(), cmp);
    sort(far.begin(), far.end(), cmp);
    reverse(far.begin(), far.end());
    vector<int> ret;
    for (auto it : near)
        ret.push_back(it);
    ret.push_back(ix);
    for (auto it : far)
        ret.push_back(it);
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 3 ; i <= n ; i++)
        dist[i] = queryDist(i);
    vector<int> cw,ccw;
    for (int i = 3 ; i <= n ; i++)
    {
        int dir = queryDir(2, i);
        if (dir == 1)
            ccw.push_back(i);
        else
            cw.push_back(i);
    }
    if (ccw.size() > 0)
        ccw = fix(ccw, 1);
    if (cw.size() > 0)
        cw = fix(cw, -1);
    cout << 0 << " 1 ";
    for (auto it : cw)
        cout << it << " ";
    cout << "2 ";
    reverse(ccw.begin(), ccw.end());
    for (auto it : ccw)
        cout << it << " ";
    cout << endl;
    return 0;
}